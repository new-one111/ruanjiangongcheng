#include "inforout.h"
#include "ui_inforout.h"
#include "lyout_window.h"
#include "failcheck.h"

inforOut::inforOut(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inforOut)
{
    ui->setupUi(this);
    setWhatsThis("Copyright © 2020-2021 CSP Rights Reserved.");

    this->setWindowTitle("city_Graph");
    // inforout 窗口中 lineEdit 全部为只读
    ui->cityName->setReadOnly(true);
    ui->j_Position->setReadOnly(true);
    ui->w_Position->setReadOnly(true);
    ui->population->setReadOnly(true);
    ui->cityConnect->setReadOnly(true);
    connect(ui->closeButton,SIGNAL(clicked()),
            this,SLOT(close()));
    ui->cityName->setText(city_flag);
    /*
     * @ 根 据 城 市 名 称 查 找 信 息
    */
    bool flag = false;
    for(int i = 0; i < vexnum ; i ++)
    {
        if(ui->cityName->text().compare(city.at(i).name) == 0)
        {
            flag = true;
            if(city.at(i).w) ui->w_Position->setText(QString::number(city.at(i).w_pesition)+" South");
            else ui->w_Position->setText(QString::number(city.at(i).w_pesition)+" North");
            if(city.at(i).j) ui->j_Position->setText(QString::number(city.at(i).j_pesition)+" West");
            else ui->j_Position->setText(QString::number(city.at(i).j_pesition)+" East");
            ui->population->setText(QString::number(city.at(i).population));
            ui->cityConnect->setText(QString::number(vexnum - 1));
        }// 找 到 城 市
    }
    if(flag == false){
        failCheck fail;
        fail.show();
        fail.exec();
    } // 没 有 找 到 城 市

}

inforOut::~inforOut()
{
    delete ui;
}
