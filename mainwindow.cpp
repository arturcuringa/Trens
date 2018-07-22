#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Semaforos
    for(int i=0; i<10; ++i)
        semaforo[i] = new Semaforo(150+i,1,0);


    //Verticais

    trem[0] = new Trem(1,90,210);
    connect(trem[0],SIGNAL(updateGUI(int,int,int,QString)),SLOT(updateInterface(int,int,int,QString)));
    connect(trem[0],SIGNAL(updateTime(int,double,double,double)),SLOT(updateTable(int,double,double,double)));
    trem[0]->start(semaforo);
    trem[0]->setVelocidade(2);
    trem[0]->setEnable(true);

    //Horizontais cima
    trem[1] = new Trem(2,230,120);
    connect(trem[1],SIGNAL(updateGUI(int,int,int,QString)),SLOT(updateInterface(int,int,int,QString)));
    connect(trem[1],SIGNAL(updateTime(int,double,double,double)),SLOT(updateTable(int,double,double,double)));
    trem[1]->start(semaforo);
    trem[1]->setVelocidade(5);
    trem[1]->setEnable(true);

    trem[2] = new Trem(3,390,120);
    connect(trem[2],SIGNAL(updateGUI(int,int,int,QString)),SLOT(updateInterface(int,int,int,QString)));
    connect(trem[2],SIGNAL(updateTime(int,double,double,double)),SLOT(updateTable(int,double,double,double)));
    trem[2]->start(semaforo);
    trem[2]->setVelocidade(4);
    trem[2]->setEnable(true);

    trem[3] = new Trem(4,530,210);
    connect(trem[3],SIGNAL(updateGUI(int,int,int,QString)),SLOT(updateInterface(int,int,int,QString)));
    connect(trem[3],SIGNAL(updateTime(int,double,double,double)),SLOT(updateTable(int,double,double,double)));
    trem[3]->start(semaforo);
    trem[3]->setVelocidade(5);
    trem[3]->setEnable(true);

    //Horizontais baixo
    trem[4] = new Trem(5,390,300);
    connect(trem[4],SIGNAL(updateGUI(int,int,int,QString)),SLOT(updateInterface(int,int,int,QString)));
    connect(trem[4],SIGNAL(updateTime(int,double,double,double)),SLOT(updateTable(int,double,double,double)));
    trem[4]->start(semaforo);
    trem[4]->setVelocidade(10);
    trem[4]->setEnable(true);

    trem[5] = new Trem(6,230,300);
    connect(trem[5],SIGNAL(updateGUI(int,int,int,QString)),SLOT(updateInterface(int,int,int,QString)));
    connect(trem[5],SIGNAL(updateTime(int,double,double,double)),SLOT(updateTable(int,double,double,double)));
    trem[5]->start(semaforo);
    trem[5]->setVelocidade(5);
    trem[5]->setEnable(true);

    //Central
    trem[6] = new Trem(7,390,210);
    connect(trem[6],SIGNAL(updateGUI(int,int,int,QString)),SLOT(updateInterface(int,int,int,QString)));
    connect(trem[6],SIGNAL(updateTime(int,double,double,double)),SLOT(updateTable(int,double,double,double)));
    trem[6]->start(semaforo);
    trem[6]->setVelocidade(5);
    trem[6]->setEnable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    //Necessario?
    for(int i=0; i<10; ++i)
        delete semaforo[i];
}

void MainWindow::updateTable(int id, double media, double desvio, double ultimo){
    switch (id) {
    case 1:
        ui->mediat1->setText(QString::number(media));
        ui->desviot1->setText(QString::number(sqrt(desvio)));
        ui->ultimot1->setText(QString::number(ultimo));
        break;
    case 2:
        ui->mediat2->setText(QString::number(media));
        ui->desviot2->setText(QString::number(sqrt(desvio)));
        ui->ultimot2->setText(QString::number(ultimo));
        break;
    case 3:
        ui->mediat3->setText(QString::number(media));
        ui->desviot3->setText(QString::number(sqrt(desvio)));
        ui->ultimot3->setText(QString::number(ultimo));
        break;
    case 4:
        ui->mediat4->setText(QString::number(media));
        ui->desviot4->setText(QString::number(sqrt(desvio)));
        ui->ultimot4->setText(QString::number(ultimo));
        break;
    case 5:
        ui->mediat5->setText(QString::number(media));
        ui->desviot5->setText(QString::number(sqrt(desvio)));
        ui->ultimot5->setText(QString::number(ultimo));
        break;
    case 6:
        ui->mediat6->setText(QString::number(media));
        ui->desviot6->setText(QString::number(sqrt(desvio)));
        ui->ultimot6->setText(QString::number(ultimo));
        break;
    case 7:
        ui->mediat7->setText(QString::number(media));
        ui->desviot7->setText(QString::number(sqrt(desvio)));
        ui->ultimot7->setText(QString::number(ultimo));
        break;
    default:
        break;
    }
}

void MainWindow::updateLabels(void){

    ui->strs1->setText(QString::number(semaforo[0]->getContador()));
    ui->strs2->setText(QString::number(semaforo[1]->getContador()));
    ui->strs3->setText(QString::number(semaforo[2]->getContador()));
    ui->strs4->setText(QString::number(semaforo[3]->getContador()));
    ui->strs5->setText(QString::number(semaforo[4]->getContador()));
    ui->strs6->setText(QString::number(semaforo[5]->getContador()));
    ui->strs7->setText(QString::number(semaforo[6]->getContador()));
    ui->strs8->setText(QString::number(semaforo[7]->getContador()));
    ui->strs9->setText(QString::number(semaforo[8]->getContador()));
    ui->strs10->setText(QString::number(semaforo[9]->getContador()));
}

void MainWindow::updateInterface(int id, int x, int y, QString log)
{
    switch(id){
        case 1:
            ui->labelTrem01->setGeometry(x,y,20,20);
            break;
        case 2:
            ui->labelTrem02->setGeometry(x,y,20,20);
            break;
        case 3:
            ui->labelTrem03->setGeometry(x,y,20,20);
            break;
        case 4:
            ui->labelTrem04->setGeometry(x,y,20,20);
            break;
        case 5:
            ui->labelTrem05->setGeometry(x,y,20,20);
            break;
        case 6:
            ui->labelTrem06->setGeometry(x,y,20,20);
            break;
        case 7:
            ui->labelTrem07->setGeometry(x,y,20,20);
            break;
        default:
            break;
    }
    updateLabels();
    trem[0]->setVelocidade(100 - ui->horizontalSlider->value());
    trem[1]->setVelocidade(100 - ui->horizontalSlider_2->value());
    trem[2]->setVelocidade(100 - ui->horizontalSlider_3->value());
    trem[3]->setVelocidade(100 - ui->horizontalSlider_4->value());
    trem[4]->setVelocidade(100 - ui->horizontalSlider_5->value());
    trem[5]->setVelocidade(100 - ui->horizontalSlider_6->value());
    trem[6]->setVelocidade(100 - ui->horizontalSlider_7->value());
}
