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
    curVolta=0;
    lastVolta=0;
    var=0;
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
    QString log;
    while(true){
        switch(id){
        case 1:
            //Cima
            if(y==120 && x== 140){
                semaforo[0]->P();
            }
            if(x==150 && y==210){
                if(!semaforo[0]->getContador()){
                    semaforo[0]->V();
                }
            }
            //Baixo
            if(x==150 && y==230){
                semaforo[7]->P();
            }
            if(y==300 && x==120){
                if(!semaforo[7]->getContador()){
                    semaforo[7]->V();
                }
            }

            if (enable)
            {
                emit updateGUI(id,x,y,log);
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
                if(!semaforo[0]->getContador()){
                    semaforo[0]->V();
                }
            }
            //Direita
            if(y==120 && x==300){
                semaforo[1]->P();
                semaforo[3]->P();
            }
            if(y== 180 && x==200){
                if(!semaforo[1]->getContador()){
                    semaforo[1]->V();
                }
                if(!semaforo[3]->getContador()){
                    semaforo[3]->V();
                }
            }

            if (enable)
            {
                emit updateGUI(id,x,y,log);
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
                semaforo[1]->P();
            }
            if(y==120 && x==340){
                if(!semaforo[4]->getContador()){
                    semaforo[4]->V();
                }
                if(!semaforo[1]->getContador()){
                    semaforo[1]->V();
                }
            }
            //Direita
            if(y==120 && x==460){
                semaforo[2]->P();
            }
            if(y==180 && x==440){
                if(!semaforo[2]->getContador()){
                    semaforo[2]->V();
                }
            }

            if (enable)
            {
                emit updateGUI(id,x,y,log);
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
                if(!semaforo[2]->getContador()){
                    semaforo[2]->V();
                }
            }
            //Baixo
            if(x==500 && y==300){
                semaforo[9]->P();
            }
            if(x==470 && y==220){
                if(!semaforo[9]->getContador()){
                    semaforo[9]->V();
                }
            }

            if (enable)
            {
                emit updateGUI(id,x,y,log);
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
                semaforo[8]->P();
                semaforo[6]->P();
            }

            if(y==240 && x==420){
                if( !semaforo[8]->getContador() )
                {
                    semaforo[8]->V();
                }
                if( !semaforo[6]->getContador() )
                {
                    semaforo[6]->V();
                }
            }

            //Direita
            if(y==240 && x==440){
                semaforo[9]->P();
            }
            if(y==300 && x==440){
                if(!semaforo[9]->getContador()){
                    semaforo[9]->V();
                }
            }

            if (enable)
            {
                emit updateGUI(id,x,y,log);
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
               // log=QString::fromStdString("Trem 6: Pos("+std::to_string(x)+","+std::to_string(y)+"). Semaforo 8. P()\n");
            }

            if(x==180 && y==240){
                if(!semaforo[7]->getContador()){
                    semaforo[7]->V();
                 //   log=QString::fromStdString("Trem 6: Pos("+std::to_string(x)+","+std::to_string(y)+"). Semaforo 8. V()\n");
                }
            }

            //Direita
            if(y==240 && x==220){
                semaforo[5]->P();
                semaforo[8]->P();

            }
            if(y==300 && x==280){
                if( !semaforo[5]->getContador() )
                {
                    semaforo[5]->V();
                 //   log=QString::fromStdString("Trem 6: Pos("+std::to_string(x)+","+std::to_string(y)+"). Semaforo 7. P()\n");
                }
                if( !semaforo[8]->getContador() )
                {
                    semaforo[8]->V();
                 //   log=QString::fromStdString("Trem 6: Pos("+std::to_string(x)+","+std::to_string(y)+"). Semaforo 7. P()\n");
                }
            }
            if (enable)
            {
                emit updateGUI(id,x,y,log);
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
            if(x==230 && y==200){
                semaforo[3]->P();
                semaforo[4]->P();
            }
            if(x==390 && y==200){

                if( !semaforo[3]->getContador() )
                {
                    semaforo[3]->V();
                }
                if( !semaforo[4]->getContador() )
                {
                    semaforo[4]->V();
                }

            }

            /**** Baixo ****/
            //Semaforo 7
            if(x==390 && y==230){
                semaforo[5]->P();
                semaforo[6]->P();
            }
            if(x==230 && y==210){
                if( !semaforo[5]->getContador() )
                {
                    semaforo[5]->V();
                }

                if( !semaforo[6]->getContador() )
                {
                    semaforo[6]->V();
                }

            }

            if (enable)
            {
                emit updateGUI(id,x,y,log);
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

        if(enable){
            curVolta += velocidade / 1000.0;

            if(x==xInicial && y==yInicial && curVolta > velocidade / 1000.0){
                /*numvoltas++;
                //tempoVoltas->push_back(elapsed);
                somaTempo+=curVolta;

                double media=somaTempo/numvoltas;
                double somatorio=0;
                for(unsigned int i=0;i<tempoVoltas->size();++i){
                    somatorio+=(x-media)*(x-media);
                }somatorio/=(numvoltas);
                */
                ++numvoltas;
                var =  numvoltas < 2 ? 0 : var*(numvoltas-2.0)/(numvoltas-1.0) + (1.0/numvoltas)* pow(curVolta-(somaTempo/(numvoltas-1.0)),2);
                somaTempo+=curVolta;
                lastVolta = curVolta;
                curVolta = 0;
                emit updateTime(id,numvoltas<1? 0 : somaTempo/numvoltas,sqrt(var),lastVolta);
            }
        }
        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}

