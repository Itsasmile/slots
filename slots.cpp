#include "SlotFunctions.cpp"
#include <string>
#include <iostream>
#include <ctype.h>
#include <limits>
#include <time.h>
#include <array>
#include <sstream>

using namespace std;

int main()
{
	int value;
	string deposit;

	string game;
	bool endGame = false;

	SlotFunctions SlotFunction;
	cout << "Welcome to the casino, your starting balance is: $" << SlotFunction.GetBalance() << ", please input an amount to deposit into your wallet." << endl;
	getline(cin, deposit);
	SlotFunction.SetDeposit(stoi(deposit));
	cout << "You have deposited $" << SlotFunction.GetDeposit() << " into your wallet." << endl;
	do
	{
		SlotFunction.Spin();
		SlotFunction.PrintGrid();
		cout << endl;
		SlotFunction.CheckWin();
		cout << "Hit e to continue playing, otherwise hit anything else to end the game." << endl;
		getline(cin, game);

		if (game == "e")
		{
			SlotFunction.RandomizeGrid();
		}
		else
		{
			cout << "\nExiting game......." << endl;
			cout << "Game has ended. You left with a balance of: $" << SlotFunction.GetBalance() << endl;
			endGame = true;
		}

	} while (!endGame);
}