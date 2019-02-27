#include "functionlibrary.h"
#include "sudokubeing.h"

Sudoku::Sudoku(string id, double mutRate) {
    MutationRate = mutRate;
    ID = id;
    Body = SudokuBody();
}

Sudoku::Sudoku(string id, Actor* a) {
    MutationRate = dynamic_cast<Sudoku*>(a)->MutationRate;
    ID = a->getID();
    Body = dynamic_cast<Sudoku*>(a)->Body;
    Reward = 0;
    Mutate();
}

void Sudoku::Mutate() {
    if (Functions::bernoulli(MutationRate)) {
        nameChange();
        int i = rand() % 9;
        int j = rand() % 9;
        Body.BackingArray[i][j] = (rand() % 9) + 1;
    }
}

void Sudoku::rewardUpdate() {
    Reward = Body.Calc();
}

QString Sudoku::toString() {
    QString str = "Name: ";
    str += QString::fromStdString(ID);
    str += "\nScore: ";
    str += QString::number(Reward);
    return str;
}

QString Sudoku::toStringComprehensive() {
    QString str = "";
    for (int i = 0; i < 9; i += 1) {
        for (int j = 0; j < 9; j += 1) {
            str += QString::number(Body.BackingArray[i][j]) + " ";

        }
        if (i == 0) {
            str += "\t\tName: " + QString::fromStdString(ID);
        } else if (i == 1) {
            str += "\t\tScore: " + QString::number(Reward);
        } else if (i == 2) {
            str += "\t\tValid Rows: [ ";
            for (int i = 0; i < Body.rows.size(); i += 1) {
                str += QString::number(Body.rows[i]) + " ";
            }
            str += "]";
        } else if (i == 3) {
            str += "\t\tValid Columns: [ ";
            for (int i = 0; i < Body.columns.size(); i += 1) {
                str += QString::number(Body.columns[i]) + " ";
            }
            str += "]";
        } else if (i == 4) {
            str += "\t\tValid Sub-Regions: [ ";
            for (int i = 0; i < Body.subRegions.size(); i += 1) {
                str += QString::number(Body.subRegions[i]) + " ";
            }
            str += "]";
        }
        str += "\n";
    }
    return str;
}

SudokuBody::SudokuBody() {
    for (unsigned int i = 0; i < 9; i += 1) {
        for (unsigned int j = 0; j < 9; j += 1) {
            BackingArray[i][j] = (rand() % 9) + 1;
        }
    }
}

int SudokuBody::Calc() {
    rows.clear();
    columns.clear();
    subRegions.clear();
    int result = 0;
    bool intSet[9] = {false};
    bool flag = false;
    for (int i = 0; i < 9; i += 1) {
        int counter = 0;
        for (int j = 0; j < 9; j += 1) {
            if (!intSet[BackingArray[i][j] - 1]) {
                counter += 1;
                intSet[BackingArray[i][j] - 1] = true;
            }
            else {
                break;
            }
        }
        if (counter == 9) {
            result += 1;
            rows.push_back(i + 1);
        }
        resetSet(intSet);
    }
    for (int i = 0; i < 9; i += 1) {
        int counter = 0;
        for (int j = 0; j < 9; j += 1) {
            if (!intSet[BackingArray[j][i] - 1]) {
                counter += 1;
                intSet[BackingArray[j][i] - 1] = true;
            }
            else {
                break;
            }
        }
        if (counter == 9) {
            result += 1;
            columns.push_back(i + 1);
        }
        resetSet(intSet);
    }
    int counter2 = 1;
    for (int i = 0, j = 0; counter2 < 10; counter2 += 1) {
        int counter = 0;
        for (int x = i, y = j; y != j + 3;) {
            if (!intSet[BackingArray[x][y] - 1]) {
                counter += 1;
                intSet[BackingArray[x][y] - 1] = true;
            }
            else {
                break;
            }
            x += 1;
            if (x == i + 3) {
                x = i;
                y += 1;
            }
        }
        if (counter == 9) {
            result += 1;
            subRegions.push_back(counter2);
        }
        i += 3;
        if (i == 9) {
            i = 0;
            j += 3;
        }
        resetSet(intSet);
    }
    return result;
}

void SudokuBody::resetSet(bool x[9]) {
    for (int i = 0; i < 9; i += 1) {
        x[i] = false;
    }
}
