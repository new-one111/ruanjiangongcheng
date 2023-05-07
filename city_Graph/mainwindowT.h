#ifndef mainwindowT_H
#define mainwindowT_H

#include <QDialog>
#include <QDebug>
#include <vector>
#include <iostream>
#include <QString>

using namespace std;

struct City
{
    QString name;
    double w,j; //  南北西东
    double w_pesition;// 纬 度
    double j_pesition;// 经 度
    double population;
};
extern vector<City>city; //
extern int idx;
extern int vexnum, arcnum;
extern int mapGrap[1000][1000];

namespace Ui {
class mainwindowT;
}
class mainwindowT : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindowT(QWidget *parent = nullptr);
    ~mainwindowT();

private slots:
    //void on_pushButton_clicked();
    void enableButton();
    //void showTip();
    void on_addCity_clicked(); // 添加按钮
    //void on_checkCity_clicked(); // 查看按钮
    void on_clickShow();
private:
    Ui::mainwindowT *ui;
};

#endif // mainwindowT_H
