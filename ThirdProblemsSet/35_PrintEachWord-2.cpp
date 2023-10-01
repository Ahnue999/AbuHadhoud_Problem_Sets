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
    string Delim = " ";
    int pos = 0;
    string Word;
    while ((pos = TheString.find(Delim)) != std::string::npos) {
        Word = TheString.substr(0, pos);
        if (Word != " ") {
            cout << Word << endl;
        }
        TheString.erase(0, (pos + Delim.length()));
    }
    if (TheString != " ") {
        cout << TheString;
    }
}
int main()
{
    PrintEachWord("Hi There How Are You");

}
