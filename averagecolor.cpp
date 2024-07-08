#include "averagecolor.h"
#include "ui_averagecolor.h"
#include <QIcon>
#include <QFileDialog>
#include <QDebug>

AverageColor::AverageColor(QWidget *parent) : QDialog(parent), ui(new Ui::AverageColor)
{
    ui->setupUi(this);
}

AverageColor::~AverageColor()
{
    delete ui;
}

void AverageColor::on_pbLoadImage_clicked()
{
    img.load(QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::currentPath(), tr("Image Files (*.png *.jpg *.bmp)")));
    QPixmap tmpimg = img.scaled(300, 300, Qt::KeepAspectRatio);
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(tmpimg);
    scene->setSceneRect(tmpimg.rect());
    ui->gvImage->setScene(scene);
}


void AverageColor::on_pbCalculate_clicked()
{
    if(img.isNull()) {ui->leColor->setText("ERROR"); return;}
    QImage qimg = img.toImage();
    int imgX = img.size().width(), imgY = img.size().height(), itrCount = 0;
    int avrR = 0, avrG = 0, avrB = 0;
    for(int x = 0; x < imgX; x++){
        for(int y = 0; y < imgY; y++){
            if(ui->cbSkipTransparent->isChecked() && qimg.pixelColor(x,y).alpha() == 0) continue;
            avrR += qimg.pixelColor(x,y).red();
            avrG += qimg.pixelColor(x,y).green();
            avrB += qimg.pixelColor(x,y).blue();
            itrCount++;
        }
    }

    avrR /= itrCount;
    avrG /= itrCount;
    avrB /= itrCount;

    QColor result(avrR, avrG, avrB);
    QPixmap pix(32, 32);
    pix.fill(result);
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(pix);
    scene->setSceneRect(pix.rect());
    ui->gvColor->setScene(scene);

    ui->leColor->setText(result.name());
}

