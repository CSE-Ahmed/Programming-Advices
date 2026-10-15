#include<iostream>
#include<string>
using namespace std;

struct stClient {
	string AccountNumber;
	string pinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

stClient ReadNewRecord() {
	
	stClient C1;
	
	cout << "Enter Your Account Number: ";
	getline(cin, C1.AccountNumber);
	
	cout << "Enter your Pin code : ";
	getline(cin, C1.pinCode);
	
	cout << "Enter your Full Name : ";
	getline(cin, C1.Name);
	
	cout << "Enter your phone Number: ";
	getline(cin, C1.Phone);
	
	cout << "Enter your Account Balance : ";
	cin >> C1.AccountBalance;

	return C1;
}

string ConvertRecordToLine(stClient Client, string seperator = "#//#") {
	string stClientRecord = "";
	stClientRecord += Client.AccountNumber + seperator;
	stClientRecord += Client.pinCode + seperator;
	stClientRecord += Client.Name + seperator;
	stClientRecord += Client.Phone + seperator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}

int main() {
	cout << "Enter your Record Please :-\n";
	stClient Client;
	Client = ReadNewRecord();
	cout << "Your record is : \n" << ConvertRecordToLine(Client);
}