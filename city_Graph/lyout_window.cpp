#include "lyout_window.h"
#include "ui_lyout_window.h"
#include "inforout.h"
#include "ui_inforout.h"
#include "sisterout.h"
#include "ui_sisterout.h"
#include "allout.h"
#include "ui_allout.h"
#include "inforchange.h"
#include "ui_inforchange.h"

lyout_window::lyout_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lyout_window)
{
    ui->setupUi(this);
    setWhatsThis("Copyright © 2020-2021 CSP Rights Reserved.");

    this->setWindowTitle("city_Graph");
    //    ui->cityCheck->setEnabled(false);
    ui->cityIn->setPlaceholderText("输入城市名称");
    connect(ui->cityIn,SIGNAL(textChanged(QString)),
            this,SLOT(enableButton()));
    connect(ui->checkAll,SIGNAL(clicked()),
            this,SLOT(close()));
    connect(ui->inforChange,SIGNAL(clicked()),
            this,SLOT(on_inforChange_clicked()));
}

lyout_window::~lyout_window()
{
    delete ui;
}
/*
@
*/
void lyout_window::enableButton()
{
    QString str = ui->cityIn->text();
    if(str.compare("")==0)
    {
        ui->cityCheck->setEnabled(false);
    }else{
        ui->cityCheck->setEnabled(true);
    }
}
/*******************************
** @当 lyout 的 查 询 按 钮 被 按 下
*********************************/
QString city_flag;
void lyout_window::on_cityCheck_clicked()
{
    if(ui->infor_box->currentText().compare("信息") == 0)
    {
        city_flag = ui->cityIn->text();
        inforOut inforout;
        inforout.show();
        inforout.exec();
    }// 这是 输出 信息
    else/* if(ui->infor_box->currentText().compare("姐妹群") == 0)*/{ // 这是 输出 姐妹群
        city_flag = ui->cityIn->text();
        sisterout sisterCity;
        sisterCity.show();
        sisterCity.exec();
    }
}
/*************************************
 * @ 当lyout 的 全 部 查 询 按 钮 被 按 下
*************************************/
void lyout_window::on_checkAll_clicked()
{
    allOut out;
    out.show();
    out.exec();
}
/*******************
 * @ 修 改 城 市 信 息
*******************/
// city_flag  已 经 被 定 义
void lyout_window::on_inforChange_clicked()
{
    city_flag = ui->cityIn->text();
    for(int i = 0 ;i < vexnum ; i ++)
    {
        if(city.at(i).name.compare(city_flag) == 0)
        {
            inforChange inforchange;
            inforchange.show();
            inforchange.exec();
        }
    }
}
