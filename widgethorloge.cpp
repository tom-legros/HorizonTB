#include "widgethorloge.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>
#include <QDateTime>

WidgetHorloge::WidgetHorloge(QWidget *parent): QWidget{parent}
{
    this->labelHeure = new QLabel(this);
    this->labelDate  = new QLabel(this);
    this->timer  = new QTimer(this);

    connect(this->timer, &QTimer::timeout, this, &WidgetHorloge::mettreAJourHeure);
    this->timer->start(1000);
    this->mettreAJourHeure();

    QVBoxLayout *layoutHeureV = new QVBoxLayout(this);
    layoutHeureV->addWidget(this->labelHeure);
    layoutHeureV->addWidget(this->labelDate);
    layoutHeureV->addStretch();
    layoutHeureV->setContentsMargins(0, 0, 0, 0);

}

void WidgetHorloge::mettreAJourHeure()
{
    QDateTime Heure;
    Heure = QDateTime::currentDateTime();
    this->labelHeure->setText(Heure.toString("hh:mm"));
    this->labelDate->setText(Heure.toString("dd/MM/yyyy"));

}

