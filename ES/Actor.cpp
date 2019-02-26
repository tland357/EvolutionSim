#include "Population.h"
#include "Syllabary.h"
#include "Actor.h"

using namespace std;

Actor::Actor() {

}

string Actor::getID() {
	return ID;
}

Actor::Actor(string id, float mutRate) {
    MutationRate = mutRate;
	ID = id;
}

Actor::Actor(string id, Actor* a) {
	ID = id;
}

Actor::~Actor() {}

float Actor::getReward() {
	return Reward;
}

void Actor::setReward(float reward) {
	Reward = reward;
}

void Actor::setID(string id) {
    ID = id;
}

void Actor::rewardUpdate() {
	Reward = 0;
}

bool Actor::compare(Actor* ac1, Actor* ac2) {
    return (ac2->getReward() > ac1->getReward());
}

void Actor::printActor() {

}

void Actor::nameChange() {
    int x = rand() % ID.length();
    if (x < 0) {
        x += ID.length();
    }
    if ((x & 1) == 0) {
        ID[x] = consonants[rand() % 20];
    }
    else {
        ID[x] = vowels[rand() % 5];
    }
}

void Actor::Mutate() {

}

QString Actor::toString() {
    return QString::fromStdString(ID);
}

QString Actor::toStringComprehensive() {
    return QString::fromStdString(ID);
}

QString Actor::toStringPopulation() {
    return "Generic Creature";
}
