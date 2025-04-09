#include "tempsensor.h"

TempSensor::TempSensor(QObject *parent) : QObject(parent)
{
    // Every time we timeout, readSensorData.
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TempSensor::readSensorData);
}

void TempSensor::startReading()
{
    timer->start(100);
}

void TempSensor::readSensorData()
{
    // This can/will of course be replaced with actual sensor data.
    int fakeTemp = rand() % 80;
    emit tempUpdated(fakeTemp);
}
