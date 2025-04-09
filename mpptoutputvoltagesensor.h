#ifndef MPPTOUTPUTVOLTAGESENSOR_H
#define MPPTOUTPUTVOLTAGESENSOR_H

#include <QObject>
#include <QTimer>

class MPPTOutputVoltageSensor : public QObject
{
    Q_OBJECT

public:
    explicit MPPTOutputVoltageSensor(QObject *parent = nullptr);
    void startReading();

signals:
    void outputVoltageUpdated(int newOutputVoltage); // Emitted when new data arrives

private slots:
    void readSensorData();

private:
    QTimer *timer;
};

#endif // MPPTIOUTPUTVOLTAGESENSOR_H
