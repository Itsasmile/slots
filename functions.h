#include <string>
#include <iostream>

#pragma once

using namespace std;

const int ROWS = 3;
const int COLS = 5;
const int MIN_BET = 1;


struct SlotsValue
{
    int value;
};

class SlotFunctions
{
private:
    static SlotsValue deposit;
    static SlotsValue balance;
    static SlotsValue winnings;
    static SlotsValue bet_amount;

public:
    static int matrix[ROWS][COLS];
    static void GetGrid();
};

int SlotFunctions::matrix[ROWS][COLS];
