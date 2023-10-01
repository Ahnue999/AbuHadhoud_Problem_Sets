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

string RepalceWords(string TheString, string ToReplace, string Replacement, bool Match = true) {
    vector<string> vWords = Split(TheString, " ");

    string After = "";
    for (string &s : vWords)
    {
        if (Match) {
            if (s == ToReplace) {
                s = Replacement;
            }
        }
        else {
            if (ToLower(s) == ToLower(ToReplace)) {
                s = Replacement;
            }
        }
    }
    return After.substr(0, After.length() - 1);
}
int main()
{
    string sen = "Mohammed Ali is quite ali";
    cout << RepalceWords(sen, "Ali", "Ahmed", true);
    system("pause>0");
}
