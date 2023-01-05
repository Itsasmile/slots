#include "SlotFunctions.h"
#include <vector>


using namespace std;

//Populates the initial matrix
void SlotFunctions::PrintGrid(){
        {
        srand(time(0));
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if(j > 0){
                    cout << " ";
                }
                //RandomizeGrid();
                cout << matrix[i][j];

                if (j < COLS - 1){
                    cout << ",";
                }
            }
            cout << endl;
      
        }     
    }

};

void SlotFunctions::RandomizeGrid()
{
            srand(time(0));
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    matrix[i][j] = rand() % 5;
                }
            }
};

// Find and change balance values
int SlotFunctions::GetBalance()
{
            return this->balance.value;
};

void SlotFunctions::AddBalance(int x)
{
            this->balance.value = GetBalance() + x;
};

void SlotFunctions::SubtractBalance(int x)
{
            this->balance.value = GetBalance() - x;
};

// Find and change winnings values
int SlotFunctions::GetWinnings()
{
            return this->winnings.value;
};

void SlotFunctions::SetWinnings(int x)
{
            this->winnings.value = x;
};

void SlotFunctions::AddWinnings(int x)
{
            this->balance.value += (GetBet() * 2);
};

void SlotFunctions::CheckWin()
{
            int arr[15] = {};
            int index = 0;
            int winnings = GetBet();
            bool won = false;

            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    arr[index] = matrix[i][j];
                    index++;
                }
            }
            int n = sizeof(arr) / sizeof(arr[index]);

            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS - 2; j++)
                {
                    if (matrix[i][j] == matrix[i][j + 1] && matrix[i][j + 1] == matrix[i][j + 2]) // add a loop maybe, and add each group of values to a row, to print the winning row.
                    {
                        won = true;
                        SetWinnings(winnings);
                        AddWinnings(winnings);
                        cout << "Congratulations, you won $" << (GetBet() * 2) << "! The winning values were: ";
                        cout << matrix[i][j] << matrix[i][j + 1] << matrix[i][j + 2] << " on row " << i + 1 << "." << endl;
                    }
                }
            }
            if (!won)
            {
                cout << "You lost! Better luck next time!" << endl;
            }
};

//Find and change deposit values
int SlotFunctions::GetDeposit(){
    return this->deposit.value;
};

void SlotFunctions::SetDeposit(int x){
    this->deposit.value = GetBalance() + x;
    this->balance.value = GetBalance() + x;

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
    if (x.length() < 1)
            return false;

    for (int i = 0; i < x.length(); i++)
    {
            if (isdigit(x[i]) == 0)
            {
            return false;
            }
    }
    return true;
};

void SlotFunctions::Spin()
{
    string bet;
    string exitGame;
    bool isValidBet = false;
    cout << "\nCurrent Balance: $" << GetBalance() << "." << endl;
    cout << "What amount would you like to bet?" << endl;
    do
    {

            getline(cin, bet);

            // cout << "Bet is: " << bet << " " << isValue(bet) << endl; // Testing the function.
            if (bet == "q")
            {
            exit(0);
            }
            if (bet == "a")
            {
            cout << "How much money would you like to add to your wallet?" << endl;
            cin >> bet;
            if (isValue(bet))
            {
                AddBalance(stoi(bet));
                cout << "You have added $" << bet << " to your balance. Your new balance is: $" << GetBalance() << "." << endl;
                continue;
            }
            }

            if (!isValue(bet))
            {
            cout << "Please enter a number." << endl;
            continue;
            }

            if (stoi(bet) >= MIN_BET)
            {
            if (GetBalance() - stoi(bet) < 0)
            {
                cout << "You have insufficient funds for this bet. Your current balance is: $" << GetBalance() << ". Press a to add funds or press q to end game." << endl;
                continue;
            }

            isValidBet = true;
            }

            else
            {
            cout << "Amount must be greater than 1." << endl;
            }

    } while (!isValidBet);

    SetBet(stoi(bet));
    SubtractBalance(stoi(bet));
    cout << "\nYou have bet $" << GetBet() << ". Current balance: $" << GetBalance() << endl;
};
