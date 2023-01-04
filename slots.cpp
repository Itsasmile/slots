#include "SlotFunctions.cpp"

using namespace std;

int main()
{
    int value;
    int deposit;
    
    string game;
    bool endGame = false;

    SlotFunctions SlotFunction;
    cout << SlotFunction.isValue("\r") << endl;
    cout << "Welcome to the casino, your starting balance is: $" << SlotFunction.GetBalance() << ", please input an amount to deposit into your wallet." << endl;
    cin >> deposit;
    SlotFunction.SetDeposit(deposit);
    cout << "You have deposited $" << SlotFunction.GetDeposit() << " into your wallet." << endl;
    do{
    SlotFunction.Spin();
    SlotFunction.PrintGrid();
    SlotFunction.CheckGrid();
    SlotFunction.CheckWin();
    cout << "Hit e to continue playing, otherwise hit anything else to end the game" << endl;
    cin >> game;

    if (game == "e"){
        /// cin.ignore();
        // endGame = false;
        SlotFunction.RandomizeGrid();
    }
    else
    {
        cout << "Exiting game......." << endl;
        break;
    }

    }while (!endGame);
    // //SlotFunction.Spin();
    // cout << "You are depositing: $" << SlotFunction.GetDeposit() << endl;
    // cout << "Your bet is: $" << SlotFunction.GetBet() << endl;
    // cout << "You have won: $" << SlotFunction.GetWinnings() << endl;
    // cout << "Testing set balance, input a value: " << endl;
    // cin >> value;
    // SlotFunction.SetBalance(value);
    // cout << "Your current balance is: $" << SlotFunction.GetBalance() << endl;
    // SlotFunction.GetGrid();

}