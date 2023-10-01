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

int Fill3x3MatrixRandom(int Matrix[3][3], short raws, short columns)
{
    for (int i = 0; i < raws; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            Matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

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

int ColSum(int Matrix[3][3], short Raws, short ColNum)
{
    int Sum = 0;
    for (short i = 0; i < Raws; i++)
    {
        Sum+= Matrix[i][ColNum];
    }
    return Sum;
}
void PrintSumOfCols(int Matrix[3][3], short Raws, short Columns)
{
    for (int i = 0; i < Columns; i++)
    {
        cout << "Column No." << i + 1 << " sum is : " << ColSum(Matrix, Raws, i) << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];
    cout << "The following is a 3x3 random Matrix: \n";
    Fill3x3MatrixRandom(Matrix, 3, 3);
    Print3x3Matrix(Matrix, 3, 3);
    PrintSumOfCols(Matrix, 3, 3);
}