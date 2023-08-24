#include <iostream>
#include <string.h>
using namespace std;

string ReplaceWord(string TheString, string ToReplace, string Replacement) {
    int pos = TheString.find(ToReplace);

    while (pos != string::npos) {
        TheString.replace(pos, ToReplace.length(), Replacement);
        pos = TheString.find(ToReplace);
    }
    return TheString;
}

int main() {
    string TheString = "Welcome to Sudan, Sudan is nice";
    string ToReplace = "Sudan";
    string Replacement = "Saudi";

    string After = ReplaceWord(TheString, ToReplace, Replacement);

    
    cout << After;
}