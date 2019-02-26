#include "startwindow.h"
#include <iostream>
#include "functionlibrary.h"
#include "Simulation.h"
#include <QRegExpValidator>
#include <QDoubleValidator>
#include "populationwindow.h"
#include "ui_startwindow.h"


using namespace std;

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
    {
        ui->setupUi(this);
        counter = 0;
        Type = MATH1;
        MutationRate = 0.01f;
        Forgiveness = 0.5f;
        RewardMultiplier = 2;
        Capacity = 100;
        Seed = 0;
        QRegExpValidator* PNInt = new QRegExpValidator(QRegExp("[+-]?\\d*"), this); // pos and neg
        QRegExpValidator* PInt = new QRegExpValidator(QRegExp("\\d*"), this);
        QDoubleValidator* PDouble = new QDoubleValidator(0.0, 1.0,12, this);
        ui->SeedInput->setValidator(PNInt);
        ui->CreatureObserveInput->setValidator(PInt);
        ui->MutationInput->setValidator(PDouble);
        ui->ForgivenessInput->setValidator(PDouble);
        ui->CapacityInput->setValidator(PInt);
        ui->MultiGen->setValidator(PInt);
        prevScrollPosition = 0;
        Reset();

    }

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_StartSim_BT_clicked()
{
    rangeChecks();
    if (counter < 9999)
        RunGen();
}

void StartWindow::RunGen() {

    if (counter > 0) {
        Sim.GenerationKill();
        Sim.GenerationRegen();
    }
    else {
        ui->BestCreatureInfo->setCursor(Qt::CursorShape::PointingHandCursor);
        ui->MedianCreatureInfo->setCursor(Qt::CursorShape::PointingHandCursor);
        ui->WorstCreatureInfo->setCursor(Qt::CursorShape::PointingHandCursor);
    }
    Sim.GenerationRun();
    Sim.GenerationSort();
    QString best = "Best Performer\n";
    best += Sim.CurrentPopulation.BestCreature->toString();
    QString middle = "Median Performer\n";
    middle += Sim.CurrentPopulation.MedianCreature->toString();
    QString worst = "Worst Performer\n";
    worst += Sim.CurrentPopulation.WorstCreature->toString();
    ui->WorstCreatureInfo->setText(worst);
    ui->MedianCreatureInfo->setText(middle);
    ui->BestCreatureInfo->setText(best);
    int u = ui->CreatureObserveInput->text().toInt();
    ui->label->setText("Creature: " + QString::number(u) + "\n" + Sim.CurrentPopulation.ActorList[u]->toStringComprehensive());
    ui->EvolutionCounter->setNum(++counter);
}

void StartWindow::on_SimType1_clicked()
{
    counter = 0;
    ui->EvolutionCounter->setNum(0);
    ui->label->setText("\
Function Snakes are made up of one randomly\n\
generated constant value, and a list of up\n\
to 20 functions. Every snake starts with a\n\
score of 1, and iteratively passes its\n\
value into its chain of functions to try\n\
and achieve the highest score possible.\n\
Key: [] -> starting value\n\
     () -> function\n");
    Reset();
}

void StartWindow::on_SimType2_clicked()
{
    counter = 0;
ui->label->setText("\
Function Snakes are made up of one randomly\n\
generated constant value, and a list of up\n\
to 20 functions. Every snake starts with a\n\
score of 1, and iteratively passes its\n\
value into its chain of functions to try\n\
and achieve the highest score possible.\n\
Additionally, efficiency based function\n\
snakes want to achieve the highest score\n\
with the least amount of functions\n\
Key: [] -> starting value\n\
     () -> function\n");
    ui->EvolutionCounter->setNum(0);
    Reset();
}

void StartWindow::on_SeedInput_textChanged(const QString &arg1)
{
    Seed = arg1.toInt();
    Reset();
}

void StartWindow::Reset() {
    counter = 0;
    ui->EvolutionCounter->setNum(0);
    srand(Seed);
    if (Capacity >= MIN_POP_CAPACITY && Capacity <= MAX_POP_CAPACITY) {
        Sim = Simulation(Type, MutationRate, Forgiveness, RewardMultiplier, Capacity);
        ui->verticalSlider->setRange(0, Capacity);
    }
    ui->label->setText("");
    ui->verticalSlider->setValue(0);
    ui->CreatureObserveInput->setText("0");
    ui->BestCreatureInfo->setCursor(Qt::CursorShape::ForbiddenCursor);
    ui->MedianCreatureInfo->setCursor(Qt::CursorShape::ForbiddenCursor);
    ui->WorstCreatureInfo->setCursor(Qt::CursorShape::ForbiddenCursor);
    ui->BestCreatureInfo->setText("Best Performer");
    ui->MedianCreatureInfo->setText("Median Performer");
    ui->WorstCreatureInfo->setText("Worst Performer");
}

void StartWindow::on_MutationInput_textChanged(const QString &arg1)
{
    MutationRate = arg1.toFloat();
    Reset();
}

void StartWindow::on_ForgivenessInput_textChanged(const QString &arg1)
{
    Forgiveness = arg1.toFloat();
    Reset();
    ui->label->setText("\
Forgiveness is a measure of how forgiving natural\n\
selection is for creatures who perform poorly\n\
during the simulation");
}

void StartWindow::on_CapacityInput_textChanged(const QString &arg1)
{

}

void StartWindow::rangeChecks() {
    bool flag = false;
    if (Capacity < MIN_POP_CAPACITY) {
        ui->CapacityInput->setText(QString::number(MIN_POP_CAPACITY));
        Capacity = MIN_POP_CAPACITY;
        ui->verticalSlider->setRange(0, MIN_POP_CAPACITY);
        flag = true;
    } else if (Capacity > MAX_POP_CAPACITY) {
        ui->CapacityInput->setText("MAX_POP_CAPACITY");
        Capacity = MAX_POP_CAPACITY;
        ui->verticalSlider->setRange(0, MAX_POP_CAPACITY);
        flag = true;
    }
    if (MutationRate > 1.0f) {
        ui->MutationInput->setText("1");
        MutationRate = 1.0f;
        flag = true;
    } else if (MutationRate < 0.0f) {
        ui->MutationInput->setText("0");
        MutationRate = 0.0f;
        flag = true;
    }
    if (Forgiveness > 1.0f) {
        ui->ForgivenessInput->setText("1");
        Forgiveness = 1.0f;
        flag = true;
    } else if (Forgiveness < 0.0f) {
        ui->ForgivenessInput->setText("0");
        Forgiveness = 0.0f;
        flag = true;
    }
    if (flag)
        Reset();
}

QString StartWindow::genPopulationDescription() {
    QString str = "Population Description:\n\n";
    for (Actor* a: Sim.CurrentPopulation.ActorList) {
        str += a->toString() + "\n";
    }
    return str;
}

void StartWindow::on_ShowPop_BT_clicked()
{

}

void StartWindow::on_verticalSlider_sliderMoved(int position)
{
    if (counter > 0) {
        if (position < Sim.CurrentPopulation.ActorList.size() && position >= 0) {
            ui->label->setText("Creature: " + QString::number(position) + "\n" + Sim.CurrentPopulation.ActorList[position]->toStringComprehensive());
            ui->CreatureObserveInput->setText(QString::number(position));
        }
    }
}

void StartWindow::on_verticalSlider_valueChanged(int value)
{

}

void StartWindow::on_CapacityInput_textEdited(const QString &arg1)
{
    Capacity = arg1.toInt();
    Reset();
}

void StartWindow::on_CreatureObserveInput_textEdited(const QString &arg1)
{
    if (counter > 0) {
        if (arg1.toInt() < Sim.CurrentPopulation.ActorList.size() && arg1.toInt() >= 0) {
            ui->verticalSlider->setValue(arg1.toInt());
            ui->label->setText("Creature: " + QString::number(arg1.toInt()) + "\n" + Sim.CurrentPopulation.ActorList[arg1.toInt()]->toStringComprehensive());
        }
    }
}

void StartWindow::on_BestCreatureInfo_clicked()
{
    if (counter > 0) {
        ui->verticalSlider->setValue(Capacity - 1);
        ui->CreatureObserveInput->setText(QString::number(Capacity - 1));
        ui->label->setText(Sim.CurrentPopulation.BestCreature->toStringComprehensive());
    }
}

void StartWindow::on_MedianCreatureInfo_clicked()
{
    if (counter > 0) {
        ui->verticalSlider->setValue(Capacity / 2);
        ui->CreatureObserveInput->setText(QString::number(Capacity / 2));
        ui->label->setText(Sim.CurrentPopulation.MedianCreature->toStringComprehensive());
    }
}

void StartWindow::on_WorstCreatureInfo_clicked()
{
    if (counter > 0) {
        ui->verticalSlider->setValue(0);
        ui->CreatureObserveInput->setText(QString::number(0));
        ui->label->setText(Sim.CurrentPopulation.WorstCreature->toStringComprehensive());
    }
}

void StartWindow::on_MultiGen_BT_clicked()
{
    rangeChecks();
    for (int i = 0; i < ui->MultiGen->text().toInt() && counter < 9999; i += 1) {
        RunGen();
    }
}
