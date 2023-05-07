#include "allout.h"
#include "ui_allout.h"
#include "lyout_window.h"

allOut::allOut(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::allOut)
{
    ui->setupUi(this);
    setWhatsThis("Copyright © 2020-2021 CSP Rights Reserved.");
    this->setWindowTitle("city_Graph");
    ui->outWindow->setReadOnly(true);
    for(int i = 0; i < vexnum ; i ++)
    {
        ui->outWindow->append(QString::number(i+1) + ". " + city.at(i).name + " " + QString::number(city.at(i).w_pesition)+(city.at(i).w == 1 ? "S " : "N ") +
                              QString::number(city.at(i).j_pesition) + (city.at(i).j == 1 ? "W " : "E ") + " " +
                              QString::number(city.at(i).population)+"人");
    }
}

allOut::~allOut()
{
    delete ui;
}
