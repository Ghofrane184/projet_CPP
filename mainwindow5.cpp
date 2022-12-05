#include "mainwindow5.h"
#include "ui_mainwindow5.h"

MainWindow5::MainWindow5(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow5)
{
    ui->setupUi(this);
}

MainWindow5::~MainWindow5()
{
    delete ui;
}
