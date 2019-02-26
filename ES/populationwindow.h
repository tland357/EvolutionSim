#ifndef POPULATIONWINDOW_H
#define POPULATIONWINDOW_H

#include <QMainWindow>

namespace Ui {
class PopulationWindow;
}

class PopulationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PopulationWindow(QWidget *parent = nullptr);
    ~PopulationWindow();
    void setPopDescription(QString str);
private:
    Ui::PopulationWindow *ui;
};

#endif // POPULATIONWINDOW_H
