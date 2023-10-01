#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
using namespace std; 

int Print3x3Matrix(int Matrix[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(3) << Matrix[i][j] << "    ";
        }
        cout << endl;
    }
}

bool CheckIdentity(int Matrix[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (i == j && Matrix[i][j] != 1)
            {
                return false;
            }
            else if (i !=j && Matrix[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{

    int Matrix[3][3] = {
        {1, 0, 0}, 
        {0, 1, 0},
        {0, 0, 1}
    };

    cout << "Matrix 1 is:\n";
    Print3x3Matrix(Matrix, 3, 3);
    
    if (CheckIdentity(Matrix, 3, 3))
    {
        cout << endl << "Is identity Matrix";
    }
    else cout << endl << "Is not an identity Matrix";
}