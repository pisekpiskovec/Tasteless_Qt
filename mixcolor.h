#ifndef MIXCOLOR_H
#define MIXCOLOR_H

#include <QDialog>
#include <commoncolorlib.h>

namespace Ui {
class MixColor;
}

class MixColor : public QDialog
{
    Q_OBJECT

public:
    explicit MixColor(QWidget *parent = nullptr);
    ~MixColor();

private slots:
    void on_pbLeft_clicked();

    void on_pbRight_clicked();

    void on_sbLeft_valueChanged(int arg1);

    void on_sbRight_valueChanged(int arg1);

private:
    Ui::MixColor *ui; commonColorLib ccl;
    int maxRGB;
    double avrR, avrG, avrB;
    int clr1R, clr1G, clr1B;
    int clr2R, clr2G, clr2B;
    QColor clr1 = Qt::black, clr2 = Qt::black;

    void calculate();
};

#endif // MIXCOLOR_H
