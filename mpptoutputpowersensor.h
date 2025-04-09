#ifndef MPPTOUTPUTPOWERSENSOR_H
#define MPPTOUTPUTPOWERSENSOR_H

#include <QObject>
#include <QTimer>

class MPPTOutputPowerSensor : public QObject
{
    Q_OBJECT

public:
    explicit MPPTOutputPowerSensor(QObject *parent = nullptr);
    void startReading();

signals:
    void outputPowerUpdated(int newOutputPower); // Emitted when new data arrives

private slots:
    void readSensorData();

private:
    QTimer *timer;
};

#endif // MPPTIOUTPUTPOWERSENSOR_H
