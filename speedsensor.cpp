#include "speedsensor.h"

SpeedSensor::SpeedSensor(QObject *parent) : QObject(parent)
{
    // Every time we timeout, readSensorData.
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SpeedSensor::readSensorData);
}

void SpeedSensor::startReading()
{
    timer->start(100);
}

void SpeedSensor::readSensorData()
{
    // This can/will of course be replaced with actual sensor data.
    int fakeSpeed = rand() % 120;
    emit speedUpdated(fakeSpeed);
}
