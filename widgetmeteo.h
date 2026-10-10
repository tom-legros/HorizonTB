#ifndef WIDGETMETEO_H
#define WIDGETMETEO_H

#include <QWidget>
#include <QString>
#include <QLabel>

class WidgetMeteo : public QWidget
{
    Q_OBJECT
private :
    QLabel *labelMeteo;
    QLabel *iconeMeteo;
    QLabel *labelDescription;
    int degres;

public:
    explicit WidgetMeteo(QWidget *parent = nullptr);

signals:
};

#endif // WIDGETMETEO_H
