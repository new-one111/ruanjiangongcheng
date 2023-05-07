#include "mainwindowT.h"
#include "ui_mainwindowT.h"
#include "achieve_add_city.h"
#include "lyout_window.h"
#include "informatiom.h"
//using namespace std;

int idx = 0;
//int t = 0 ;
int vexnum = 0, arcnum = 0;
int mapGrap[1000][1000];
vector<City>city;

mainwindowT::mainwindowT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindowT)
{
    ui->setupUi(this);
    setWhatsThis("Copyright © 2020-2021 CSP Rights Reserved.");
    this->setWindowTitle("city_Graph");
    /*
     * @ 初 始 化 mapGrap
    */
    for(int i = 0; i < 1000; i ++)
        for(int j = 0; j < 1000; j ++)
            mapGrap[i][j] = 0;
    // 设置LineEdit 的 属 性 和 浮 动 提 醒
    ui->j_Position->setPlaceholderText("输入经度");
    ui->w_Position->setPlaceholderText("输入纬度");
    ui->enName->setPlaceholderText("输入城市名称");
    ui->population->setPlaceholderText("输入城市人口");
    ui->j_Position->setValidator(new QDoubleValidator);
    ui->w_Position->setValidator(new QDoubleValidator);
    ui->population->setValidator(new QDoubleValidator);
    ui->addCity->setEnabled(false);
    // 输入 LineEdit 有文本 添加按钮亮起
    connect(ui->enName,SIGNAL(textChanged(QString)),
            this,SLOT(enableButton()));
    //点击 添加 提示信息
    connect(ui->addCity,SIGNAL(clicked()),
            ui->enName,SLOT(clear()));
    //
    ui->checkCity->setEnabled(false);
    //
    connect(ui->checkCity,SIGNAL(clicked()),
            this,SLOT(on_clickShow()));
}

mainwindowT::~mainwindowT()
{
    delete ui;
}

/*
 @ 根 据 文 本 输 入 有 无 调 整  *添 加 按 钮* 状 态
*/
void mainwindowT::enableButton()
{
    QString str = ui->enName->text();
    if(str.compare("")==0)
    {
        ui->addCity->setEnabled(false);
    }else{
        ui->addCity->setEnabled(true);
    }
}
/****************************************
**@添 加 按 钮 储 存 数 据 ( 核 心 1 )
**@北 纬 , 文 本 信 息 来 源 于 w_box @ 1 0
**@南 纬 , 文 本 信 息 来 源 于 w_box @ 2 1
**@东 经 , 文 本 信 息 来 源 于 j_box @ 3 0
**@西 经 , 文 本 信 息 来 源 于 j_box @ 4 1
*****************************************/
void mainwindowT::on_addCity_clicked() //  点击后存储数据
{
    //  qDebug() << ui->w_box->currentText(); // Debug
    City  temp;
    temp.name = ui->enName->text();
    QString str = ui->w_box->currentText();
    if(ui->w_box->currentText().compare("North") == 0)
        temp.w = 0;
    else
        temp.w = 1;
    if(ui->j_box->currentText().compare("East") == 0)
        temp.j = 0;
    else
        temp.j = 1;
    temp.w_pesition = ui->w_Position->text().toDouble();
    temp.j_pesition = ui->j_Position->text().toDouble();
    //  qDebug() << str;
    temp.population = ui->population->text().toDouble();
    vexnum ++; // 节点数 +1
    //  qDebug()<< vexnum<<endl;

    city.push_back(temp); // 头节点 +1
    //  qDebug() << city.at(t).population,t++;


    /*
     *@ 完 成 无 向 完 全 连 通 图 mapGrap
    */
    for(int i = 0; i < vexnum; i ++)
    {
        for(int j = 0; j < vexnum; j ++)
        {
            if(i != j && mapGrap[i][j] != 1) mapGrap[i][j] = 1;
        }
    } // 更 新 mapGrap 内 的 信 息


    achieve_add_city b;
    b.show();
    b.exec();
    ui->checkCity->setEnabled(true); // 开放查询按钮
    //ui->enName->clear();
    ui->j_Position->clear();
    ui->w_Position->clear();
    ui->population->clear();
}
/*
 *@ 打 开 查 询 窗 口
*/
void mainwindowT::on_clickShow()
{
    lyout_window check;
    check.show();
    check.exec();
}
