#include <iostream>
#include <fstream>
using namespace std;

const string ClientsFileName = "Client.txt";

struct stData {
    string AccountNumber;
    string PINCode;
    string Name;
    string Phone;
    double AccountBalance;
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
    cout << "Enter Your Account Number : ";
    getline(cin >> ws, Data.AccountNumber);
    Data.PINCode = ReadString("Enter Your PIN Code : ");
    Data.Name = ReadString("Enter Your Name : ");
    Data.Phone = ReadString("Enter Your Phone Number: ");
    Data.AccountBalance = stod(ReadString("Enter Your Account Balance : "));
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

void ClientToFile(string FileName, string Line) {
    
    fstream ClientFile;

    ClientFile.open(FileName, ios::out | ios::app );
    if (ClientFile.is_open()) {
        ClientFile << Line << endl;
        ClientFile.close();
    }
    
}

void AddNewClient() {
    stData ClientData;
    ClientData = FillClientData();
    ClientToFile(ClientsFileName, ConvertRecordToLine(ClientData));
}
void AddClients () {
    char Answer = 'Y';
    do {
        system ("cls");
        cout << "Adding new clients : \n\n";
        
        AddNewClient();

        cout << "Added succefully!!\nDo You Want to Add More Clients ? [y/n]  \n";
        cin >> Answer;
    } while (toupper(Answer) == 'Y');
}
int main()
{
    AddClients();
    system("pause>0");
}