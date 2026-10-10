#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QHBoxLayout>
#include <QScreen>

#include "widgethorloge.h"
#include "widgetmeteo.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    QScreen *ecran = QGuiApplication::primaryScreen();

    QRect rect = ecran->geometry();
    setGeometry(rect.x(), rect.y(), rect.width(), 48);
    QWidget *Centre = centralWidget();
    Centre->setStyleSheet("#centralwidget { background-color: rgba(20, 20, 20, 200); }"
                          "QLabel { color: white; background: transparent; }");

    QHBoxLayout *layout = new QHBoxLayout(Centre);
    WidgetMeteo *meteoWidget = new WidgetMeteo(this);
    WidgetHorloge *horlogeWidget = new WidgetHorloge(this);

    layout->addWidget(meteoWidget);
    layout->addWidget(horlogeWidget);
    setAttribute(Qt::WA_TranslucentBackground);
}

MainWindow::~MainWindow()
{
    delete ui;
}
