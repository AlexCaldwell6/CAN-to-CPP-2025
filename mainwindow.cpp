#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QPixmap>
#include <QLabel>

/**
 * @brief MainWindow which contains all other UI objects.
 * @param parent Equal to nullptr, unused.
 *
 * @author Alex Caldwell
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    // Setup UI. Creates everything done in Qt creator.
    ui->setupUi(this);

    speedSensor = new SpeedSensor(this);
    connect(speedSensor, &SpeedSensor::speedUpdated, this, &MainWindow::updateSpeed);
    speedSensor->startReading();

    socSensor = new SOCSensor(this);
    connect(socSensor, &SOCSensor::socUpdated, this, &MainWindow::updateSOC);
    socSensor->startReading();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateSpeed(int newSpeed)
{
    ui->SpeedValue->display(newSpeed); //
}

void MainWindow::updateSOC(int newSOC)
{
    ui->SOCValue->display(newSOC);
}
