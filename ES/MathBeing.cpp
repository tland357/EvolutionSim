#include <math.h>
#include "FunctionLibrary.h"
#include "MathBeing.h"


using namespace std;

MathBeing::MathBeing() {}

MathBeing::MathBeing(string id, float mutRate) {
    MutationRate = mutRate;
    ID = id;
    Body = MathBeingBody();
}

MathBeing2::MathBeing2(string id, float mutRate) {
    MutationRate = mutRate;
    ID = id;
    Body = MathBeingBody();
}

void MathBeing::Mutate() {
    bool changed = false;
    if (Functions::bernoulli(MutationRate)) {
        changed = true;
        if (Functions::bernoulli(0.5))
            Body.constant0 += 1;
        else
            Body.constant0 -= 1;
        if (Functions::bernoulli(MutationRate)) {
            Body.reset0();
        }
    }
    for (unsigned int i = 0; i < MAX_CALCS; i += 1) {
        if (Functions::bernoulli(MutationRate)) {
            Body.operations[i] = rand() % FunctionCount;
            changed = true;
        }
    }
    if (changed)
        nameChange();
}

MathBeing::MathBeing(string id, Actor* M) {
    ID = M->getID();
    MutationRate = dynamic_cast<MathBeing*>(M)->MutationRate;
    Reward = 0;
    Body = dynamic_cast<MathBeing*>(M)->Body;
    Mutate();
}

QString MathBeing::toString() {
    QString str = "Name: ";
    str += QString::fromStdString(ID);
    str += "\nScore: ";
    str += (Reward != 2147483647 ? QString::number(Reward): "Perfect Score!!!");
    return str;
}

QString MathBeing::toStringComprehensive() {
    QString str = "Name: " + QString::fromStdString(ID);
    rewardUpdate();
    str += "\nScore: " + (Reward != 2147483647 ? QString::number(Reward): "Perfect Score!!!");
    str += "\nBody: [v = 1] [c = " + QString::number(Body.constant0) + "] ";
    for (int i = 0; i < MAX_CALCS && Body.operations[i]; i += 1) {
        str += Body.BodyPart(i) + ((i % 6) == 0 ? "\n" : "");
    }
    return str;
}

QString MathBeing::toStringPopulation() {
    return "";
}

QString MathBeing2::toStringPopulation() {
    return "";
}

QString MathBeingBody::BodyPart(unsigned int i) {
    QString str = "(";
    switch (operations[i]){
    case 1:
        str += "v + c) ";
        break;
    case 2:
        str += "v * c) ";
        break;
    case 3:
        str += "v / c) ";
        break;
    case 4:
        str += "c) ";
        break;
    case 5:
        str += "-v) ";
        break;
    case 6:
        str += "v & c) ";
        break;
    case 7:
        str += "c * sin(v)) ";
        break;
    case 8:
        str += "2v) ";
        break;
    case 9:
        str += "-2v) ";
        break;
    case 10:
        str += "log_2(v)) ";
        break;
    case 11:
        str += "v * v) ";
        break;
    case 12:
        str += "v - c) ";
        break;
    default:
        return "";
    }
    return str;
}

MathBeing2::MathBeing2(string id, Actor* M) {
    ID = M->getID();
    MutationRate = dynamic_cast<MathBeing2*>(M)->MutationRate;
    Reward = 0;
    Body = dynamic_cast<MathBeing2*>(M)->Body;
    Mutate();
}

void MathBeing::rewardUpdate() {
    setReward(static_cast<float>(Body.Run()));
    printActor();
}

void MathBeing::printActor() {

}

MathBeing::~MathBeing() {}
MathBeing2::~MathBeing2() {}

void MathBeing2::rewardUpdate() {
    setReward(static_cast<float>(Body.Run()) / static_cast<float>(Body.Length));
    printActor();
}

MathBeingBody::MathBeingBody() {
	reset0();
    InitialValue = 1;
	for (int i = 0; i < MAX_CALCS; i += 1) {
        int x = rand() % FunctionCount;
        operations.push_back(x);
	}
}

void MathBeingBody::reset0() {
	constant0 = (rand() % 21) - 10;
}


int MathBeingBody::Run() {
	InitialValue = 1;
    for (int i = 0; i < MAX_CALCS && operations[i]; i += 1) {
        InitialValue = calc(InitialValue, operations[i]);
        Length = i;
	}
	return InitialValue;
}

int MathBeingBody::calc(int value, int operation) {
    switch (operation)
	{
	case 1:
        return value + constant0;
	case 2:
        return value * constant0;
	case 3:
		if (constant0 != 0)
            return value / constant0;
        return value;
	case 4:
        return constant0;
	case 5:
        return value * -1;
	case 6:
        return value & constant0;
	case 7:
        return ceilf(constant0 * sinf(value));
	case 8:
        return value << 1;
	case 9:
        return value * -2;
	case 10:
        if (value > 0)
            return ceilf(log2f(value));
        return value;
	case 11:
        return value * value;
	case 12:
        return value - constant0;
	default:
        return 1;
	}
}

void MathBeingBody::printBody() {

}
