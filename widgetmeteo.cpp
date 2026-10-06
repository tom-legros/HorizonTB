#include "widgetmeteo.h"
#include <QString>
#include <QLabel>
#include <QHBoxLayout>

WidgetMeteo::WidgetMeteo(QWidget *parent): QWidget{parent}
{
    this->labelMeteo = new QLabel(this);
    this->degres = 0;
    this->labelMeteo->setText(QString::number(this->degres)+"°C");

    QHBoxLayout *layoutMeteo = new QHBoxLayout(this);
    layoutMeteo->addWidget(this->labelMeteo);

    layoutMeteo->setContentsMargins(5, 0, 5, 0);
    this->setLayout(layoutMeteo);
}
