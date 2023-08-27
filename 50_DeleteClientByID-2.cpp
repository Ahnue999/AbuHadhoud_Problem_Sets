#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string FileName = "Client.txt";

struct stData {
    string AccountNumber;
    string PINCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool ToDelete = false;
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

string ReadClientAccountInfo() {
    string ID = "";
    cout << "Enter the ID of the account you want to find\n";
    getline(cin, ID);
    return ID;
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

bool SearchClient(string ID, vector<stData> Clients, stData& Client) {
    for (stData &C : Clients) {
        if (C.AccountNumber == ID) {
            Client = C;
            return true;
        }
    } 
    return false;
}

void PrintRecord (stData Data) {
    cout << "Account Numer : " << Data.AccountNumber << endl;
    cout << "PIN Code : " << Data.PINCode << endl;
    cout << "Name : " << Data.Name << endl;
    cout << "Phone : " << Data.Phone << endl;
    cout << "Account Balance : " << Data.AccountBalance << endl;
}

void MarkClientForDeletion(string ID, vector<stData> &Clients) {
    for (stData &C : Clients) {
        if (C.AccountNumber == ID) {
            C.ToDelete = true;
        }
    }
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

void LoadVectorToFile(string FileName, vector<stData> Clients) {
    fstream MyFile;

    MyFile.open(FileName, ios::out);
    
    if (MyFile.is_open()) {
        for (stData &C : Clients) {
            if (!C.ToDelete) {
                MyFile << ConvertRecordToLine(C) << endl;
            }
        } 
    }
}
bool DeleteClientByID(vector<stData> &Clients, string ID) {
    char Answer = 'N';
    stData Client;

    if (SearchClient(ID, Clients, Client)) {
        PrintRecord(Client);

        cout << "Are you sure you want to delete this record\n";
        cin >> Answer;
        
        if (toupper(Answer) == 'Y') {
            MarkClientForDeletion(ID, Clients);
            LoadVectorToFile(FileName, Clients);

            cout << "Client was deleted successfully!\n";
            Clients = LoadFileToVector(FileName);
        }
    }
    else {
        cout << "Client was not found!\n";
    }
}
int main() {
    string ID = ReadClientAccountInfo();
    vector<stData> Clients = LoadFileToVector(FileName);

    DeleteClientByID(Clients, ID);
}