#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Semaforos
    for(int i=0; i<10; ++i)
        semaforos[i] = new Semaforo(150+i,1,0);


    //Verticais
    trem1 = new Trem(1,90,210);
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem1->start(semaforos);
    trem1->setVelocidade(50);

    trem4 = new Trem(4,530,210);
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem4->start(semaforos);
    trem4->setVelocidade(10);

    //Horizontais cima
    trem2 = new Trem(2,230,120);
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem2->start(semaforos);
    trem2->setVelocidade(10);

    trem3 = new Trem(3,390,120);
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem3->start(semaforos);
    trem3->setVelocidade(10);

    //Horizontais baixo
    trem5 = new Trem(5,390,300);
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem5->start(semaforos);
    trem5->setVelocidade(10);

    trem6 = new Trem(6,230,300);
    connect(trem6,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem6->start(semaforos);
    trem6->setVelocidade(10);

    //Central
    trem7 = new Trem(7,390,220);
    connect(trem7,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem7->start(semaforos);
    trem7->setVelocidade(100);

    /*
    sem0 = new Semafaro(151,1,0);
    sem1 = new Semafaro(152,1,0);
    sem2 = new Semafaro(152,1,0);
    sem3 = new Semafaro(154,1,0);
    sem4 = new Semafaro(155,1,0);
    sem5 = new Semafaro(156,1,0);
    sem6 = new Semafaro(157,1,0);
    sem7 = new Semafaro(158,1,0);
    sem8 = new Semafaro(159,1,0);
    sem9 = new Semafaro(1510,1,0);
    */
}

MainWindow::~MainWindow()
{
    delete ui;
    //Necessario?
    for(int i=0; i<10; ++i)
        delete semaforos[i];
}

void MainWindow::updateInterface(int id, int x, int y)
{
    switch(id){
        case 1:
            ui->labelTrem01->setGeometry(x,y,20,20);
            break;
        case 2:
            ui->labelTrem02->setGeometry(x,y,20,20);
            break;
        case 3:
            std::cout<<""<<std::endl;
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
}

