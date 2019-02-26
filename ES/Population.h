#pragma once
#include <random>
#include "Actor.h"
#include "simtype.h"
#include <string>

using namespace std;
const int MAX_CAPACITY = 1000;
const float e = 2.718282f;


class Population {
public:
    vector<Actor*> ActorList;
    vector<Actor*> SurvivorList;
    Population();
    virtual ~Population();
    Population(SimType type, float mutRate, float forgive, int rewardMult, unsigned int capacity);
    void sort();
    virtual void kill(float forgiveness);
    virtual void regen();
    static string genName();
    void Run();
    float MutationRate;
    float Forgiveness;
    int RewardMultiplier;
    Actor* BestCreature;
    Actor* MedianCreature;
    Actor* WorstCreature;
protected:
    void swap(unsigned int i, unsigned int j);
    float sig(unsigned int index, float forgiveness);
    void forgiveFunc(float& forgiveness);
    std::knuth_b rand_engine;
    void clamp01(float& value);
    unsigned int Capacity;
    unsigned int survivorCounter;
    SimType Type;
};
