#include <iostream>
#include <ctype.h>
#include <string.h>
using namespace std;
 
 struct stStringData{
     int StringLength = 0;
     int CapitalCount = 0;
     int SmallCount = 0;
 };
     
string ReadString()
{
    string TheString;
    cout << "Enter a string\n";
    getline(cin, TheString);
    return TheString;
}

void FillData(string TheString, stStringData& Data)
{
    Data.StringLength = TheString.length();
    for (int i = 0; i < Data.StringLength; i++)
    {
        if (TheString[i] == ' ') continue;
        isupper(TheString[i]) ? Data.CapitalCount++ : Data.SmallCount++;
    }
}

int main()
{
    string TheString = ReadString();
    stStringData Data;
    
    FillData(TheString, Data);
    
    cout << "The String length : " << Data.StringLength << endl;
    cout << "The Capital count : " << Data.CapitalCount << endl;
    cout << "The Small count : " << Data.SmallCount << endl;
    
}
