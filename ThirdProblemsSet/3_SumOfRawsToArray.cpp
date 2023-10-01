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

int RawSum(int Matrix[3][3], short RawNum, short Columns)
{
    int Sum = 0;
    for (short i = 0; i < Columns; i++)
    {
        Sum+= Matrix[RawNum][i];
    }
    return Sum;
}

void SumRawToArray(int Matrix[3][3], short Raws, short Columns, int ArrSum[3])
{
    for (int i = 0; i < Raws; i++)
    {
        ArrSum[i] = RawSum(Matrix, i, Columns);
    }
}

void PrintSumOfRawArray(int ArrSum[3], short Raws)
{
    for (int i = 0; i < Raws; i++)
    {
        cout << "Raw No." << i + 1 << " sum is : " << ArrSum[i] << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];
    int ArrSum[3];
    cout << "The following is a 3x3 random Matrix: \n";
    Fill3x3MatrixRandom(Matrix, 3, 3);
    Print3x3Matrix(Matrix, 3, 3);
    SumRawToArray(Matrix, 3, 3, ArrSum);
    PrintSumOfRawArray(ArrSum, 3);
}