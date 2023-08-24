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

string ToLower(string TheString) {
    for (int i = 0; i < TheString.length(); i++) {
        TheString[i] = tolower(TheString[i]);
    }
    return TheString;
}

string RepalceWords(vector<string> TheVector, string ToReplace, string Replacement, bool Match = true) {
    if (!Match) {
    }
    string TheString = "";
    for (string &word : TheVector) {
        if (word == ToReplace) {
            TheString += Replacement + " ";
        }
        else {
        TheString += word + " ";
        }
    }
    return TheString.substr(0, TheString.length() - 1);
} 
int main()
{
    cout << RepalceWords(Split(ReadString(), " "), "Ali", "Ahmed", false);
    system("pause>0");
}
