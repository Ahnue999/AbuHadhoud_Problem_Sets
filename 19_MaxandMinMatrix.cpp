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

int FindMaxMatrix(int Matrix[3][3], int Rows, int Cols)
{
    int Max = Matrix[0][0];
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Max < Matrix[i][j])
            {
                Max = Matrix[i][j];
            }
        }
    }
    return Max;
}

int FindMinMatrix(int Matrix[3][3], int Rows, int Cols)
{
    int Min = Matrix[0][0];
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Min > Matrix[i][j])
            {
                Min = Matrix[i][j];
            }
        }
    }
    return Min;
}
int main()
{

    int Matrix[3][3] = {{3, 14, 61}, {12, 15, 1}, {92, 4, 52}};
    cout << "The following is a 3x3 Matrix: \n";
    Print3x3Matrix(Matrix, 3, 3);

    cout << "\nMax is : " << FindMaxMatrix(Matrix, 3, 3) << endl;;
    cout << "\nMin is : " << FindMinMatrix(Matrix, 3, 3) << endl;;
}