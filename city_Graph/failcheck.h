#ifndef FAILCHECK_H
#define FAILCHECK_H

#include <QDialog>

namespace Ui {
class failCheck;
}

class failCheck : public QDialog
{
    Q_OBJECT

public:
    explicit failCheck(QWidget *parent = nullptr);
    ~failCheck();

private:
    Ui::failCheck *ui;
};

#endif // FAILCHECK_H
