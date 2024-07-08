#include "mixcolor.h"
#include "ui_mixcolor.h"
#include "QColorDialog"
#include <math.h>

MixColor::MixColor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MixColor)
{
    ui->setupUi(this);
    calculate();
}

MixColor::~MixColor()
{
    delete ui;
}

void MixColor::on_pbLeft_clicked()
{
    QColor tmp = QColorDialog::getColor();
    clr1 = tmp;
    QPixmap pix(ui->gvLeft->geometry().width(), ui->gvLeft->geometry().height());
    pix.fill(tmp);
    QGraphicsScene *scene = new QGraphicsScene();
    scene->addPixmap(pix);
    scene->setSceneRect(pix.rect());
    ui->gvLeft->setScene(scene);
    clr1R = tmp.red(); clr1G = tmp.green(); clr1B = tmp.blue();
    calculate();
}


void MixColor::on_pbRight_clicked()
{
    QColor tmp = QColorDialog::getColor();
    clr2 = tmp;
    QPixmap pix(ui->gvRight->geometry().width(), ui->gvRight->geometry().height());
    pix.fill(tmp);
    QGraphicsScene *scene = new QGraphicsScene();
    scene->addPixmap(pix);
    scene->setSceneRect(pix.rect());
    ui->gvRight->setScene(scene);
    clr2R = tmp.red(); clr2G = tmp.green(); clr2B = tmp.blue();
    calculate();
}

void MixColor::calculate()
{
    if(ui->sbLeft->value() == 0 && ui->sbRight->value() == 0)
    {
        QPixmap pix(ui->gvColor->geometry().width(), ui->gvColor->geometry().height());
        pix.fill(Qt::black);
        QGraphicsScene *scene = new QGraphicsScene();
        scene->addPixmap(pix);
        scene->setSceneRect(pix.rect());
        ui->gvColor->setScene(scene);
        ui->leColor->setText(QString(""));
        return;
    }
    maxRGB = (ui->sbLeft->value()*255) + (ui->sbRight->value()*255);
    avrR = (clr1R * ui->sbLeft->value()) + (clr2R * ui->sbRight->value());
    avrG = (clr1G * ui->sbLeft->value()) + (clr2G * ui->sbRight->value());
    avrB = (clr1B * ui->sbLeft->value()) + (clr2B * ui->sbRight->value());

    avrR *= 255;
    avrG *= 255;
    avrB *= 255;

    avrR /= maxRGB;
    avrG /= maxRGB;
    avrB /= maxRGB;

    avrR = ceil(avrR);
    avrG = ceil(avrG);
    avrB = ceil(avrB);

    QColor result(avrR, avrG, avrB);
    QPixmap pix(64, 64);
    pix.fill(result);
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(pix);
    scene->setSceneRect(pix.rect());
    ui->gvColor->setScene(scene);

    ui->leColor->setText(result.name());
}


void MixColor::on_sbLeft_valueChanged(int arg1) { calculate(); }
void MixColor::on_sbRight_valueChanged(int arg1) { calculate(); }

