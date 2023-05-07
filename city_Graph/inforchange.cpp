#include "inforchange.h"
#include "ui_inforchange.h"
#include "mainwindowT.h"
#include "lyout_window.h"


inforChange::inforChange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inforChange)
{
    ui->setupUi(this);
    City temp;
    setWhatsThis("Copyright © 2020-2021 CSP Rights Reserved.");

    for(int i = 0 ; i < vexnum ; i ++)
    {
        if(city.at(i).name.compare(city_flag) == 0)
        {
            temp = city.at(i);
        }
    }
    ui->enSure->setEnabled(true);
    ui->enName->setPlaceholderText(temp.name);
    ui->w_Position->setPlaceholderText(QString::number(temp.w_pesition));
    ui->j_Position->setPlaceholderText(QString::number(temp.j_pesition));
    ui->population->setPlaceholderText(QString::number(temp.population));
    //ui->enName->setValidator(new QDoubleValidator);
    ui->w_Position->setValidator(new QDoubleValidator);
    ui->j_Position->setValidator(new QDoubleValidator);
    ui->population->setValidator(new QDoubleValidator);
    connect(ui->enSure,SIGNAL(clicked()),
            ui->close,SLOT(click()));
    connect(ui->close,SIGNAL(clicked()),
            this,SLOT(close()));
}

inforChange::~inforChange()
{
    delete ui;
}

void inforChange::on_enSure_clicked()
{
    for(int i = 0 ; i < vexnum ; i ++)
    {
        if(city.at(i).name.compare(city_flag) == 0)
        {

            city.at(i).name = ui->enName->text();
            city.at(i).w_pesition = ui->w_Position->text().toDouble();
            city.at(i).w = ui->w_box->currentText().compare("North") == 0 ? 0 : 1;
            city.at(i).j_pesition = ui->j_Position->text().toDouble();
            city.at(i).j = ui->j_box->currentText().compare("East") == 0 ? 0 : 1;
            city.at(i).population = ui->population->text().toDouble();
            break;

        }
    }
}
