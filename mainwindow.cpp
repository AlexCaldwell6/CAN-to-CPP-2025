#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QPixmap>
#include <QLabel>
#include <QString>

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

    tempSensor = new TempSensor(this);
    connect(tempSensor, &TempSensor::tempUpdated, this, &MainWindow::updateTemp);
    tempSensor->startReading();

    mpptInputVoltageSensor = new MPPTInputVoltageSensor(this);
    connect(mpptInputVoltageSensor, &MPPTInputVoltageSensor::inputVoltageUpdated, this, &MainWindow::updateMPPTInputVoltage);
    mpptInputVoltageSensor->startReading();

    mpptOutputVoltageSensor = new MPPTOutputVoltageSensor(this);
    connect(mpptOutputVoltageSensor, &MPPTOutputVoltageSensor::outputVoltageUpdated, this, &MainWindow::updateMPPTOutputVoltage);
    mpptOutputVoltageSensor->startReading();

    mpptInputPowerSensor = new MPPTInputPowerSensor(this);
    connect(mpptInputPowerSensor, &MPPTInputPowerSensor::inputPowerUpdated, this, &MainWindow::updateMPPTInputPower);
    mpptInputPowerSensor->startReading();

    mpptOutputPowerSensor = new MPPTOutputPowerSensor(this);
    connect(mpptOutputPowerSensor, &MPPTOutputPowerSensor::outputPowerUpdated, this, &MainWindow::updateMPPTOutputPower);
    mpptOutputPowerSensor->startReading();
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

void MainWindow::updateTemp(int newTemp)
{
    ui->TempValue->display(newTemp);
}

void MainWindow::updateMPPTInputVoltage(int newVoltage)
{
    ui->InputVoltageValue->setText(QString::fromUtf8(std::to_string(newVoltage).append(" Volts")));
}

void MainWindow::updateMPPTOutputVoltage(int newVoltage)
{
    ui->OutputVoltageValue->setText(QString::fromUtf8(std::to_string(newVoltage).append(" Volts")));
}

void MainWindow::updateMPPTInputPower(int newPower)
{
    ui->InputPowerValueMPPT->setText(QString::fromUtf8(std::to_string(newPower).append(" Watts")));
}

void MainWindow::updateMPPTOutputPower(int newPower)
{
    ui->OutputPowerValueMPPT->setText(QString::fromUtf8(std::to_string(newPower).append(" Watts")));
}
