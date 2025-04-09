#include "mpptinputvoltagesensor.h"

MPPTInputVoltageSensor::MPPTInputVoltageSensor(QObject *parent) : QObject(parent)
{
    // Every time we timeout, readSensorData.
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MPPTInputVoltageSensor::readSensorData);
}

void MPPTInputVoltageSensor::startReading()
{
    timer->start(100);
}

void MPPTInputVoltageSensor::readSensorData()
{
    // This can/will of course be replaced with actual sensor data.
    int fakeInputVoltage = rand() % 120;
    emit inputVoltageUpdated(fakeInputVoltage);
}
