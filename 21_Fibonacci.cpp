#include <iostream>
using namespace std;

void PrintFibonacci(int Length)
{
    long int Previous1 = 0;
    long int Previous2 = 1;
    long int temp = 0;

    for (int i = 0; i < Length; i++)
    {
        cout << Previous2 << "  ";
        temp = Previous2;        
        Previous2 += Previous1;
        Previous1 = temp;
    }
}

int main()
{
    PrintFibonacci(30);
}