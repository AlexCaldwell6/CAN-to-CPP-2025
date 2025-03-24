#ifndef SPEEDSENSOR_H
#define SPEEDSENSOR_H

#include <QObject>
#include <QTimer>

class SpeedSensor : public QObject
{
    Q_OBJECT

public:
    explicit SpeedSensor(QObject *parent = nullptr);
    void startReading();

signals:
    void speedUpdated(int newSpeed); // Emitted when new data arrives

private slots:
    void readSensorData();

private:
    QTimer *timer;
};

#endif // SPEEDSENSOR_H
