#include "populationwindow.h"
#include "ui_populationwindow.h"

PopulationWindow::PopulationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PopulationWindow)
{
    ui->setupUi(this);
}

PopulationWindow::~PopulationWindow()
{
    delete ui;
}

void PopulationWindow::setPopDescription(QString str) {
    ui->PopulationDescription->setText(str);
}
