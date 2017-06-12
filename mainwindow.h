#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "trem.h"
#include "semaforo.h"
#include <QMainWindow>
#include <cstdio>       //printf
#include <cstring>      //memset
#include <cstdlib>      //exit
#include <netinet/in.h> //htons
#include <arpa/inet.h>  //inet_addr
#include <sys/socket.h> //socket
#include <unistd.h>     //close
#include <cmath>


#define PORTNUM 4555
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateInterface(int,int,int);
    void updateLabels(void);
    void updateTable(int,double,double,double);

private:
    Ui::MainWindow *ui;
    Trem *trem[7];
    Semaforo* semaforo[10];
    void serverHandler();

    typedef struct{
        int op;
        int id;
        int value;
    }Operation;

};

#endif // MAINWINDOW_H
