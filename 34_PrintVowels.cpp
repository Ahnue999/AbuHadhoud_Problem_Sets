#include <iostream>
using namespace std;

char ReadChar() {
    char TheChar;
    cout << "Enter a character\n";
    cin >> TheChar;
    return TheChar;
}

string ReadString() {
    string TheString;
    cout << "Enter a string\n";
    getline(cin, TheString);
    return TheString;
}
bool IsVowel(char TheChar) {
    TheChar = tolower(TheChar);

    return (TheChar == 'a' || TheChar == 'e' ||TheChar == 'i' ||TheChar == 'o' ||TheChar == 'u');
}

void CountVowels(string TheString) {
    int Length = TheString.length();
    
    for (int i = 0; i < Length; i++) {
        if (IsVowel(TheString[i])) {
            cout << TheString[i] << " ";
        }
    }
}
int main() {
    string TheString = ReadString();

    CountVowels(TheString);
}