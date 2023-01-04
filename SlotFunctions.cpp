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

bool SlotFunctions::CheckGrid()
{
            int arr[15] = {};
            int index = 0;
            bool isTrio = false;
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    arr[index] = matrix[i][j];
                    index++;
                }
            }
            int n = sizeof(arr) / sizeof(arr[index]);

            for (int i = 0; i < n - 2; i += 3)
            {
                if (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2])
                {
                    isTrio = true;
                }
            }
            return isTrio;
};

void SlotFunctions::RandomizeGrid(){
        srand(time(0)); 
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {   
            matrix[i][j] = rand() % 5;
            }
        }
};

//Find and change balance values
int SlotFunctions::GetBalance(){
    return this->balance.value;
};

void SlotFunctions::SetBalance(int x){
    this->balance.value = x;

};

void SlotFunctions::SubtractBalance(int x){
    this->balance.value = GetBalance() - x;
};



//Find and change winnings values
int SlotFunctions::GetWinnings(){
    return this->winnings.value;
};

void SlotFunctions::SetWinnings(int x){
    this->winnings.value = x;

};

void SlotFunctions::AddWinnings(int x){
    this->winnings.value = GetWinnings() + x;
    this ->balance.value = GetBalance() + x;

};

void SlotFunctions::CheckWin()
{
    int arr[15] = {};
    int index = 0;
    int winnings = GetBet();
    int winning_row = 0;
    ostringstream temp;
    string win;

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
                AddWinnings(winnings);
                cout << "Congratulations, you won $" << GetBet() << " ! The winning values were: " /*<< ", on row " << winning_row + 1 */;
                cout << matrix[i][j] << matrix[i][j + 1] << matrix[i][j + 2] << " on row " << i + 1 << endl;
            }
            }
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
        bool isValidBet = false;
        cout << "Current Balance: $" << GetBalance() << endl;
        cout << "What amount would you like to bet?" << endl;
        do
        {

            getline(cin, bet);
            // cout << "Bet is: " << bet << " " << isValue(bet) << endl;

            if (isValue(bet))
            {
            int x;
            if (stoi(bet) >= MIN_BET)
            {
                isValidBet = true;
            }

            else
            {
                cout << "Amount must be greater than 1" << endl;
            }
            }
            else
            {
            cout << "Please enter a number." << endl;
            }
        } while (!isValidBet);
        SetBet(stoi(bet));
        SubtractBalance(stoi(bet));
        cout << "You have bet $" << GetBet() << ". Current Balance: $" << GetBalance() << endl;
};
