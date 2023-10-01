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

 string CapitalLetters(string TheString)
{
    int Length = TheString.length();
    
    for (int i = 0; i < Length; i++)
    {
        TheString[i] = toupper(TheString[i]);
    }
    return TheString;
}

string SmallLetters(string& TheString)
{
    int Length = TheString.length();
    
    for (int i = 0; i < Length; i++)
    {
        TheString[i] = tolower(TheString[i]);
    }
    return TheString;
}

int main()
{
    string TheString = ReadString();
    cout << "Capital: ";
    cout << CapitalLetters(TheString) << endl;
    cout << "Small: ";
    cout << SmallLetters(TheString) << endl;
}