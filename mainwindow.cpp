#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QScreen"
#include <QHBoxLayout>
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
    QHBoxLayout *layout = new QHBoxLayout(Centre);
    WidgetMeteo *meteoWidget = new WidgetMeteo(this);
    layout->addWidget(meteoWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}
