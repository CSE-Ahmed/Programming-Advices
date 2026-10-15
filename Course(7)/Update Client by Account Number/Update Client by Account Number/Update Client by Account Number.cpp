#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

struct stClient{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForUpdate = false;
};

string const ClientFileName = "ClientsRecord.txt";

string ReadAccountNumber() {
	string str;
	cout << "Enter the Account Number ? \n";
	getline(cin, str);
	return str;
}

vector<string> splitString(string S1, string delim = "#//#") {
	vector<string> vString;
	short pos = 0;
	string sWord = "";

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

stClient ConvertLineToRecord(string S1, string seperator = "#//#") {
	stClient Client;
	vector<string> vClientData = splitString(S1);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);

	return Client;
}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#") {
	string stClientRecord = "";
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);
	return stClientRecord;
}

vector<stClient> LoadClientFromFile() {
	vector<stClient> vClients;
	string Line;
	stClient Client;
	fstream MyFile;
	MyFile.open(ClientFileName, ios::in);

	if (MyFile.is_open()) {
		while (getline(MyFile, Line)) {
			Client = ConvertLineToRecord(Line);
			vClients.push_back(Client);
		}

		MyFile.close();
	}
	return vClients;
}

void SaveClientsDataToFile(string FileName, vector<stClient> vClients) {
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open()) {
		string DataLine;
		for (stClient C : vClients) {
			DataLine = ConvertRecordToLine(C);
			MyFile << DataLine << endl;
		}
		MyFile.close();
	}
}

void PrintClientRecord(stClient Client) {
	cout << "\nThe following are the client details:\n\n";
	cout << "Account Number : " << Client.AccountNumber << endl;
	cout << "Pin Code       : " << Client.PinCode << endl;
	cout << "Name           : " << Client.Name << endl;
	cout << "Phone          : " << Client.Phone << endl;
	cout << "Account Balance: " << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, vector<stClient>& vClient, stClient& Client) {
	for (stClient& C : vClient) {
		if (C.AccountNumber == AccountNumber) {
			C.MarkForUpdate = true;
			Client = C;
			return true;
		}
	}
	return false;
}

stClient UpdateClientData(stClient& Client) {
	cout << "\nEnter the new data for this client\n";

	cout << "Pin Code        : ";
	getline(cin >> ws, Client.PinCode);

	cout << "Name            : ";
	getline(cin, Client.Name);

	cout << "Phone           : ";
	getline(cin, Client.Phone);

	cout << "Account Balance : ";
	cin >> Client.AccountBalance;

	return Client;
}

bool updateClientByAccountNumber(string AccountNumber, vector<stClient>& vClient) {
	stClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClient, Client)) {

		PrintClientRecord(Client);

		cout << "\nAre you sure you want to update this Client ? [Y/N]\n";
		cin >> Answer;

		if (toupper(Answer) == 'Y') {
			for (stClient& C : vClient) {
				if (C.MarkForUpdate == true) {
					UpdateClientData(C); 
					break;
				}
			}

			
			SaveClientsDataToFile(ClientFileName, vClient);

			cout << "\nClient updated successfully :) \n";
			return true;
		}
	}
	else {
		cout << "Client with Account Number [" << AccountNumber << "] Not found !\n";
		return false;
	}
	return false;
}

int main() {
	string AccountNumber = ReadAccountNumber();
	
	vector <stClient> vClient = LoadClientFromFile();

	updateClientByAccountNumber(AccountNumber, vClient);
}

