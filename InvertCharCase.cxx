#include <iostream>
#include <ctype.h>
using namespace std;

char ReadChar()
{
    char TheChar;
    cout << "Enter a character\n";
    cin >> TheChar;
    return TheChar;
}

 char InvertCharCase(char TheChar)
 {
     return isupper(TheChar) ? tolower(TheChar) : toupper(TheChar);
 }

int main()
{
    char TheChar = ReadChar();
    
    cout << InvertCharCase(TheChar) << endl;
}
