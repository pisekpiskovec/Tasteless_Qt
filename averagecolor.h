#ifndef AVERAGECOLOR_H
#define AVERAGECOLOR_H

#include <QDialog>
#include <QPixmap>

namespace Ui {
class AverageColor;
}

class AverageColor : public QDialog
{
    Q_OBJECT

public:
    explicit AverageColor(QWidget *parent = nullptr);
    ~AverageColor();

private slots:
    void on_pbLoadImage_clicked();

    void on_pbCalculate_clicked();

private:
    Ui::AverageColor *ui;
    QPixmap img;
};

#endif // AVERAGECOLOR_H
