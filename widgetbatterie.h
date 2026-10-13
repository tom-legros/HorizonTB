#ifndef WIDGETBATTERIE_H
#define WIDGETBATTERIE_H

#include <QLabel>
#include <QTimer>
#include <QWidget>

class WidgetBatterie : public QWidget
{
    Q_OBJECT
private:
    QLabel *labelBatterie;
    QTimer *timer;

private slots:
    void mettreAJourBatterie();
public:
    explicit WidgetBatterie(QWidget *parent = nullptr);
    static bool batteriePresente();

signals:
};

#endif // WIDGETBATTERIE_H
