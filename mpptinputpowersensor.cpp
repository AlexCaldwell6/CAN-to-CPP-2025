#include "mpptinputpowersensor.h"

MPPTInputPowerSensor::MPPTInputPowerSensor(QObject *parent) : QObject(parent)
{
    // Every time we timeout, readSensorData.
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MPPTInputPowerSensor::readSensorData);
}

void MPPTInputPowerSensor::startReading()
{
    timer->start(100);
}

void MPPTInputPowerSensor::readSensorData()
{
    // This can/will of course be replaced with actual sensor data.
    int fakeInputPower = rand() % 120;
    emit inputPowerUpdated(fakeInputPower);
}
