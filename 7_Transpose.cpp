#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std; 

int Fill3x3MatrixOredered(int Matrix[3][3], short raws, short columns)
{
    int counter = 0;
    for (int i = 0; i < raws; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            counter++;
            Matrix[i][j] = counter;
        }
    }
}

void Transpose(int Matrix1[3][3], int Matrix2[3][3], short raws, short columns)
{
    for (int i = 0; i < raws; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            Matrix2[i][j] = Matrix1[j][i];
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

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];
    int Transposed[3][3];
    cout << "The following is a 3x3 Ordered Matrix: \n";
    Fill3x3MatrixOredered(Matrix, 3, 3);
    Print3x3Matrix(Matrix, 3, 3);

    Transpose(Matrix, Transposed, 3, 3);
    cout << "The following is a 3x3 transposed Matrix: \n";
    Print3x3Matrix(Transposed, 3, 3);
}