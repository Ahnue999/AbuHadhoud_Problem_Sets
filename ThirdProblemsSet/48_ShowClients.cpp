#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

const string FileName = "Client.txt";

struct stData {
    string AccountNumber;
    string PINCode;
    string Name;
    string Phone;
    double AccountBalance;
};

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


stData LineToRecord(string Line, string Delim = "#//#") {
    vector<string> vData = Split(Line, "#//#");
    stData Data;
    Data.AccountNumber = vData[0];
    Data.PINCode = vData[1];
    Data.Name = vData[2];
    Data.Phone = vData[3];
    Data.AccountBalance = stod(vData[4]);
    return Data;
}

vector<stData> LoadFileToVector (string FileName) {
    fstream ClientsFile;
    vector<stData> vClientsData;

    ClientsFile.open(FileName, ios::in);
    if (ClientsFile.is_open()) {
        string Line;
        stData Client;

        while (getline(ClientsFile, Line)) {
            Client = LineToRecord(Line);
            vClientsData.push_back(Client);
        }

        ClientsFile.close();

    }
    return vClientsData;
}


void PrintClients(vector<stData> Data) {
    cout << "                          Client list (" << Data.size() << ") Client(s): " << endl;
    cout << "________________________________________________________________________________________________\n";
    cout << "|" << setw(20) << left << "Account Number" << "|" << setw(12) << "Pin Code" << "|" << setw(34) << "Client Name" << "|" << setw(18) << "Phone Number" << "|" << setw(12) << "Balance" << endl;
    cout << "________________________________________________________________________________________________\n";

    for (stData &Record : Data) {
        cout <<  "|" << setw(20) << Record.AccountNumber <<  "|" << setw(12) << Record.PINCode << "|" << setw(34) << Record.Name << "|" << setw(18) << Record.Phone << "|" << setw(12) << Record.AccountBalance << endl;
    }
}

int main() {
    
    PrintClients(LoadFileToVector(FileName));
}