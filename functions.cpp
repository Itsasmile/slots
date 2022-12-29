#include "functions.h"

using namespace std;

//Populates the initial matrix
void SlotFunctions::GetGrid(){
        {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if(j > 0){
                    cout << " ";

                }

                cout << matrix[i][j];

                if (j < COLS - 1){
                    cout << ",";
                }
            }
            cout << endl;
      
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
    this->balance.value = x;

};
//Find and change deposit values
int SlotFunctions::GetDeposit(){
    return this->deposit.value;
};

void SlotFunctions::SetDeposit(int x){
    this->balance.value = x;

};
//Find and change bet values
int SlotFunctions::GetBet(){
    return this->bet_amount.value;
};

void SlotFunctions::SetBet(int x){
    this->balance.value = x;

};




