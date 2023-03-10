#include <string>
#include <iostream>
#include <ctype.h>
#include <limits>
#include <time.h>
#include <array>
#include <sstream>

#pragma once

using namespace std;

const int ROWS = 3;
const int COLS = 5;
const int MIN_BET = 1;
const int ARRAY_SIZE = ROWS * COLS;

struct SlotsValue
{
	int value = {};
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
		RandomizeGrid();
	}

	int matrix[ROWS][COLS] = {}; // will this reset the instance everytime i create an object?

	void PrintGrid();
	void RandomizeGrid();

	int GetBalance();
	void AddBalance(int x);
	void SubtractBalance(int x);

	int GetWinnings();
	void SetWinnings(int x);
	void AddWinnings(int x);
	void CheckWin();

	int GetDeposit();
	void SetDeposit(int x);

	int GetBet();
	void SetBet(int x);

	void Spin();

	bool isValue(string x);
};
