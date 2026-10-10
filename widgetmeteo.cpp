#include "widgetmeteo.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QString>
#include <QTimer>
#include <QVBoxLayout>

WidgetMeteo::WidgetMeteo(QWidget *parent): QWidget{parent}
{
    this->degres = 0;
    this->labelMeteo = new QLabel(this);
    this->labelDescription = new QLabel(this);
    this->iconeMeteo = new QLabel(this);
    this->reseau = new QNetworkAccessManager(this);

    connect(this->reseau, &QNetworkAccessManager::finished, this, &WidgetMeteo::reponseRecue);

    demanderMeteo();

    QTimer *minuteur = new QTimer(this);
    connect(minuteur, &QTimer::timeout, this, &WidgetMeteo::demanderMeteo);
    minuteur->start(15 * 60 * 1000);

    QHBoxLayout *layoutMeteoH = new QHBoxLayout(this);
    QVBoxLayout *layoutMeteoV = new QVBoxLayout();

    layoutMeteoV->addWidget(this->labelMeteo);
    layoutMeteoV->addWidget(this->labelDescription);

    layoutMeteoH->addWidget(this->iconeMeteo);
    layoutMeteoH->addLayout(layoutMeteoV);
    layoutMeteoH->addStretch();

    layoutMeteoV->setContentsMargins(0, 0, 0, 0);
    layoutMeteoH->setContentsMargins(5, 0, 5, 0);
    layoutMeteoH->setSpacing(8);
}

void WidgetMeteo::reponseRecue(QNetworkReply *reponse)
{
    if (reponse->error() != QNetworkReply::NoError) {
        labelDescription->setText("Hors ligne");
        reponse->deleteLater();
        return;
    }
    QJsonDocument document = QJsonDocument::fromJson(reponse->readAll());
    QJsonObject meteoActuelle = document.object().value("current").toObject();
    double temperature = meteoActuelle.value("temperature_2m").toDouble();
    int codeMeteo = meteoActuelle.value("weather_code").toInt();

    this->degres = qRound(temperature);
    this->labelMeteo->setText(QString::number(this->degres) + "°C");
    this->labelDescription->setText(descriptionDepuisCode(codeMeteo));
    this->iconeMeteo->setText(iconeDepuisCode(codeMeteo));

    reponse->deleteLater();
}

QString WidgetMeteo::descriptionDepuisCode(int code)
{
    if (code == 0) {
        return "Ciel dégagé";
    }
    if (code == 1 || code == 2) {
        return "Peu Nuageux";
    }
    if (code == 3) {
        return "Nuageux";
    }
    if (code >= 45 && code <= 48) {
        return "Brouillard";
    }
    if (code >= 51 && code <= 57) {
        return "Pluvieux";
    }
    if ((code >= 61 && code <= 67) || (code >= 80 && code <= 82)) {
        return "Pluie";
    }
    if ((code >= 71 && code <= 77) || (code >= 85 && code <= 86)) {
        return "Neige";
    }
    if (code >= 95 && code <= 99) {
        return "Orage";
    }
    return "Inconnu";
}

QString WidgetMeteo::iconeDepuisCode(int code)
{
    if (code == 0) {
        return "☀️";
    }
    if (code == 1 || code == 2) {
        return "🌤️";
    }
    if (code == 3) {
        return "☁️";
    }
    if (code >= 45 && code <= 48) {
        return "🌫️";
    }
    if (code >= 51 && code <= 57) {
        return "🌦️";
    }
    if ((code >= 61 && code <= 67) || (code >= 80 && code <= 82)) {
        return "🌧️";
    }
    if ((code >= 71 && code <= 77) || (code >= 85 && code <= 86)) {
        return "❄️";
    }
    if (code >= 95 && code <= 99) {
        return "⛈️";
    }
    return "Inconnu";
}

void WidgetMeteo::demanderMeteo()
{
    reseau->get(QNetworkRequest(
        QUrl("https://api.open-meteo.com/v1/"
             "forecast?latitude=49.26&longitude=4.03&current=temperature_2m,weather_code")));
}