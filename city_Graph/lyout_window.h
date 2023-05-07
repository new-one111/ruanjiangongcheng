#ifndef LYOUT_WINDOW_H
#define LYOUT_WINDOW_H

#include "mainwindowT.h"

extern QString city_flag; //定 义 一 次
namespace Ui {
class lyout_window;
}

class lyout_window : public QDialog
{
    Q_OBJECT

public:
    explicit lyout_window(QWidget *parent = nullptr);
    ~lyout_window();
private slots:
    void enableButton();
    void on_cityCheck_clicked();
//    void enableButton2();


    void on_checkAll_clicked();

    void on_inforChange_clicked();

private:
    Ui::lyout_window *ui;
};

#endif // LYOUT_WINDOW_H
