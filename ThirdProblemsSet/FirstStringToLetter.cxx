#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

string ReadString()
{
    string TheString;
    cout << "Enter a string\n";
    getline(cin, TheString);
    return TheString;
}

 string CapitalFirstLetter(string& TheString)
{
    bool IsFirstLetter = true;
    int Length = TheString.length();
    
    for (int i = 0; i < Length; i++)
    {
        if (TheString[i] != ' ' && IsFirstLetter)
        {
            TheString[i] = toupper(TheString[i]);
        }
        IsFirstLetter = TheString[i] == ' ' ? true : false;
    }
    return TheString;
}

int main()
{
    string TheString = ReadString();
    CapitalFirstLetter(TheString);
    cout << TheString;
}