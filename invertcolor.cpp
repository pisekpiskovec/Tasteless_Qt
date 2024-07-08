#include "invertcolor.h"
#include "ui_invertcolor.h"
#include <QColorDialog>
#include <math.h>

InvertColor::InvertColor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InvertColor)
{
    ui->setupUi(this);
}

InvertColor::~InvertColor()
{
    delete ui;
}

void InvertColor::on_pbPick_clicked()
{
    QColor begin(QColorDialog::getColor());
    QColor result(abs(255-begin.red()), abs(255-begin.green()), abs(255-begin.blue()));

    QPixmap pixB(32, 32);
    QPixmap pixR(32, 32);
    pixB.fill(begin);
    pixR.fill(result);
    QGraphicsScene *sceneB = new QGraphicsScene(this);
    QGraphicsScene *sceneR = new QGraphicsScene(this);
    sceneB->addPixmap(pixB);
    sceneB->setSceneRect(pixB.rect());
    ui->gvInitial->setScene(sceneB);
    sceneR->addPixmap(pixR);
    sceneR->setSceneRect(pixR.rect());
    ui->gvColor->setScene(sceneR);
    ui->leColor->setText(result.name());
}

