#include "functions.cpp"

using namespace std;

int main()
{
    SlotFunctions SlotFunction;
    cout << "This is a slot machine." << endl
         << endl;
    cout << "You are depositing: $" << SlotFunction.GetDeposit() << endl;
    cout << "Your bet is: $" << SlotFunction.GetBet() << endl;
    cout << "You have won: $" << SlotFunction.GetWinnings() << endl;
    cout << "Your current balance is: $" << SlotFunction.GetBalance() << endl;

    SlotFunction.GetGrid();
}