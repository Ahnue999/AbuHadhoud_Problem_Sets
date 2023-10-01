#include <iostream>
#include <string.h>
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

 int CountLetter(string TheString, char ToCount)
 {
     int count = 0;
     int Length = TheString.length();
     
     for (int i = 0; i < Length; i++)
     {
         if (TheString[i] == ToCount) {
             count++;
         }
     }
     return count;
 }

char ReadChar()
{
    char TheChar;
    cout << "Enter a character\n";
    cin >> TheChar;
    return TheChar;
}

int main()
{
    string TheString = ReadString();
    char ToCount = ReadChar();
    
    cout <<"\'"<< ToCount << "\' was found " << CountLetter(TheString, ToCount) << " times ";
}