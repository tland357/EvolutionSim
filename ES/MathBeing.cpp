#include <math.h>
#include "FunctionLibrary.h"
#include "MathBeing.h"


using namespace std;

MathBeing::MathBeing() {}

MathBeing::MathBeing(string id, double mutRate) {
    MutationRate = mutRate;
    ID = id;
    Body = MathBeingBody();
}

MathBeing2::MathBeing2(string id, double mutRate) {
    MutationRate = mutRate;
    ID = id;
    Body = MathBeingBody();
}

void MathBeing::Mutate() {
    if (Functions::bernoulli(MutationRate)) {
        nameChange();
        if (Functions::bernoulli(1.0 / FunctionCount))
            Body.constant0 += Functions::bernoulli(0.5) ? 1 : -1;
        else {
            if (Functions::bernoulli(1.0 / 3.0)) {
                Body.operations[rand() % Body.operations.size()] = rand() % FunctionCount;
            } else {
                if (Functions::bernoulli(0.5)) {
                    if (Body.operations.size())
                        Body.operations.pop_back();
                    else
                        Body.operations.push_back(rand() % FunctionCount);
                } else {
                    if (Body.operations.size() < 20)
                        Body.operations.push_back(rand() % FunctionCount);
                    else
                        Body.operations.pop_back();
                }
            }

        }
    }
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
    str += QString::number(Reward);
    return str;
}

QString MathBeing::toStringComprehensive() {
    QString str = "Name: " + QString::fromStdString(ID);
    rewardUpdate();
    str += "\nScore: " + QString::number(Reward);
    str += "\nBody: [v = 1] [c = " + QString::number(Body.constant0) + "] ";
    for (int i = 0; i < Body.operations.size(); i += 1) {
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
        str += "c * sqrt(v)) ";
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
    setReward(Body.Run());
    printActor();
}

void MathBeing::printActor() {

}

MathBeing::~MathBeing() {}
MathBeing2::~MathBeing2() {}

void MathBeing2::rewardUpdate() {
    setReward(static_cast<double>(Body.Run()) / static_cast<double>(Body.Length + 1));
    printActor();
}

MathBeingBody::MathBeingBody() {
	reset0();
    InitialValue = 1;
	for (int i = 0; i < MAX_CALCS; i += 1) {
        int x = rand() % FunctionCount;
        if (x) {
            operations.push_back(x);
        } else {
            break;
        }
	}
}

void MathBeingBody::reset0() {
	constant0 = (rand() % 21) - 10;
}


double MathBeingBody::Run() {
    double val = 1;
    for (int i = 0; i < operations.size(); i += 1) {
        val = calc(val, operations[i]);
	}
    return val;
}

double MathBeingBody::calc(double value, unsigned int operation) {
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
        return constant0 * sqrt(value);
	case 7:
        return constant0 * sinf(value);
	case 8:
        return value * 2;
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
