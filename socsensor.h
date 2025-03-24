#ifndef SOCSENSOR_H
#define SOCSENSOR_H

#include <QObject>
#include <QTimer>

class SOCSensor : public QObject
{
    Q_OBJECT

public:
    explicit SOCSensor(QObject *parent = nullptr);
    void startReading();

signals:
    void socUpdated(int newSOC); // Emitted when new data arrives

private slots:
    void readSensorData();

private:
    QTimer *timer;
};

#endif // SOCSENSOR_H
