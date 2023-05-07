#ifndef ACHIEVE_ADD_CITY_H
#define ACHIEVE_ADD_CITY_H

#include "mainwindowT.h"
namespace Ui {
class achieve_add_city;
}

class achieve_add_city : public QDialog
{
    Q_OBJECT

public:
    explicit achieve_add_city(QWidget *parent = nullptr);
    ~achieve_add_city();

private:
    Ui::achieve_add_city *ui;
};

#endif // ACHIEVE_ADD_CITY_H
