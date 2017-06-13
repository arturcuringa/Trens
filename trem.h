#ifndef TREM_H
#define TREM_H

#include <QObject>
#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
#include <time.h>

#include "semaforo.h"
using namespace std;

class Trem : public QObject
{
    Q_OBJECT
public:
    Trem(int,int,int);
    ~Trem();
    void start(Semaforo *semaforo[]);
    void run(Semaforo *semaforo[]);
    void setVelocidade(int);
    void setEnable(bool);

signals:
    void updateGUI(int,int,int);
    void updateTime(int,double,double,double);

private:
   std::thread threadTrem;
   int id;
   int x;
   int y;
   int xInicial;
   int yInicial;
   int velocidade;
   bool enable;

   double curVolta;
   double lastVolta;
   double var;
   int numvoltas;
   double somaTempo;
   std::vector<double>* tempoVoltas;
};

#endif // TREM_H


