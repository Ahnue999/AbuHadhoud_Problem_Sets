#include <iostream>
#include <ctype.h>
using namespace std;

char InvertCharCase(char TheChar)
 {
     return isupper(TheChar) ? tolower(TheChar) : toupper(TheChar);
 }
 
string ReadString()
{
    string TheString;
    cout << "Enter a string\n";
    getline(cin, TheString);
    return TheString;
}

 string InvertStringCase(string TheString)
{
    int Length = TheString.length();
    
    for (int i = 0; i < Length; i++)
    {
        TheString[i] = InvertCharCase(TheString[i]);
    }
    return TheString;
}

int main()
{
    string TheString = ReadString();
    
    cout << InvertStringCase(TheString) << endl;
}
