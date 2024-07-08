#ifndef INVERTCOLOR_H
#define INVERTCOLOR_H

#include <QDialog>

namespace Ui {
class InvertColor;
}

class InvertColor : public QDialog
{
    Q_OBJECT

public:
    explicit InvertColor(QWidget *parent = nullptr);
    ~InvertColor();

private slots:
    void on_pbPick_clicked();

private:
    Ui::InvertColor *ui;
};

#endif // INVERTCOLOR_H
