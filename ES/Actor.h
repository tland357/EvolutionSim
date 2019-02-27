#pragma once
#include <stdlib.h>
#include <string>
#include <QString>
#include <random>

using namespace std;

class Actor {
public:
	//default constructor. do not call!
    Actor();

	//constructor for generating a new actor
    Actor(string id, double mutRate);

	//constructor which reproduces one actor from another
    Actor(string id, Actor* a);
    virtual ~Actor();

    string getID();
    void setID(string id);
    void setReward(double reward);
    double getReward();

	//updates the current value of the reward. Overridable
	virtual void rewardUpdate();
	virtual void printActor();
    virtual QString toString();
    virtual QString toStringComprehensive();
    virtual QString toStringPopulation();
    virtual void Mutate();

	//returns true if second argument is larger than the first
    static bool compare(Actor* ac1, Actor* ac2);
    double getMutationRate();
protected:
    double Reward;
    double MutationRate;
    string ID;
    void nameChange();
};

//stores information for an actor
class ActorBody {

};
