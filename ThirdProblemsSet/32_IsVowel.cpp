#include <iostream>
using namespace std;

char ReadChar() {
    char TheChar;
    cout << "Enter a character\n";
    cin >> TheChar;
    return TheChar;
}

bool IsVowel(char TheChar) {
    TheChar = tolower(TheChar);

    return (TheChar == 'a' || TheChar == 'e' ||TheChar == 'i' ||TheChar == 'o' ||TheChar == 'u');
}

int main() {
    char TheChar = ReadChar();

    if (IsVowel(TheChar)) {
        cout << "Yes!";
    }
    else cout << "No!";
}