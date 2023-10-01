#include <iostream>
#include <string.h>
using namespace std;

string ReadString() {
    string TheString;
    cout << "Enter a string\n";
    getline(cin, TheString);
    return TheString;
}

string TrimLeft(string TheString) {
    int Length = TheString.length();
    for (int i = 0; i < Length; i++) {
        if (TheString[i] != ' ') {
            return TheString.substr(i, Length - i);
        }
    }
}

string TrimRight(string TheString) {
    int Length = TheString.length();
    for (int i = Length - 1; i > 0; i--) {
        if (TheString[i] != ' ') {
            return TheString.substr(0, i + 1);
        }
    }
}

string TrimAll(string TheString) {
    return TrimLeft(TrimRight(TheString));
}
int main() {
    string TheString = "    Mohammed  Abdalah     ";
    cout << "TrimLeft : " << endl;
    cout << TrimLeft(TheString) << endl;
    cout << "TrimRight : " << endl;
    cout << TrimRight(TheString) << "mao" << endl;
    cout << "TrimAll : " << endl;
    cout << TrimAll(TheString);
}