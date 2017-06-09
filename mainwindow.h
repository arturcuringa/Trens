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
    void updateLabels(void);

private:
    Ui::MainWindow *ui;
    Trem *trem[7];
    Semaforo* semaforo[10];
};

#endif // MAINWINDOW_H
