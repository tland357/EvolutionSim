#include <math.h>
#include "Syllabary.h"
#include <vector>
#include "MathBeing.h"
#include "sudokubeing.h"
#include "functionlibrary.h"
#include "Population.h"

using namespace std;


Population::Population() {}


Population::~Population() {
    ActorList.clear();
    SurvivorList.clear();
}


Population::Population(SimType type, double mutRate, double forgive, int rewardMult, unsigned int capacity) {
    MutationRate = mutRate;
    Capacity = capacity;
    Forgiveness = forgive;
    RewardMultiplier = rewardMult;
    Type = type;
    ActorList.clear();
    SurvivorList.clear();
    switch (Type) {
    case GENERAL:
        for (unsigned int i = 0; i < Capacity; i += 1) {
            ActorList.push_back(new Actor(genName(), MutationRate));
        }
        break;
    case MATH1:
        for (unsigned int i = 0; i < Capacity; i += 1) {
            ActorList.push_back(new MathBeing(genName(), MutationRate));
        }
        break;
    case MATH2:
        for (unsigned int i = 0; i < Capacity; i += 1) {
            ActorList.push_back(new MathBeing2(genName(), MutationRate));
        }
        break;
    case MATH3:
        break;
    case SUDOKU:
        for (unsigned int i = 0; i < Capacity; i += 1) {
            ActorList.push_back(new Sudoku(genName(), MutationRate));
        }
        break;
    }
}


void Population::sort() {
	bool directionToggle = true;
    unsigned int front = 0;
    unsigned int back = Capacity - 1;
    unsigned int lastSwap = 0;
	while (front < back) {
		if (directionToggle) {
            for (unsigned int x = front; x < back; x += 1) {
                if (!Actor::compare(ActorList[x], ActorList[x + 1])) {
					swap(x, x + 1);
					lastSwap = x;
				}
			}
			back = lastSwap;
			directionToggle = false;
		}
		else {
            for (unsigned int x = back; x > front; x -= 1) {
                if (Actor::compare(ActorList[x], ActorList[x - 1])) {
					swap(x, x - 1);
					lastSwap = x;
				}
			}
			front = lastSwap;
			directionToggle = true;
		}
	}
    BestCreature = ActorList[ActorList.size() - 1];
    MedianCreature = ActorList[ActorList.size() / 2];
    WorstCreature = ActorList[0];
}


void Population::swap(unsigned int i, unsigned int j) {
    Actor* temp = ActorList[i];
    ActorList[i] = ActorList[j];
	ActorList[j] = temp;
}


void Population::kill(double forgiveness) {
    survivorCounter = 0;
    SurvivorList.clear();
    switch (Type) {
    case GENERAL:
        for (unsigned int i = Capacity; i > 0 && survivorCounter < (Capacity / 2); i -= 1) {
            if (Functions::bernoulli(sig(i, forgiveness))) {
                SurvivorList.push_back(new Actor(genName(), ActorList[i - 1]));
                survivorCounter += 1;
            }
        }
        break;
    case MATH1:
        for (unsigned int i = Capacity; i > 0 && survivorCounter < (Capacity / 2); i -= 1) {
            if (Functions::bernoulli(sig(i, forgiveness))) {
                SurvivorList.push_back(new MathBeing(genName(), ActorList[i - 1]));
                survivorCounter += 1;
            }
        }
        break;
    case MATH2:
        for (unsigned int i = Capacity; i > 0 && survivorCounter < (Capacity / 2); i -= 1) {
            if (Functions::bernoulli(sig(i, forgiveness))) {
                SurvivorList.push_back(new MathBeing2(genName(), ActorList[i - 1]));
                survivorCounter += 1;
            }
        }
        break;
    case MATH3:
        break;
    case SUDOKU:
        for (unsigned int i = Capacity; i > 0 && survivorCounter < (Capacity / 2); i -= 1) {
            if (Functions::bernoulli(sig(i, forgiveness))) {
                SurvivorList.push_back(new Sudoku(genName(), ActorList[i - 1]));
                survivorCounter += 1;
            }
        }
        break;
    }
}


double Population::sig(unsigned int index, double forgiveness) {
	clamp01(forgiveness);
	forgiveFunc(forgiveness);
    double x = (index - (Capacity / 2) - 0.5f) / forgiveness;
    double r = pow(e, x) / (1 + pow(e, x));
    clamp01(r);
    return r;
}


void Population::clamp01(double& value) {
	if (value > 1)
		value = 1;
	else if (value < 0) {
		value = 0;
	}
}


void Population::forgiveFunc(double& forgiveness) {
	forgiveness = 1 - (99603 * forgiveness) + (199602 * forgiveness * forgiveness);
}


void Population::regen() {
    ActorList.clear();
    switch (Type) {
    case GENERAL:
        for (unsigned int i = 0; i < Capacity; i += 1) {
            if (i < SurvivorList.size()) {
                ActorList.push_back(SurvivorList[i]);
            }
            else {
                ActorList.push_back(new Actor(genName(), ActorList[i - SurvivorList.size()]));
            }
        }
        break;
    case MATH1:
        for (unsigned int i = 0; i < Capacity; i += 1) {
            if (i < SurvivorList.size()) {
                ActorList.push_back(SurvivorList[i]);
            }
            else {
                ActorList.push_back(new MathBeing(genName(), ActorList[i - SurvivorList.size()]));
            }
        }
        break;
    case MATH2:
        for (unsigned int i = 0; i < Capacity; i += 1) {
            if (i < SurvivorList.size()) {
                ActorList.push_back(SurvivorList[i]);
            }
            else {
                ActorList.push_back(new MathBeing2(genName(), ActorList[i - SurvivorList.size()]));
            }
        }
        break;
    case MATH3:
        break;
    case SUDOKU:
        for (unsigned int i = 0; i < Capacity; i += 1) {
            if (i < SurvivorList.size()) {
                ActorList.push_back(SurvivorList[i]);
            }
            else {
                ActorList.push_back(new Sudoku(genName(), ActorList[i - SurvivorList.size()]));
            }
        }
        break;
    }
}


string Population::genName() {
    unsigned int length = (rand() % 6) + 5;
    string name = "";
    for (unsigned int i = 0; i < length; i += 1) {
		if ((i & 1) == 0)
            name.push_back(consonants[rand() % 20]);
		else
            name.push_back(vowels[rand() % 5]);
	}
	return name;
}


void Population::Run() {
    for (unsigned int i = 0; i < Capacity; i += 1) {
        ActorList[i]->rewardUpdate();
	}
}
