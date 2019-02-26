#include "startwindow.h"
#include <QApplication>
#include "Simulation.h"
#include "Actor.h"
#include <random>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow w;
    w.show();
    return a.exec();
}
