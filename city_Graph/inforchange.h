#ifndef INFORCHANGE_H
#define INFORCHANGE_H

#include <QDialog>

namespace Ui {
class inforChange;
}

class inforChange : public QDialog
{
    Q_OBJECT

public:
    explicit inforChange(QWidget *parent = nullptr);
    ~inforChange();

private slots:
    void on_enSure_clicked();

private:
    Ui::inforChange *ui;
};

#endif // INFORCHANGE_H
