#include "trem.h"

Trem::Trem(int id, int x, int y)
{
    this->id = id;
    this->x = x;
    this->y = y;
    velocidade = 250;
    enable = false;
}

Trem::~Trem()
{
    threadTrem.join();
}

void Trem::setVelocidade(int velocidade)
{
    this->velocidade = velocidade;
}

void Trem::setEnable(bool enable)
{
    this->enable = enable;
}

void Trem::start(Semaforo* semaforo[])
{
    threadTrem = std::thread(&Trem::run,this,semaforo);
}

void Trem::run(Semaforo* semaforo[])
{
    while(true){
        switch(id){
        case 1:
            //Cima
            if(y==120 && x== 140){
                semaforo[0]->P();
            }
            if(x==150 && y==210){
                semaforo[0]->V();
            }
            //Baixo
            if(x==150 && y==230){
                semaforo[7]->P();
            }
            if(y==300 && x==120){
                semaforo[7]->V();
            }

            if (enable)
            {

                emit updateGUI(id,x,y);
                if (x == 90 && y > 120)
                    y-=10;
                else if (y == 120 && x < 150)
                    x+=10;
                else if (x == 150 && y < 300)
                    y+=10;
                else if (y == 300 && x > 90)
                    x-=10;
                else std::cout<<"bugou";
            }

            break;
        case 2:
            //Esquerda
            if(y==180 && x==160){
                semaforo[0]->P();
            }
            if(y==120 && x==180){
                semaforo[0]->V();
            }
            //Direita
            if(y==120 && x==300){
                semaforo[3]->P();
                semaforo[1]->P();
            }
            if(y==180 && x==280){
                semaforo[1]->V();
            }
            if(y== 180 && x==200){
                semaforo[3]->V();
            }

            //std::cout<<"Semaforo 1: "<<semaforo[0]->getContador()<<std::endl;
            //std::cout<<"Semaforo 2: "<<semaforo[1]->getContador()<<std::endl;
            //std::cout<<"Semaforo 4: "<<semaforo[3]->getContador()<<std::endl;

            if (enable)
            {
                emit updateGUI(id,x,y);
                if (x == 150 && y > 120)
                    y-=10;
                else if (y == 120 && x < 310)
                    x+=10;
                else if (x == 310 && y < 180)
                    y+=10;
                else if (y == 180 && x > 150)
                    x-=10;
                else std::cout<<"bugou";
            }
            break;
        case 3:
            //Esquerda
            if(y==180 && x==410){
               semaforo[1]->P();
               semaforo[4]->P();

            }
            if(y==150 && x==310){
               semaforo[4]->V();
            }
            if(y==120 && x==340){
               semaforo[1]->V();
            }
            //Direita
            if(y==120 && x==460){
                semaforo[2]->P();
            }
            if(y==180 && x==440){
                semaforo[2]->V();
            }

            //std::cout<<"Semaforo 5: "<<semaforo[4]->getContador()<<std::endl;
            //std::cout<<"Semaforo 2: "<<semaforo[1]->getContador()<<std::endl;
            //std::cout<<"Semaforo 3: "<<semaforo[2]->getContador()<<std::endl;

            if (enable)
            {
                emit updateGUI(id,x,y);
                if (x == 310 && y > 120)
                    y-=10;
                else if (y == 120 && x < 470)
                    x+=10;
                else if (x == 470 && y < 180)
                    y+=10;
                else if (y == 180 && x > 310)
                    x-=10;
                else std::cout<<"bugou";
            }
            break;
        case 4:
            //Cima
            if(x==470 && y==190){
                semaforo[2]->P();
            }
            if(x==490 && y==120){
                semaforo[2]->V();
            }
            //Baixo
            if(x==500 && y==300){
                semaforo[9]->P();
            }
            if(x==470 && y==220){
                semaforo[9]->V();
            }
            //std::cout<<"Semaforo 3: "<<semaforo[2]->getContador()<<std::endl;
            //std::cout<<"Semaforo 10: "<<semaforo[9]->getContador()<<std::endl;

            if (enable)
            {
                emit updateGUI(id,x,y);
                if (x == 470 && y > 120)
                    y-=10;
                else if (y == 120 && x < 530)
                    x+=10;
                else if (x == 530 && y < 300)
                    y+=10;
                else if (y == 300 && x > 470)
                    x-=10;
                else std::cout<<"bugou";
            }
            break;
        case 5:
            //Esquerda
            if(y==300 && x==320){
                semaforo[6]->P();
                semaforo[8]->P();

            }
            if(y==240 && x==340){
                semaforo[8]->V();
                //enable=false;
            }
            if(y==240 && x==420){
                semaforo[6]->V();
                //enable=false;
                //enable=false;
            }

            //Direita
            if(y==240 && x==440){
                semaforo[9]->P();
            }
            if(y==300 && x==440){
                semaforo[9]->V();
            }
            //std::cout<<"Semaforo 9: "<<semaforo[8]->getContador()<<std::endl;
            //std::cout<<"Semaforo 10: "<<semaforo[9]->getContador()<<std::endl;

            if (enable)
            {
                emit updateGUI(id,x,y);
                if (x == 310 && y > 240)
                    y-=10;
                else if (y == 240 && x < 470)
                    x+=10;
                else if (x == 470 && y < 300)
                    y+=10;
                else if (y == 300 && x > 310)
                    x-=10;
                else std::cout<<"bugou";
            }
            break;
        case 6:
            //Esquerda
            //Semaforo 8
            if(x==160 && y==300){
                semaforo[7]->P();
            }

            if(x==180 && y==240){
                semaforo[7]->V();
            }

            //Direita
            //Semaforo 6
            if(y==240 && x==220){
                semaforo[8]->P();
                semaforo[5]->P();

            }
            if(y==270 && x==310){
                semaforo[5]->V();
            }

            //Semaforo 9
            /*
            if(y==240 && x==300){
                //semaforo[1]->V();
            }*/
            if(y==300 && x==280){
                semaforo[8]->V();

            }
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (x == 150 && y > 240)
                    y-=10;
                else if (y == 240 && x < 310)
                    x+=10;
                else if (x == 310 && y < 300)
                    y+=10;
                else if (y == 300 && x > 150)
                    x-=10;
                else std::cout<<"bugou";
            }
            break;

        case 7:
            /**** Cima ****/
            //Semaforo 4
            if(x==230 && y==200){
                semaforo[4]->P();
                semaforo[3]->P();
                //enable=false;
            }
            if(x==350 && y==180){
                semaforo[3]->V();
                //enable=false;
            }
            /* Segundo
            //Semaforo 5
            if(x==300 && y==180){
                enable=false;
            }
            */
            if(x==390 && y==200){
                semaforo[4]->V();
                //enable=false;
            }

            /**** Baixo ****/
            //Semaforo 7
            if(x==390 && y==230){
                semaforo[5]->P();
                semaforo[6]->P();
                //enable=false;
            }
            if(x==280 && y==240){
                semaforo[6]->V();
                //enable=false;
            }
            /*
            //Semaforo 6
            if(x==320 && y==240){
                //enable=false;
            }*/
            if(x==230 && y==210){
                semaforo[5]->V();
                //enable=false;
            }

            if (enable)
            {
                emit updateGUI(id,x,y);
                if (x == 230 && y > 180)
                    y-=10;
                else if (y == 180 && x < 390)
                    x+=10;
                else if (x == 390 && y < 240)
                    y+=10;
                else if (y == 240 && x > 230)
                    x-=10;
                else std::cout<<"bugou";
            }
            break;
        default:
            std::cout<<"ID ESTRANHO"<<id<<std::endl;
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}

