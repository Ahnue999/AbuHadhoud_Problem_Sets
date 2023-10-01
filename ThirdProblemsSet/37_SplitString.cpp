#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

string ReadString()
{
    string TheString;
    cout << "Enter a string\n";
    getline(cin, TheString);
    return TheString;
}

vector<string> Split(string TheString, string Delim = " ")
{
    vector<string> vWords;
    int count = 0;
    int pos = 0;
    string Word;
    while ((pos = TheString.find(Delim)) != std::string::npos) {
        Word = TheString.substr(0, pos);
        if (Word != " ") {
            vWords.push_back(Word);
        }
        TheString.erase(0, (pos + Delim.length()));
    }
    if (TheString != " ") {
        vWords.push_back(TheString);
    }
    return vWords;
}
void PrintVector(vector <string> TheVector) {
    cout << "Tokens : " << TheVector.size() << endl;
    for (string &aString : TheVector) {
        cout << aString << endl;
    }
}
int main()
{
    PrintVector(Split(ReadString(), " "));
}
