#include <iostream>
#include <ctype.h>
#include <string.h>
using namespace std;



string RemovePunc(string TheString) {
    string After = "";
    for (int i = 0; i < TheString.length(); i++) {
        if (!ispunct(TheString[i])) {
            After += TheString[i];
        }
    }
    return After;
}

int main() {
    string Sen = "What? is! That$";
    cout << RemovePunc(Sen);
}