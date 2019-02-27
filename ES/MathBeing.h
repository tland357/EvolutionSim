#pragma once
#include <string>
#include "Actor.h"

const int MAX_CALCS = 20;
const int FunctionCount = 12;

class MathBeingBody : ActorBody {
public:
    int InitialValue;
    vector<int> operations;
    int constant0;
    int constant1;
    int constant2;
    int constant3;
    int constant4;
    int constant5;
    int Length;
    void reset0();
    void printBody();
    MathBeingBody();
    double calc(double value, unsigned int operation);
    double Run();
    QString BodyPart(unsigned int i);
};


class MathBeing : public Actor {
public:
    MathBeing();
    MathBeing(string id, double mutRate);
    MathBeing(string id, Actor* M);
    virtual ~MathBeing() override;
	virtual void rewardUpdate() override;
    virtual QString toString() override;
    virtual QString toStringPopulation() override;
	virtual void printActor() override;
    virtual void Mutate() override;
    virtual QString toStringComprehensive() override;
    MathBeingBody Body;
};

class MathBeing2 : public MathBeing {
public:
    MathBeing2(string id, double mutRate);
    MathBeing2(string id, Actor* M);
    virtual ~MathBeing2() override;
    virtual void rewardUpdate() override;
    virtual QString toStringPopulation() override;
};
