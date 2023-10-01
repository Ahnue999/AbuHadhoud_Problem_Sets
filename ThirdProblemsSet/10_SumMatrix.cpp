#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
using namespace std; 

int RandomNumber(int from, int to)
{
    int random = rand() % (to - from + 1) + from;
    return random;
}

int Fill3x3MatrixRandom(int Matrix[3][3], short Rows, short columns)
{
    for (int i = 0; i < Rows
; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            Matrix[i][j] = RandomNumber(0, 9);
        }
    }
}

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

int SumOfMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int Sum = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Sum += Matrix[i][j];
        }
    }
    return Sum;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];
    cout << "The following is a 3x3 random Matrix: \n";
    Fill3x3MatrixRandom(Matrix, 3, 3);
    Print3x3Matrix(Matrix, 3, 3);
    cout << "\nThe Sum of this Matrix is : " << SumOfMatrix(Matrix, 3, 3);
}