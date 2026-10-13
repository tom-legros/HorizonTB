#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QHBoxLayout>
#include <QScreen>

#include "widgethorloge.h"
#include "widgetmeteo.h"
#include "widgetbatterie.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMenuBar(nullptr);
    setStatusBar(nullptr);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    QScreen *ecran = QGuiApplication::primaryScreen();

    QRect rect = ecran->geometry();
    setGeometry(rect.x(), rect.y(), rect.width(), 48);
    QWidget *centre = centralWidget();
    centre->setStyleSheet("#centralwidget { background-color: rgba(20, 20, 20, 200); }"
                          "QLabel { color: white; background: transparent; }");

    QHBoxLayout *layout = new QHBoxLayout(centre);
    WidgetMeteo *meteoWidget = new WidgetMeteo(this);
    WidgetHorloge *horlogeWidget = new WidgetHorloge(this);


    layout->addWidget(meteoWidget);
    if (WidgetBatterie::batteriePresente()){
        WidgetBatterie *batterieWidget = new WidgetBatterie(this);
        layout->addWidget(batterieWidget);
    }
    layout->addWidget(horlogeWidget);
    setAttribute(Qt::WA_TranslucentBackground);
}

MainWindow::~MainWindow()
{
    delete ui;
}
