#include "functions.cpp"

using namespace std;

int main()
{
    SlotFunctions SlotFunction;
    cout << "This is a slot machine." << endl
         << endl;
    cout << "Your current balance is: " << SlotFunction.GetBalance() << endl;

    SlotFunction.GetGrid();
}