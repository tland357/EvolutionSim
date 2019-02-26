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
    Simulation(SimType type, float mutRate, float forgive, int rewardMult, unsigned int Capacity);
	~Simulation();
    Population CurrentPopulation;
    //Population Math3Pop;
	void GenerationRun();
	void GenerationSort();
    void BMWCreatures(Actor* Worst, Actor* Middle, Actor* Best);
	void GenerationKill();
	void GenerationRegen();
	void setForgiveness(float value);
	void setRewardMultiplier(int value);
	void setMutationRate(float value);
	SimType Type;
	float getMutationRate();
private:
	void Setup(SimType Type);
	int GoodMultiplierSetting = 2;
	int HistoryCount = 0;
    float GenerationForgiveness = 0.5f;
    float MutationRate = 0.05f;
    unsigned int Capacity;

};
