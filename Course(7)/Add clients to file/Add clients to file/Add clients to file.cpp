#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct stClient {
	string AccountNumber;
	string pinCode;
	string Name;
	string Phone;
	double Accountbalance;
};

stClient ReadNewRecord() {
	stClient Clinet;

	cout << "Enter your Account Number ? ";
	getline(cin >> ws, Clinet.AccountNumber);
	cout << "Enter your Pin Code ? ";
	getline(cin, Clinet.pinCode);
	cout << "Enter your name ? ";
	getline(cin, Clinet.Name);
	cout << "Enter your phone Number ? ";
	getline(cin, Clinet.Phone);
	cout << "Enter your Account Balance ?";
	cin >> Clinet.Accountbalance;

	return Clinet;
}

string ConvertRecordToLine(stClient Client, string seperator = "#//#") {
	string ClientRecord = "";
	ClientRecord += Client.AccountNumber + seperator;
	ClientRecord += Client.pinCode + seperator;
	ClientRecord += Client.Name + seperator;
	ClientRecord += Client.Phone + seperator;
	ClientRecord += to_string(Client.Accountbalance);

	return ClientRecord;
 }

void AddClientRecordToFile(string Record) {
	fstream ClientRecord;
	
	ClientRecord.open("ClientsRecord.txt", ios::out | ios::app);
	
	if (ClientRecord.is_open()) {

		ClientRecord << Record << endl;

		ClientRecord.close();
	}
}

void AddNewClient() {
	stClient Client;
	
	Client = ReadNewRecord();

	AddClientRecordToFile(ConvertRecordToLine(Client));

}

void AddClients() {
	char AddMore = 'Y';
	do {
		system("cls");
		
		cout << "Adding New client ? \n";

		AddNewClient();

		cout << "\n Client Added Successfully, do you want to add more clients ? Y / N ? ";

		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}

int main() {
	AddClients();
	system("pause > 0");
}