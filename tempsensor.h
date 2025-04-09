#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#include <QObject>
#include <QTimer>

class TempSensor : public QObject
{
    Q_OBJECT

public:
    explicit TempSensor(QObject *parent = nullptr);
    void startReading();

signals:
    void tempUpdated(int newTemp); // Emitted when new data arrives

private slots:
    void readSensorData();

private:
    QTimer *timer;
};

#endif // TEMPSENSOR_H
