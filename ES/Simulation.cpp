#include "Actor.h"
#include "MathBeing.h"
#include <random>
#include <iostream>
#include "Population.h"
#include "Actor.h"
#include "MathPopulation.h"
#include "Simulation.h"

using namespace std;


Simulation::Simulation(){

}


Simulation::Simulation(SimType type, float mutRate, float forgive, int rewardMult, unsigned int capacity){
    MutationRate = mutRate;
    GenerationForgiveness = forgive;
    GoodMultiplierSetting = rewardMult;
    Capacity = capacity;
    HistoryCount = 0;
    Type = type;
    CurrentPopulation = Population(type, mutRate, forgive, rewardMult, capacity);
}


void Simulation::GenerationRun() {
    CurrentPopulation.Run();
}


void Simulation::GenerationSort() {
    CurrentPopulation.sort();
}


void Simulation::GenerationKill() {
    CurrentPopulation.kill(GenerationForgiveness);
}


void Simulation::GenerationRegen() {
    CurrentPopulation.regen();
}


void Simulation::setForgiveness(float value) {
	GenerationForgiveness = value;
}


void Simulation::setRewardMultiplier(int value) {
	GoodMultiplierSetting = value;
}


void Simulation::setMutationRate(float value) {
	MutationRate = value;
}


float Simulation::getMutationRate() {
	return MutationRate;
}


Simulation::~Simulation() {
}


void Simulation::Setup(SimType Type) {

}

void Simulation::BMWCreatures(Actor *Worst, Actor *Middle, Actor *Best) {
    Best = CurrentPopulation.BestCreature;
    Middle = CurrentPopulation.MedianCreature;
    Worst = CurrentPopulation.WorstCreature;
}
