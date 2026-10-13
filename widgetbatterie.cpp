#include "widgetbatterie.h"

#include <QLabel>
#include <QTimer>
#include <QFile>
#include <QHBoxLayout>

WidgetBatterie::WidgetBatterie(QWidget *parent)
    : QWidget{parent}
{
    this->labelBatterie = new QLabel(this);
    this->timer = new QTimer(this);

    connect(this->timer, &QTimer::timeout, this, &WidgetBatterie::mettreAJourBatterie);
    this->timer->start(30*1000);
    this->mettreAJourBatterie();

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(this->labelBatterie);

}
void WidgetBatterie::mettreAJourBatterie()
{
    QFile fichierCapacite("/sys/class/power_supply/BAT0/capacity");
    if (!fichierCapacite.open(QIODevice::ReadOnly | QIODevice::Text)) {
        this->labelBatterie->setText("Secteur");
        return;
    }
    int pourcentage = fichierCapacite.readAll().trimmed().toInt();

    QString icone = "🔋";
    QFile fichierStatut("/sys/class/power_supply/BAT0/status");
    if (fichierStatut.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if (fichierStatut.readAll().trimmed() == "Charging") {
            icone = "⚡";
        }
    }

    this->labelBatterie->setText(icone + " " + QString::number(pourcentage) + " %");
}

bool WidgetBatterie::batteriePresente()
{
    return QFile::exists("/sys/class/power_supply/BAT0/capacity");
}