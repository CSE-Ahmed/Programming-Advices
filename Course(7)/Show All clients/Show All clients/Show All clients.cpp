#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;

struct stClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	int AccountBalance;
};

vector<string> SplitString(string S1, string delim = "#//#") {
	vector<string> vString;
	short pos = 0;
	string sword = "";
	while ((pos = S1.find(delim)) != std::string::npos) {
		sword = S1.substr(0, pos);
		
		if (sword != "") {
			vString.push_back(sword);
			
		}
		S1.erase(0, pos + delim.length());
	}

	if (S1 != "") {
		vString.push_back(S1);
	}

	return vString;
}

stClient ConvertLinetoRecord(string Line) {
	stClient Client;
	vector<string> vString = SplitString(Line);
	Client.AccountNumber = vString[0] ;
	Client.PinCode = vString[1];
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stod(vString[4]);

	return Client;
}

vector<stClient> LoadClientsDataFromFile() {
	string stLine = "";
	vector<stClient> vClient;
	stClient Client;
	fstream fClient;
	
	fClient.open("ClientsRecord.txt", ios::in);
	if (fClient.is_open()) {
		while (getline(fClient, stLine)) {
			Client = ConvertLinetoRecord(stLine);

			vClient.push_back(Client);
		}

		fClient.close();
	}
	else {
		cout << "Error while opening the file :( \n";
	}

	return vClient;
}

void PrintClientRecord(stClient Client) {
	cout << "|" << left << setw(15) << Client.AccountNumber;

	cout << "|" << left << setw(15) << Client.PinCode;
	
	cout << "|" << left << setw(15) << Client.Name;

	cout << "|" << left << setw(15) << Client.Phone;

	cout << "|" << left << setw(15) << Client.AccountBalance;
}

void PrintAllClientsRecord(vector<stClient> vString) {
	
	cout << setw(50) << "Client List (" << vString.size() << ") client (s) " << setw(50) << endl;
	
	cout << string(90, '_') << "\n\n";

	cout << "| " << left << setw(14) << "Account Number";
	cout << "| " << left << setw(14) << "Pin Code ";
	cout << "| " << left << setw(14) << "Name ";
	cout << "| " << left << setw(14) << "Phone ";
	cout << "| " << left << setw(15) << "Account Balance \n";
	
	cout << string(90, '_') << "\n\n";

	for (short i = 0; i < vString.size(); i++) {
		PrintClientRecord(vString[i]);

		cout << endl;
	}

	cout << string(90, '_') << endl;
}

int main() {
	vector<stClient> vClient;
	vClient = LoadClientsDataFromFile();
	PrintAllClientsRecord(vClient);
}