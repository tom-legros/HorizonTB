#include "widgetmeteo.h"
#include <QString>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

WidgetMeteo::WidgetMeteo(QWidget *parent): QWidget{parent}
{
    this->degres = 0;
    this->labelMeteo = new QLabel(this);
    this->labelDescription = new QLabel(this);
    this->iconeMeteo = new QLabel(this);

    this->labelMeteo->setText(QString::number(this->degres)+"°C");
    this->labelDescription->setText("Nuage");
    this->iconeMeteo->setText("☁️");

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
