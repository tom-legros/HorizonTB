#include "widgetmeteo.h"
#include <QString>
#include <QLabel>

WidgetMeteo::WidgetMeteo(QWidget *parent): QWidget{parent}
{
    this->labelMeteo = new QLabel(this);
    this->degres = 0;
    this->labelMeteo->setText(QString::number(this->degres)+"°C");
}
