#pragma once
#include <random>
#include "Actor.h"
#include "simtype.h"
#include <string>

using namespace std;
const int MAX_CAPACITY = 1000;
const double e = 2.718282;


class Population {
public:
    vector<Actor*> ActorList;
    vector<Actor*> SurvivorList;
    Population();
    virtual ~Population();
    Population(SimType type, double mutRate, double forgive, int rewardMult, unsigned int capacity);
    void sort();
    virtual void kill(double forgiveness);
    virtual void regen();
    static string genName();
    void Run();
    double MutationRate;
    double Forgiveness;
    int RewardMultiplier;
    Actor* BestCreature;
    Actor* MedianCreature;
    Actor* WorstCreature;
protected:
    void swap(unsigned int i, unsigned int j);
    double sig(unsigned int index, double forgiveness);
    void forgiveFunc(double& forgiveness);
    std::knuth_b rand_engine;
    void clamp01(double& value);
    unsigned int Capacity;
    unsigned int survivorCounter;
    SimType Type;
};
