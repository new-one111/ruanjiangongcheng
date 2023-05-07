#include "mainwindowT.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwindowT w;
    w.show();
    return a.exec();
}
