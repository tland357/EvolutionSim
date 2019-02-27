#pragma once
#include "Actor.h"

using namespace std;

class SudokuBody {
public:
    SudokuBody();
    int BackingArray[9][9];
    int Calc();
    vector<int> rows;
    vector<int> columns;
    vector<int> subRegions;
private:
    void resetSet(bool x[9]);
};

class Sudoku : public Actor {
public:
    Sudoku(string id, double mutRate);
    Sudoku(string id, Actor* a);
    SudokuBody Body;
    virtual void Mutate() override;
    virtual void rewardUpdate() override;
    virtual QString toString() override;
    virtual QString toStringComprehensive() override;
};
