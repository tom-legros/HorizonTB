#ifndef WIDGETMETEO_H
#define WIDGETMETEO_H

#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkreply>
#include <QString>
#include <QWidget>

class WidgetMeteo : public QWidget
{
    Q_OBJECT
private:
    QLabel *labelMeteo;
    QLabel *iconeMeteo;
    QLabel *labelDescription;
    int degres;
    QNetworkAccessManager *reseau;

private slots:
    void reponseRecue(QNetworkReply *reponse);

public:
    explicit WidgetMeteo(QWidget *parent = nullptr);

signals:
};

#endif // WIDGETMETEO_H
