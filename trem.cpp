#include "trem.h"

Trem::Trem(int id, int x, int y)
{
    this->id = id;
    this->x = x;
    this->y = y;
    this->xInicial=x;
    this->yInicial=y;
    velocidade = 250;
    enable = true;
    numvoltas=0;
    somaTempo=0;
    tempoVoltas=new vector<double>();
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
    struct timespec start, finish;
    double elapsed;

    while(true){
        switch(id){
        case 1:
            //Cima
            if(y==120 && x== 140){
                   semaforo[0]->P();
            }
            if(x==150 && y==210){
                if(!semaforo[0]->getContador())
                    semaforo[0]->V();
            }
            //Baixo
            if(x==150 && y==230){
                    semaforo[7]->P();
            }
            if(y==300 && x==120){
                if(!semaforo[7]->getContador())
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
                if(!semaforo[0]->getContador())
                    semaforo[0]->V();
            }
            //Direita
            if(y==120 && x==300){
//                semaforo[1]->P();
//                semaforo[3]->P();
                semaforo[4]->P();
            }
            if(y== 180 && x==200){

//                    semaforo[1]->V();
//                    std::cout << "1" << std::endl;
//                    semaforo[3]->V();
//                    std::cout << "3" << std::endl;
                if(!semaforo[4]->getContador())
                    semaforo[4]->V();


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


                semaforo[4]->P();

            }
            if(y==120 && x==340){

//                    semaforo[1]->V();
//                    std::cout << "1" << std::endl;
//                    semaforo[3]->V();
//                    std::cout << "3" << std::endl;
                if(!semaforo[4]->getContador())
                    semaforo[4]->V();

            }
            //Direita
            if(y==120 && x==460){
                    semaforo[2]->P();
            }
            if(y==180 && x==440){
                if(!semaforo[2]->getContador())
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
                if(!semaforo[2]->getContador())
                    semaforo[2]->V();
            }
            //Baixo
            if(x==500 && y==300){

                    semaforo[9]->P();
            }
            if(x==470 && y==220){
                if(!semaforo[9]->getContador())
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
//                    semaforo[5]->P();
                    semaforo[6]->P();
//                    semaforo[8]->P();
            }

            if(y==240 && x==420){
                if( !semaforo[6]->getContador() )
                {
//                    semaforo[5]->V();
                    semaforo[6]->V();
//                    semaforo[8]->V();
                }
            }

            //Direita
            if(y==240 && x==440){
                    semaforo[9]->P();
            }
            if(y==300 && x==440){
                if(!semaforo[9]->getContador())
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
                if(!semaforo[7]->getContador())
                    semaforo[7]->V();
            }

            //Direita
            //Semaforo 6
            if(y==240 && x==220){

//                semaforo[5]->P();
                semaforo[6]->P();
//                semaforo[8]->P();

            }
            //Semaforo 9
            /*
            if(y==240 && x==300){
                //semaforo[1]->V();
            }*/
            if(y==300 && x==280){
//                if(!semaforo[5]->getContador() && !semaforo[6]->getContador() && !semaforo[8]->getContador())
//                {
//                    semaforo[5]->V();
//                    semaforo[6]->V();
//                    semaforo[8]->V();
//                }
                if( !semaforo[6]->getContador() )
                {
//                    semaforo[5]->V();
                    semaforo[6]->V();
//                    semaforo[8]->V();
                }
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
//                semaforo[1]->P();
//                semaforo[3]->P();
                semaforo[4]->P();
                //enable=false;
            }

            /* Segundo
            //Semaforo 5
            if(x==300 && y==180){
                enable=false;
            }
            */
            if(x==390 && y==200){

                if( !semaforo[4]->getContador() )
                {
//                    semaforo[5]->V();
                    semaforo[4]->V();
//                    semaforo[8]->V();
                }
                    //semaforo[1]->V();
                    //std::cout << "1" << std::endl;
                    //semaforo[3]->V();
                    //std::cout << "3" << std::endl;
                    //semaforo[4]->V();
                    //std::cout << "4" << std::endl;

                //enable=false;
            }

            /**** Baixo ****/
            //Semaforo 7
            if(x==390 && y==230){
                //semaforo[5]->P();
                semaforo[6]->P();
                //semaforo[8]->P();
                //enable=false;
            }
            /*
            //Semaforo 6
            if(x==320 && y==240){
                //enable=false;
            }*/
            if(x==230 && y==210){
                if( !semaforo[6]->getContador() )
                {
//                    semaforo[5]->V();
                    semaforo[6]->V();
//                    semaforo[8]->V();
                }
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
        if(x==xInicial && y==yInicial){
            if(numvoltas!=0){

                clock_gettime(CLOCK_REALTIME, &finish);

                elapsed = (finish.tv_sec - start.tv_sec);
                elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

                numvoltas++;
                tempoVoltas->push_back(elapsed);
                somaTempo+=tempoVoltas->back();

                double media=somaTempo/numvoltas;
                double somatorio=0;
                for(unsigned int i=0;i<tempoVoltas->size();++i){
                    somatorio+=(x-media)*(x-media);
                }somatorio/=(numvoltas);

                emit updateTime(id,media,somatorio,tempoVoltas->back());

                clock_gettime(CLOCK_MONOTONIC, &start);
            }else numvoltas++;
        }
        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}

