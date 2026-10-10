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

    QString descriptionDepuisCode(int code);
    QString iconeDepuisCode(int code);

private slots:
    void reponseRecue(QNetworkReply *reponse);
    void demanderMeteo();

public:
    explicit WidgetMeteo(QWidget *parent = nullptr);

signals:
};

#endif // WIDGETMETEO_H
