#include "mpptoutputvoltagesensor.h"

MPPTOutputVoltageSensor::MPPTOutputVoltageSensor(QObject *parent) : QObject(parent)
{
    // Every time we timeout, readSensorData.
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MPPTOutputVoltageSensor::readSensorData);
}

void MPPTOutputVoltageSensor::startReading()
{
    timer->start(100);
}

void MPPTOutputVoltageSensor::readSensorData()
{
    // This can/will of course be replaced with actual sensor data.
    int fakeOutputVoltage = rand() % 120;
    emit outputVoltageUpdated(fakeOutputVoltage);
}
