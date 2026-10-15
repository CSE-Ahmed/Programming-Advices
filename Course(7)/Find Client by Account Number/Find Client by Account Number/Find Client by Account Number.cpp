#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "ClientsRecord.txt";

struct stClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

string ReadAccountNumber() {
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}

vector<string> SplitString(string S1, string delim = "#//#") {
    vector<string> vString;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(delim)) != std::string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "") {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "") {
        vString.push_back(S1);
    }
    return vString;
}

stClient ConvertLinetoRecord(string Line, string Seperator = "#//#") {
    stClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}

vector<stClient> LoadClientsDataFromFile() {
    vector<stClient> vClients;
    fstream MyFile;

    MyFile.open(ClientsFileName, ios::in);

    if (MyFile.is_open()) {
        string Line;
        stClient Client;
        while (getline(MyFile, Line)) {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

void PrintClientRecord(stClient Client) {
    cout << "\nThe following are the client details:\n\n";
    cout << "Account Number : " << Client.AccountNumber << endl;
    cout << "Pin Code       : " << Client.PinCode << endl;
    cout << "Name           : " << Client.Name << endl;
    cout << "Phone          : " << Client.Phone << endl;
    cout << "Account Balance: " << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, vector<stClient> vClients, stClient& Client) {
    for (stClient C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            Client = C;
            return true;
        }
    }
    return false;
}

int main() {
    stClient Client;

    string AccountNumber = ReadAccountNumber();
    vector<stClient> vClients = LoadClientsDataFromFile();

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
        PrintClientRecord(Client);
    }
    else {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n" << endl;
    }

    system("pause>0");
    return 0;
}