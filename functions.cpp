#include "functions.h"

using namespace std;

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

int SlotFunctions::GetBalance(){
    return balance.value;
};

int SlotFunctions::GetWinnings(){
    return winnings.value;
};

int SlotFunctions::GetDeposit(){
    return deposit.value;
};

int SlotFunctions::GetBet(){
    return bet_amount.value;
};
