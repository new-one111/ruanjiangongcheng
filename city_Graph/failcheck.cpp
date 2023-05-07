#include "failcheck.h"
#include "ui_failcheck.h"

failCheck::failCheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::failCheck)
{
    ui->setupUi(this);
    setWhatsThis("Copyright © 2020-2021 CSP Rights Reserved.");

    this->setWindowTitle("city_Graph");
}

failCheck::~failCheck()
{
    delete ui;
}
