#include "sisterout.h"
#include "ui_sisterout.h"
#include "lyout_window.h"
#include "failcheck.h"

sisterout::sisterout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sisterout)
{
    ui->setupUi(this);
    setWhatsThis("Copyright © 2020-2021 CSP Rights Reserved.");

    this->setWindowTitle("city_Graph");
    /*
     * @ 寻 找 姐 妹 群
    */
    ui->cityInfor->setReadOnly(true);
    ui->sisterCity->setReadOnly(true);
    connect(ui->closeButton,SIGNAL(clicked()),
            this,SLOT(close()));
    City temp;
    for(int i = 0; i < vexnum ; i ++)
    {
        if(city.at(i).name.compare(city_flag) == 0)
        {
            temp = city.at(i);
        }
    }
    bool t1 = false;
    for(int i = 0 ;i < vexnum ; i ++)
    {
        if(temp.name.compare(city.at(i).name) == 0) continue;

        if(temp.population - city.at(i).population <= 50000 && temp.population - city.at(i).population >= -50000)
        { // 满 足 人 数 之 差 不 超 过 50000
            double a = city.at(i).w, b = city.at(i).j, a_p = city.at(i).w_pesition, b_p = city.at(i).j_pesition;
            if(a == temp.w)
            {
                if((-5 <= a_p - temp.w_pesition && a_p - temp.w_pesition <= 5))
                {
                    //
                    ui->cityInfor->setText("城市 "+ city_flag+" 的姐妹群");
                    ui->sisterCity->append(city.at(i).name + " " + QString::number(city.at(i).w_pesition)+(city.at(i).w == 1 ? "S " : "N ") +
                                           QString::number(city.at(i).j_pesition) + (city.at(i).j == 1 ? "W " : "E ") + " " +
                                           QString::number(city.at(i).population)+"人");

                    //                        ui->sisterCity->append(city.at(i).name);
                    t1 = true;
                }
            }else{
                if(a_p + temp.w_pesition <= 5)
                {
                    ui->cityInfor->setText("城市 "+ city_flag+" 的姐妹群");
                    ui->sisterCity->append(city.at(i).name + " " + QString::number(city.at(i).w_pesition)+(city.at(i).w == 1 ? "S " : "N ") +
                                           QString::number(city.at(i).j_pesition) + (city.at(i).j == 1 ? "W " : "E ") + " " +
                                           QString::number(city.at(i).population)+"人");
                    t1 = true;
                }
            }
            if(!t1){ // 纬 度 没 有 找 到 姐 妹 群
                if(b == temp.j)
                {
                    if((-5 <= b_p - temp.j_pesition && b_p - temp.j_pesition <= 5))
                    {
                        //
                        ui->cityInfor->setText("城市 "+ city_flag+" 的姐妹群");
                        ui->sisterCity->append(city.at(i).name + " " + QString::number(city.at(i).w_pesition)+(city.at(i).w == 1 ? "S " : "N ") +
                                               QString::number(city.at(i).j_pesition) + (city.at(i).j == 1 ? "W " : "E ") + " " +
                                               QString::number(city.at(i).population)+"人");
                        t1 = true;
                    }
                }else{
                    if(b_p + temp.j_pesition <= 5)
                    {
                        ui->cityInfor->setText("城市 "+ city_flag+" 的姐妹群");
                        ui->sisterCity->append(city.at(i).name + " " + QString::number(city.at(i).w_pesition)+(city.at(i).w == 1 ? "S " : "N ") +
                                               QString::number(city.at(i).j_pesition) + (city.at(i).j == 1 ? "W " : "E ") + " " +
                                               QString::number(city.at(i).population)+"人");
                        t1 = true;
                    }
                }
            }
        }
    }
    if(!t1)
    {
        ui->cityInfor->setText("城市 "+city_flag+" 不存在姐妹群");
        ui->sisterCity->append("无姐妹群");
    }
}

sisterout::~sisterout()
{
    delete ui;
}
