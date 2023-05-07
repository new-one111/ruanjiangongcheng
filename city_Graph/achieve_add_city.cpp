#include "achieve_add_city.h"
#include "ui_achieve_add_city.h"

achieve_add_city::achieve_add_city(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::achieve_add_city)
{
    ui->setupUi(this);
    this->setWindowTitle("city_Graph");
    setWhatsThis("Copyright © 2020-2021 CSP Rights Reserved.");
 }

achieve_add_city::~achieve_add_city()
{
    delete ui;
}
