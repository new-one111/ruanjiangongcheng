#ifndef INFORMATIOM_H
#define INFORMATIOM_H

#include <QDialog>
#include <QDebug>
#include <QVector>

class informatiom{
    public:
    struct City
    {
        QString name;
        double w_pesition[2];// 纬 度
        double j_pesition[2];// 经 度
        double population;
    };
    QVector<City>city; //
    int idx;
    //int t = 0 ;
    int vexnum, arcnum;
    int mapGrap[1000][1000];
};
#endif // INFORMATIOM_H
