#ifndef MPPTINPUTVOLTAGESENSOR_H
#define MPPTINPUTVOLTAGESENSOR_H

#include <QObject>
#include <QTimer>

class MPPTInputVoltageSensor : public QObject
{
    Q_OBJECT

public:
    explicit MPPTInputVoltageSensor(QObject *parent = nullptr);
    void startReading();

signals:
    void inputVoltageUpdated(int newInputVoltage); // Emitted when new data arrives

private slots:
    void readSensorData();

private:
    QTimer *timer;
};

#endif // MPPTINPUTVOLTAGESENSOR_H
