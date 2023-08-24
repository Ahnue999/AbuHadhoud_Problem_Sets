
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
using namespace std;

int Print3x3Matrix(int Matrix[3][3], short raws, short columns)
{
    for (int i = 0; i < raws; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << setw(3) << Matrix[i][j] << "    ";
        }
        cout << endl;
    }
}

bool IsPalindromeMatrix(int Matrix[3][3], int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if ( Matrix[i][j] != Matrix[i][(Cols - 1) - j] )            
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
        {3, 14, 3},
        {1, 15, 1},
        {42, 4, 42}
    };
    cout << "The following is a 3x3 Matrix: \n";
    Print3x3Matrix(Matrix, 3, 3);

    if(IsPalindromeMatrix(Matrix, 3, 3))
    {
        cout << "\nThis matrix is palindrome";
    }
    else 
    {
        cout << "\nThis matrix isn't palindrome";
    }
}