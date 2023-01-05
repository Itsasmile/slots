#include "SlotFunctions.cpp"

using namespace std;

int main()
{
    int value;
    int deposit;

    string game;
    bool endGame = false;

    SlotFunctions SlotFunction;
    cout << "Welcome to the casino, your starting balance is: $" << SlotFunction.GetBalance() << ", please input an amount to deposit into your wallet." << endl;
    cin >> deposit;
    SlotFunction.SetDeposit(deposit);
    cout << "You have deposited $" << SlotFunction.GetDeposit() << " into your wallet." << endl;
    do
    {
        SlotFunction.Spin();
        SlotFunction.PrintGrid();
        cout << endl;
        SlotFunction.CheckWin();
        cout << "Hit e to continue playing, otherwise hit anything else to end the game." << endl;
        cin >> game;

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