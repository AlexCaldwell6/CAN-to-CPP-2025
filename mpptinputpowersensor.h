#ifndef MPPTINPUTPOWERSENSOR_H
#define MPPTINPUTPOWERSENSOR_H

#include <QObject>
#include <QTimer>

class MPPTInputPowerSensor : public QObject
{
    Q_OBJECT

public:
    explicit MPPTInputPowerSensor(QObject *parent = nullptr);
    void startReading();

signals:
    void inputPowerUpdated(int newInputPower); // Emitted when new data arrives

private slots:
    void readSensorData();

private:
    QTimer *timer;
};

#endif // MPPTINPUTPOWERSENSOR_H
