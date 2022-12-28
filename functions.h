#include <string>
#include <iostream>

#pragma once

using namespace std;

const int ROWS = 3;
const int COLS = 5;
const int MIN_BET = 1;

struct SlotsValue
{
    int value ={};
};

class SlotFunctions
{
private:
    SlotsValue deposit;
    SlotsValue balance;
    SlotsValue winnings;
    SlotsValue bet_amount;

public:
    SlotFunctions()
    {
        // balance = {};
        // deposit = {};
        // winnings = {};
        // bet_amount = {};
    }

    int matrix[ROWS][COLS] = {}; // will this reset the instance everytime i create an object?
    void GetGrid();
    int GetBalance();
    int GetWinnings();
    int GetDeposit();
    int GetBet();

};
//int SlotFunctions::matrix[ROWS][COLS];


