#pragma once
#include <fstream>
#include "Population.h"
#include "simtype.h"
#include "MathBeing.h"
#include "MathPopulation.h"
#include <random>

const int HistoryLength = 300;

class Simulation {
public:
    Simulation();
	//factory system for building a simulation type
    Simulation(SimType type, double mutRate, double forgive, int rewardMult, unsigned int Capacity);
	~Simulation();
    Population CurrentPopulation;
    //Population Math3Pop;
	void GenerationRun();
	void GenerationSort();
    void BMWCreatures(Actor* Worst, Actor* Middle, Actor* Best);
	void GenerationKill();
	void GenerationRegen();
    void setForgiveness(double value);
	void setRewardMultiplier(int value);
    void setMutationRate(double value);
	SimType Type;
    double getMutationRate();
private:
	void Setup(SimType Type);
	int GoodMultiplierSetting = 2;
	int HistoryCount = 0;
    double GenerationForgiveness = 0.5f;
    double MutationRate = 0.05f;
    unsigned int Capacity;

};
