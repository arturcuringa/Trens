#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "trem.h"
#include "semaforo.h"
#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;
    Trem *trem6;
    Trem *trem7;

    Semaforo *sem1;
    Semaforo *sem2;
    Semaforo *sem3;
    Semaforo *sem4;
    Semaforo *sem5;
    Semaforo *sem6;
    Semaforo *sem7;
    Semaforo *sem8;
    Semaforo *sem9;
    Semaforo *sem10;
};

#endif // MAINWINDOW_H
