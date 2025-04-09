#include "mpptoutputpowersensor.h"

MPPTOutputPowerSensor::MPPTOutputPowerSensor(QObject *parent) : QObject(parent)
{
    // Every time we timeout, readSensorData.
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MPPTOutputPowerSensor::readSensorData);
}

void MPPTOutputPowerSensor::startReading()
{
    timer->start(100);
}

void MPPTOutputPowerSensor::readSensorData()
{
    // This can/will of course be replaced with actual sensor data.
    int fakeOutputPower = rand() % 120;
    emit outputPowerUpdated(fakeOutputPower);
}
