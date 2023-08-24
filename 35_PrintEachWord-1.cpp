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

void PrintEachWord(string TheString)
{
    bool IsFirstLetter = true;
    int Length = TheString.length();
    
    for (int i = 0; i < Length; i++)
    {
        if (TheString[i] != ' ' && IsFirstLetter)
        {
            cout << "\n" << TheString[i]; 
        }
        else {
            cout << TheString[i];
        }
        IsFirstLetter = TheString[i] == ' ' ? true : false;
    }
}
int main()
{
    PrintEachWord(ReadString());

}
