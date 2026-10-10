#include "widgetmeteo.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QString>
#include <QVBoxLayout>

WidgetMeteo::WidgetMeteo(QWidget *parent): QWidget{parent}
{
    this->degres = 0;
    this->labelMeteo = new QLabel(this);
    this->labelDescription = new QLabel(this);
    this->iconeMeteo = new QLabel(this);
    this->reseau = new QNetworkAccessManager(this);

    connect(this->reseau, &QNetworkAccessManager::finished, this, &WidgetMeteo::reponseRecue);

    this->labelDescription->setText("Nuage");
    this->iconeMeteo->setText("☁️");
    this->reseau->get(QNetworkRequest(
        QUrl("https://api.open-meteo.com/v1/"
             "forecast?latitude=49.26&longitude=4.03&current=temperature_2m,weather_code")));

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
    QJsonDocument document = QJsonDocument::fromJson(reponse->readAll());
    QJsonObject meteoActuelle = document.object().value("current").toObject();
    double temperature = meteoActuelle.value("temperature_2m").toDouble();

    this->degres = qRound(temperature);
    this->labelMeteo->setText(QString::number(this->degres) + "°C");

    reponse->deleteLater();
}
