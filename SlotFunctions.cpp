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

bool SlotFunctions::SetGrid()
{
            // Loop through matrix compare every trio of numbers, if equal

            /*
                1    |     2    |    3    |    4    |    5
                6    |     7    |    8    |    9   |    10
                11    |     12    |    13    |    14    |    15
                matrix[0][0]
                matrix[0][3]
            */
            int arr[15] = {};
            int index = 0;
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    arr[index] = matrix[i][j];
                    index++;
                }
            }

            for (int i = 0; i < 15; i++)
            {
                cout << arr[i];
            }

            if (arr[0] == arr[1] && arr[1] == arr[2])
            {
                return true;
            }
            else
            {
                return false;
            }
};

void SlotFunctions::RandomizeGrid(){
        srand(time(0)); 
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {   
            matrix[i][j] = rand() % 10;
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


