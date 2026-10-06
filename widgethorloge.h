#ifndef WIDGETHORLOGE_H
#define WIDGETHORLOGE_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

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