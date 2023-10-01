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
    for (int i = 0; i < Rows; i++)
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

bool CheckTypical(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] != Matrix2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];
    int Matrix2[3][3];
    cout << "The following is a 3x3 random Matrix: \n";

    Fill3x3MatrixRandom(Matrix1, 3, 3);
    cout << "Matrix 1 is:\n";
    Print3x3Matrix(Matrix1, 3, 3);
    Fill3x3MatrixRandom(Matrix2, 3, 3);
    cout << "\nMatrix 2 is:\n";
    Print3x3Matrix(Matrix2, 3, 3);

    if (CheckTypical(Matrix1, Matrix2, 3, 3))
    {
        cout << "\nThey are Typical\n";
    }
    else 
    {
        cout << "\nThey are not Typical\n";
    }
}