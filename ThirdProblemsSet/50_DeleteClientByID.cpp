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

void PrintRecord (stData Data) {
    cout << "Account Numer : " << Data.AccountNumber << endl;
    cout << "PIN Code : " << Data.PINCode << endl;
    cout << "Name : " << Data.Name << endl;
    cout << "Phone : " << Data.Phone << endl;
    cout << "Account Balance : " << Data.AccountBalance << endl;
}

bool SearchClient(string ID, stData& Client) {
    vector<stData> ClientsData = LoadFileToVector(FileName);
    for (stData &C : ClientsData) {
        if (C.AccountNumber == ID) {
            Client = C;
            return true;
        }
    } 
    return false;
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

void SaveDataToFile(string FileName, vector<string> &TheVector)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    if (MyFile.is_open())
    {
	for (string &Line : TheVector)
	{
            if (Line != "")
            {
                MyFile << Line << endl;
            }
	}
    }
    MyFile.close();
}

void ClientToFile(string FileName, string Line) {
    
    fstream ClientFile;

    ClientFile.open(FileName, ios::out | ios::app );
    if (ClientFile.is_open()) {
        ClientFile << Line << endl;
        ClientFile.close();
    }
    
}


vector<stData> DeleteClient (vector<stData> &Clients, string ID) {
    for (int i = 0; i < Clients.size() - 1; i++) {
        if (Clients[i].AccountNumber == ID) {
            Clients.erase(Clients.begin() + i);
        }
    }
    vector<string> LinesVector;
    for (stData &Line : Clients) {
        LinesVector.push_back(ConvertRecordToLine(Line));
    }
    SaveDataToFile(FileName, LinesVector);
}

int main() {
    string ID = ReadClientAccountInfo();
    vector<stData> Clients = LoadFileToVector(FileName);
    stData Client;
    SearchClient(ID, Client);
    PrintRecord(Client);
    char Answer;
    cout << "Are you sure you want to delete this client? \n";
    cin >> Answer;
    if (toupper(Answer) == 'Y') {
        DeleteClient(Clients, ID);
    }
}