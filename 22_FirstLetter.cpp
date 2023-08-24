#include <iostream>
#include <string.h>
using namespace std;

string ReadString()
{
    string TheString;
    cout << "Enter a string\n";
    getline(cin, TheString);
    return TheString;
}

void PrintFirstLetter(string TheString)
{
    bool IsFirstLetter = true;
    int Length = TheString.length();
    
    for (int i = 0; i < Length; i++)
    {
        if (TheString[i] != ' ' && IsFirstLetter)
        {
            cout << TheString[i] << ' ';
        }
        IsFirstLetter = TheString[i] == ' ' ? true : false;
    }
}
int main()
{
    PrintFirstLetter(ReadString());
}
