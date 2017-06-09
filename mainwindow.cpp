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

    trem1 = new Trem(1,90,210);
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem1->start(semaforo);
    trem1->setVelocidade(50);

    trem4 = new Trem(4,530,210);
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem4->start(semaforo);
    trem4->setVelocidade(10);

    //Horizontais cima
    trem2 = new Trem(2,230,120);
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem2->start(semaforo);
    trem2->setVelocidade(10);

    trem3 = new Trem(3,390,120);
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem3->start(semaforo);
    trem3->setVelocidade(10);

    //Horizontais baixo
    trem5 = new Trem(5,390,300);
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem5->start(semaforo);
    trem5->setVelocidade(10);

    trem6 = new Trem(6,230,300);
    connect(trem6,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem6->start(semaforo);
    trem6->setVelocidade(10);

    //Central
    trem7 = new Trem(7,390,220);
    connect(trem7,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem7->start(semaforo);
    trem7->setVelocidade(200);
}

MainWindow::~MainWindow()
{
    delete ui;
    //Necessario?
    for(int i=0; i<10; ++i)
        delete semaforo[i];
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

void MainWindow::updateInterface(int id, int x, int y)
{
    updateLabels();
    switch(id){
        case 1:
            //Cima
            if(y==120 && x== 140){
                std::cout<<"Trem 1: Pos("<<x<<","<<y<<"). Semaforo 1. P()"<<std::endl;
                //ui->strs1->setText("0");
            }
            if(x==150 && y==210){
                std::cout<<"Trem 1: Pos("<<x<<","<<y<<"). Semaforo 1. V()"<<std::endl;

            }
            //Baixo
            if(x==150 && y==230)
                std::cout<<"Trem 1: Pos("<<x<<","<<y<<"). Semaforo 8. P()"<<std::endl;

            if(y==300 && x==120)
                std::cout<<"Trem 1: Pos("<<x<<","<<y<<"). Semaforo 8. V()"<<std::endl;

            ui->labelTrem01->setGeometry(x,y,20,20);
            break;
        case 2:

            //Esquerda
            if(y==180 && x==160)
                std::cout<<"Trem 2: Pos("<<x<<","<<y<<"). Semaforo 1. P()"<<std::endl;
            if(y==120 && x==180)
                std::cout<<"Trem 2: Pos("<<x<<","<<y<<"). Semaforo 1. V()"<<std::endl;

            //Direita
            if(y==120 && x==300){
                std::cout<<"Trem 2: Pos("<<x<<","<<y<<"). Semaforo 4. P()"<<std::endl;
                std::cout<<"Trem 2: Pos("<<x<<","<<y<<"). Semaforo 2. P()"<<std::endl;
                //semaforo[3]->P();
                //semaforo[1]->P();
            }
            if(y==180 && x==280)
                std::cout<<"Trem 2: Pos("<<x<<","<<y<<"). Semaforo 2. V()"<<std::endl;
            if(y== 180 && x==200)
                std::cout<<"Trem 2: Pos("<<x<<","<<y<<"). Semaforo 4. V()"<<std::endl;

            ui->labelTrem02->setGeometry(x,y,20,20);
            break;
        case 3:

            //Esquerda
            if(y==180 && x==410){
                std::cout<<"Trem 3: Pos("<<x<<","<<y<<"). Semaforo 2. P()"<<std::endl;
                std::cout<<"Trem 3: Pos("<<x<<","<<y<<"). Semaforo 5. P()"<<std::endl;
                //semaforo[1]->P();
               //semaforo[4]->P();
            }
            if(y==150 && x==310){
                std::cout<<"Trem 3: Pos("<<x<<","<<y<<"). Semaforo 5. V()"<<std::endl;
                //semaforo[4]->V();
            }
            if(y==120 && x==340){
                std::cout<<"Trem 3: Pos("<<x<<","<<y<<"). Semaforo 2. V()"<<std::endl;
               //semaforo[1]->V();
            }
            //Direita
            if(y==120 && x==460){
                std::cout<<"Trem 3: Pos("<<x<<","<<y<<"). Semaforo 3. P()"<<std::endl;
                //semaforo[2]->P();
            }
            if(y==180 && x==440){
                std::cout<<"Trem 3: Pos("<<x<<","<<y<<"). Semaforo 3. V()"<<std::endl;
                //semaforo[2]->V();
            }
            ui->labelTrem03->setGeometry(x,y,20,20);
            break;
        case 4:

            //Cima
            if(x==470 && y==190){
                std::cout<<"Trem 4: Pos("<<x<<","<<y<<"). Semaforo 3. P()"<<std::endl;
                //semaforo[2]->P();
            }
            if(x==490 && y==120){
                std::cout<<"Trem 4: Pos("<<x<<","<<y<<"). Semaforo 3. V()"<<std::endl;
                //semaforo[2]->V();
            }
            //Baixo
            if(x==500 && y==300){
                std::cout<<"Trem 4: Pos("<<x<<","<<y<<"). Semaforo 10. P()"<<std::endl;
                //semaforo[9]->P();
            }
            if(x==470 && y==220){
                std::cout<<"Trem 4: Pos("<<x<<","<<y<<"). Semaforo 10. V()"<<std::endl;
                //semaforo[9]->V();
            }

            ui->labelTrem04->setGeometry(x,y,20,20);
            break;
        case 5:
            //Esquerda
            if(y==300 && x==320){
                //semaforo[6]->P();
                //semaforo[8]->P();
                std::cout<<"Trem 5: Pos("<<x<<","<<y<<"). Semaforo 7. P()"<<std::endl;
                std::cout<<"Trem 5: Pos("<<x<<","<<y<<"). Semaforo 9. P()"<<std::endl;
            }
            if(y==240 && x==340)
                std::cout<<"Trem 5: Pos("<<x<<","<<y<<"). Semaforo 9. V()"<<std::endl;

            if(y==240 && x==420)
                std::cout<<"Trem 5: Pos("<<x<<","<<y<<"). Semaforo 7. V()"<<std::endl;

            //Direita
            if(y==240 && x==440)
                std::cout<<"Trem 5: Pos("<<x<<","<<y<<"). Semaforo 10. P()"<<std::endl;

            if(y==300 && x==440)
                std::cout<<"Trem 5: Pos("<<x<<","<<y<<"). Semaforo 10. V()"<<std::endl;
            ui->labelTrem05->setGeometry(x,y,20,20);
            break;

        case 6:

            //Esquerda
            //Semaforo 8
            if(x==160 && y==300)
                std::cout<<"Trem 6: Pos("<<x<<","<<y<<"). Semaforo 8. P()"<<std::endl;

            if(x==180 && y==240)
                std::cout<<"Trem 6: Pos("<<x<<","<<y<<"). Semaforo 8. V()"<<std::endl;

            //Direita
            //Semaforo 6
            if(y==240 && x==220){
                std::cout<<"Trem 6: Pos("<<x<<","<<y<<"). Semaforo 9. P()"<<std::endl;
                std::cout<<"Trem 6: Pos("<<x<<","<<y<<"). Semaforo 6. P()"<<std::endl;
                //semaforo[8]->P();
                //semaforo[5]->P();
            }
            if(y==270 && x==310)
                std::cout<<"Trem 6: Pos("<<x<<","<<y<<"). Semaforo 6. V()"<<std::endl;

            if(y==300 && x==280)
                std::cout<<"Trem 6: Pos("<<x<<","<<y<<"). Semaforo 9. V()"<<std::endl;

            ui->labelTrem06->setGeometry(x,y,20,20);
            break;
        case 7:
            // Cima
            //Semaforo 4
            if(x==230 && y==200){
                std::cout<<"Trem 7: Pos("<<x<<","<<y<<"). Semaforo 5. P()"<<std::endl;
                std::cout<<"Trem 7: Pos("<<x<<","<<y<<"). Semaforo 4. P()"<<std::endl;
                //semaforo[4]->P();
                //semaforo[3]->P();
            }
            if(x==350 && y==180)
                std::cout<<"Trem 7: Pos("<<x<<","<<y<<"). Semaforo 4. V()"<<std::endl;

            if(x==390 && y==200)
                std::cout<<"Trem 7: Pos("<<x<<","<<y<<"). Semaforo 5. V()"<<std::endl;

            //Baixo
            //Semaforo 7
            if(x==390 && y==230){
                std::cout<<"Trem 7: Pos("<<x<<","<<y<<"). Semaforo 6. P()"<<std::endl;
                std::cout<<"Trem 7: Pos("<<x<<","<<y<<"). Semaforo 7. P()"<<std::endl;
                //semaforo[5]->P();
                //semaforo[6]->P();
            }
            if(x==280 && y==240)
                std::cout<<"Trem 7: Pos("<<x<<","<<y<<"). Semaforo 7. V()"<<std::endl;

            if(x==230 && y==210)
                std::cout<<"Trem 7: Pos("<<x<<","<<y<<"). Semaforo 6. V()"<<std::endl;

            ui->labelTrem07->setGeometry(x,y,20,20);
            break;
        default:
            break;
    }
}


