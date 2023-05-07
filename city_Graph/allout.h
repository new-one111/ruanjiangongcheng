#ifndef ALLOUT_H
#define ALLOUT_H

#include <QDialog>

namespace Ui {
class allOut;
}

class allOut : public QDialog
{
    Q_OBJECT

public:
    explicit allOut(QWidget *parent = nullptr);
    ~allOut();

private:
    Ui::allOut *ui;
};

#endif // ALLOUT_H
