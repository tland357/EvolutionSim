#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "Simulation.h"
#include <QMainWindow>

enum RadioType {
    Math1,
    Math2
};
const int MAX_POP_CAPACITY = 10000;
const int MIN_POP_CAPACITY = 10;

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private slots:
    void on_StartSim_BT_clicked();

    void on_SimType1_clicked();

    void on_SimType2_clicked();

    void on_SeedInput_textChanged(const QString &arg1);

    void on_MutationInput_textChanged(const QString &arg1);

    void on_ForgivenessInput_textChanged(const QString &arg1);

    void on_CapacityInput_textChanged(const QString &arg1);

    void on_ShowPop_BT_clicked();

    void on_verticalSlider_sliderMoved(int position);

    void on_verticalSlider_valueChanged(int value);

    void on_CapacityInput_textEdited(const QString &arg1);

    void on_CreatureObserveInput_textEdited(const QString &arg1);

    void on_BestCreatureInfo_clicked();

    void on_MedianCreatureInfo_clicked();

    void on_WorstCreatureInfo_clicked();

    void on_MultiGen_BT_clicked();

private:
    void Reset();
    void RunGen();
    SimType Type;
    class Simulation Sim;
    Ui::StartWindow *ui;
    int counter;
    float MutationRate;
    float Forgiveness;
    int RewardMultiplier;
    unsigned int Capacity;
    long long int Seed;
    void rangeChecks();
    QString populationDescription;
    QString genPopulationDescription();
    int prevScrollPosition;
};

#endif // STARTWINDOW_H
