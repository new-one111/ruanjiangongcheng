#ifndef INFOROUT_H
#define INFOROUT_H

#include <QDialog>

namespace Ui {
class inforOut;
}

class inforOut : public QDialog
{
    Q_OBJECT

public:
    explicit inforOut(QWidget *parent = nullptr);
    ~inforOut();

private slots:
    //void on_closeButton_clicked();

private:
    Ui::inforOut *ui;
};

#endif // INFOROUT_H
