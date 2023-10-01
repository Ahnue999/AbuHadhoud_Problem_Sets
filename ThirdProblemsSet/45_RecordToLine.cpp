#include <iostream>
using namespace std;

struct stData {
    string AccountNumber;
    string PINCode;
    string Name;
    string Phone;
    int AccountBalance;
};

string ReadString(string Massage)
{
    string TheString;
    cout << Massage;
    getline(cin, TheString);
    return TheString;
}

int ReadNum(string Massage) {
    int Num;
    cout << Massage;
    cin >> Num;
    return Num;
}

stData FillClientData() {
    stData Data;
    Data.AccountNumber = ReadString("Enter Your Account Number : ");
    Data.PINCode = ReadString("Enter Your PIN Code : ");
    Data.Name = ReadString("Enter Your Name : ");
    Data.Phone = ReadString("Enter Your Phone Number: ");
    Data.AccountBalance = ReadNum("Enter Your Account Balance : ");
    return Data;
}

string ConvertRecordToLine(stData Data, string Seperator = "#//#") {
    string Line = "";
    
    Line += Data.AccountNumber + Seperator; 
    Line += Data.PINCode + Seperator;
    Line += Data.Name + Seperator;
    Line += Data.Phone + Seperator;
    Line += to_string(Data.AccountBalance);

    return Line;
}

int main() {
    stData ClientData;
    ClientData = FillClientData();
    cout << ConvertRecordToLine(ClientData);
}