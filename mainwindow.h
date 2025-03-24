#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "speedsensor.h"
#include "socsensor.h"

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

private:
    Ui::MainWindow *ui;
    SpeedSensor *speedSensor;
    SOCSensor *socSensor;

};
#endif // MAINWINDOW_H
