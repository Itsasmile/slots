#include "functions.h"

using namespace std;

void SlotFunctions::GetGrid(){
        {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                cout << " " << matrix[i][j] << ",";
            }
            cout << endl;
        }
    }
};