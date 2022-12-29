#include <string>
#include <iostream>
#include <ctype.h>
#include <limits>

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
        //balance = {};
        // deposit = {};
        // winnings = {};
        // bet_amount = {};
    }

    int matrix[ROWS][COLS] = {}; // will this reset the instance everytime i create an object?

    void GetGrid();
    void SetGrid();

    int GetBalance();
    void SetBalance(int x);

    int GetWinnings();
    void SetWinnings(int x);

    int GetDeposit();
    void SetDeposit(int x);

    int GetBet();
    void SetBet(int x); 

    void Spin();
    void Game();
    
    bool isValue(string x);


};
//int SlotFunctions::matrix[ROWS][COLS];


