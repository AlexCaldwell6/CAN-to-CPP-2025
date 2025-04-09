#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "speedsensor.h"
#include "socsensor.h"
#include "tempsensor.h"
#include "mpptinputvoltagesensor.h"
#include "mpptoutputvoltagesensor.h"
#include "mpptinputpowersensor.h"
#include "mpptoutputpowersensor.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateSpeed(int newSpeed);
    void updateSOC(int newSOC);
    void updateTemp(int newTemp);
    void updateMPPTInputVoltage(int newInputVoltage);
    void updateMPPTOutputVoltage(int newOutputVoltage);
    void updateMPPTInputPower(int newInputPower);
    void updateMPPTOutputPower(int newOutputPower);

private:
    Ui::MainWindow *ui;
    SpeedSensor *speedSensor;
    SOCSensor *socSensor;
    TempSensor *tempSensor;
    MPPTInputVoltageSensor *mpptInputVoltageSensor;
    MPPTOutputVoltageSensor *mpptOutputVoltageSensor;
    MPPTInputPowerSensor *mpptInputPowerSensor;
    MPPTOutputPowerSensor *mpptOutputPowerSensor;
};
#endif // MAINWINDOW_H
