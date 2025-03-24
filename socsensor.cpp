#include "socsensor.h"

SOCSensor::SOCSensor(QObject *parent) : QObject(parent)
{
    // Every time we timeout, readSensorData.
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SOCSensor::readSensorData);
}

void SOCSensor::startReading()
{
    timer->start(100);
}

void SOCSensor::readSensorData()
{
    // This can/will of course be replaced with actual sensor data.
    int fakeSOC = rand() % 120;
    emit socUpdated(fakeSOC);
}
