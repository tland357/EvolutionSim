//#include "MathBeing.h"
//#include <iostream>
//#include "functionlibrary.h"
//#include "MathPopulation.h"

//using namespace std;

//MathPop::MathPop() {

//}

//MathPop::MathPop(float mutRate, float forgive, int rewardMult, unsigned int capacity) {
//    MutationRate = mutRate;
//    Forgiveness = forgive;
//    RewardMultiplier = rewardMult;
//    Capacity = capacity;
//    for (unsigned int i = 0; i < Capacity; i += 1) {
//        cout << i << ": ";
//        ActorList[i] = MathBeing(genName(), mutRate);
//    }
//    cout << "Math1 Population Generation Successful!" << endl;
//}

//void MathPop::regen() {
//    for (unsigned int i = 0; i < survivorCounter; i += 1) {
//        ActorList[i] = SurvivorList[i];
//    }
//    for (unsigned int i = survivorCounter; i < Capacity; i += 1) {
//        ActorList[i] = MathBeing(genName(), ActorList[i - survivorCounter]);
//    }
//}

//MathPop::~MathPop() {

//}

//void MathPop2::regen() {
//    for (unsigned int i = 0; i < survivorCounter; i += 1) {
//        ActorList[i] = SurvivorList[i];
//    }
//    for (unsigned int i = survivorCounter; i < Capacity; i += 1) {
//        ActorList[i] = MathBeing2(genName(), ActorList[i - survivorCounter]);
//    }
//}

//MathPop2::MathPop2() {
//}

//MathPop2::~MathPop2() {
//}

//MathPop2::MathPop2(float mutRate, float forgive, int rewardMult, unsigned int capacity) {
//    MutationRate = mutRate;
//    Forgiveness = forgive;
//    RewardMultiplier = rewardMult;
//    Capacity = capacity;
//    for (unsigned int i = 0; i < Capacity; i += 1) {
//        cout << i << ": ";
//        ActorList[i] = MathBeing2(genName(), mutRate);
//    }
//    cout << "Population Generation Successful!" << endl;
//}
