#ifndef SISTEROUT_H
#define SISTEROUT_H

#include <QDialog>

namespace Ui {
class sisterout;
}

class sisterout : public QDialog
{
    Q_OBJECT

public:
    explicit sisterout(QWidget *parent = nullptr);
    ~sisterout();

private slots:

private:
    Ui::sisterout *ui;
};

#endif // SISTEROUT_H
