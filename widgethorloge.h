#ifndef WIDGETHORLOGE_H
#define WIDGETHORLOGE_H

#include <QLabel>
#include <QTimer>
#include <QWidget>

class WidgetHorloge : public QWidget
{
    Q_OBJECT

private:
    QLabel *labelHeure;
    QLabel *labelDate;
    QTimer *timer;

private slots:
    void mettreAJourHeure();

public:
    explicit WidgetHorloge(QWidget *parent = nullptr);
};

#endif // WIDGETHORLOGE_H