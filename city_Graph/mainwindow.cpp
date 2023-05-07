//#include "mainwindow.h"
//#include "ui_mainwindow.h"
//#include "achieve_add_city.h"
//#include "lyout_window.h"
//using namespace std;
//struct City
//{
//    QString name;
//    double w_pesition[2];// 纬 度
//    double j_pesition[2];// 经 度
//    double population;
//};
//vector<City>city; //
//int idx = 0 ;
////int t = 0 ;
//int vexnum = 0, arcnum = 0;
//int mapGrap[1000][1000];
//MainWindow::MainWindow(QWidget *parent)
//    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
//{
//    ui->setupUi(this);
//    /*
//     * @ 初 始 化 mapGrap
//    */
//    for(int i = 0; i < 1000; i ++)
//        for(int j = 0; j < 1000; j ++)
//            mapGrap[i][j] = 0;

//    ui->j_Position->setPlaceholderText("输入经度");
//    ui->w_Position->setPlaceholderText("输入纬度");
//    ui->enName->setPlaceholderText("输入城市名称");
//    ui->population->setPlaceholderText("输入城市人口");
//    ui->addCity->setEnabled(false);
//    // 输入 LineEdit 有文本 添加按钮亮起
//    connect(ui->enName,SIGNAL(textChanged(QString)),
//            this,SLOT(enableButton()));
//    //点击 添加 提示信息
//    connect(ui->addCity,SIGNAL(clicked()),
//            ui->enName,SLOT(clear()));
//    //
//    ui->checkCity->setEnabled(false);
//    //
//    connect(ui->checkCity,SIGNAL(clicked()),
//            this,SLOT(on_clickShow()));
//}

//MainWindow::~MainWindow()
//{
//    delete ui;
//}

///*
// @ 根 据 文 本 输 入 有 无 调 整  *添 加 按 钮* 状 态
//*/
//void MainWindow::enableButton()
//{
//    QString str = ui->enName->text();
//    if(str.compare("")==0)
//    {
//        ui->addCity->setEnabled(false);
//    }else{
//        ui->addCity->setEnabled(true);
//    }
//}
///*
// @ 添 加 按 钮 储 存 数 据
//*/
//void MainWindow::on_addCity_clicked() //  点击后存储数据
//{
////  qDebug() << ui->w_box->currentText(); // Debug
//    City  temp;
//    temp.name = ui->enName->text();
//    QString str = ui->w_box->currentText();
//    if(ui->w_box->currentText().compare("North") == 0)
//    {   //  北 纬
//        temp.w_pesition[0] = ui->w_Position->text().toDouble();
//        if(ui->j_box->currentText().compare("East") == 0)
//        {
//            temp.j_pesition[0] = ui->j_Position->text().toDouble();
//        }else{
//            temp.j_pesition[1] = ui->j_Position->text().toDouble();
//        }
//    }else{
//        // 南 纬
//        temp.w_pesition[1] = ui->w_Position->text().toDouble();
//        if(ui->j_box->currentText().compare("East") == 0)
//        {
//            temp.j_pesition[0] = ui->j_Position->text().toDouble();
//        }else{
//            temp.j_pesition[1] = ui->j_Position->text().toDouble();
//        }
//    }
//    qDebug() << str;
//    temp.population = ui->population->text().toDouble();
//    vexnum ++; // 节点数 +1
////  qDebug()<< vexnum<<endl;
//    city.push_back(temp); // 头节点 +1
////  qDebug() << city.at(t).population,t++;
//    for(int i = 0; i < vexnum; i ++)
//    {
//        for(int j = 0; j < vexnum; j ++)
//        {
//            if(i != j && mapGrap[i][j] != 1) mapGrap[i][j] = 1;
//        }
//    } // 更 新 mapGrap 内 的 信 息


//    achieve_add_city b;
//    b.show();
//    b.exec();
//    ui->checkCity->setEnabled(true); // 开放查询按钮
//    //ui->enName->clear();
//    ui->j_Position->clear();
//    ui->w_Position->clear();
//    ui->population->clear();
//}
///*
// *@ 打 开 查 询 窗 口
//*/
//void MainWindow::on_clickShow()
//{
//    lyout_window check;
//    check.show();
//    check.exec();
//}
