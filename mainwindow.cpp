#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "averagecolor.h"
#include "invertcolor.h"
#include "mixcolor.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbAverageColor_clicked()
{
    AverageColor avrg;
    avrg.exec();
}


void MainWindow::on_pbInvertColor_clicked()
{
    InvertColor invr;
    invr.exec();
}


void MainWindow::on_pbMixColor_clicked()
{
    MixColor mixr;
    mixr.exec();
}

