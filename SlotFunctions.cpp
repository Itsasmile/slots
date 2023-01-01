#include "SlotFunctions.h"

using namespace std;

//Populates the initial matrix
void SlotFunctions::GetGrid(){
        {
        int matrix_value;
        srand(time(0));
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if(j > 0){
                    cout << " ";

                }
                matrix[i][j] = rand() % 10;

                cout << matrix[i][j];

                if (j < COLS - 1){
                    cout << ",";
                }
            }
            cout << endl;
      
        }
    }
};

void SlotFunctions::SetGrid(){
    GetGrid();

    
    
};


//Find and change balance values
int SlotFunctions::GetBalance(){
    return this->balance.value;
};

void SlotFunctions::SetBalance(int x){
    this->balance.value = x;

};
//Find and change winnings values
int SlotFunctions::GetWinnings(){
    return this->winnings.value;
};

void SlotFunctions::SetWinnings(int x){
    this->winnings.value = x;

};
//Find and change deposit values
int SlotFunctions::GetDeposit(){
    return this->deposit.value;
};

void SlotFunctions::SetDeposit(int x){
    this->deposit.value = x;

};
//Find and change bet values
int SlotFunctions::GetBet(){
    return this->bet_amount.value;
};

void SlotFunctions::SetBet(int x){
    this->bet_amount.value = x;

};

bool SlotFunctions::isValue(string x)
{
    for (int i = 0; i < x.length(); i++)
    {
        if (!isdigit(x[i]))
        {
            return false;
        }
    }
    return true;
};

void SlotFunctions::Spin()
{
    string x;
    bool isValidBet = false;
    cout << "What amount would you like to bet?" << endl;
    getline(cin, x);

    do
    {
        if (isValue(x))
        {

            if (stoi(x) >= MIN_BET)
            {
                isValidBet = true;
            }
            else
            {
                cout << "Amount must be greater than 1" << endl;
                cin >> x;
            }
        }
        else
        {
            cout << "Please enter a number." << endl;
            cin >> x;
        }
    } while (!isValidBet);
    SetBet(stoi(x));
    cout << "Your bet is $" << GetBet() << endl;

};


