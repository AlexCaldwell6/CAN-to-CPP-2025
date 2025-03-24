#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QPixmap>
#include <QLabel>

/**
 * @brief MainWindow which contains all other UI objects.
 * @param parent Equal to nullptr, unused.
 *
 * @author Alex Caldwell
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    // Setup UI. Creates everything done in Qt creator.
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
