#include "trem.h"

Trem::Trem(int id, int x, int y)
{
    this->id = id;
    this->x = x;
    this->y = y;
    velocidade = 250;
    enable = true;
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

void Trem::start()
{
    threadTrem = std::thread(&Trem::run,this);
}

void Trem::run()
{
    while(true){
        switch(id){
        case 1:
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
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}

