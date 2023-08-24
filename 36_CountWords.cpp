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

int CountWords(string TheString)
{
    int count = 0;
    string Delim = " ";
    int pos = 0;
    string Word;
    while ((pos = TheString.find(Delim)) != std::string::npos) {
        Word = TheString.substr(0, pos);
        if (Word != " ") {
            count++;
        }
        TheString.erase(0, (pos + Delim.length()));
    }
    if (TheString != " ") {
        count++;
    }
    return count;
}
int main()
{
    cout << "There are " << CountWords(ReadString()) << " Words in your string";

}
