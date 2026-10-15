#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct stClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string phone;
	int AccountBalance;
};

vector <string> SplitString(string S1, string delim) {
	vector <string> vString;
	short pos = 0;
	string sword;

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

stClient ConvertLineToData(string Line, string seperator = "#//#") {
	vector <string> vString;
	
	stClient C1;
	
	vString = SplitString(Line, seperator);

	C1.AccountNumber  = vString[0];
	C1.PinCode        = vString[1];
	C1.Name           = vString[2];
	C1.phone          = vString[3];
	C1.AccountBalance = stoi(vString[4]);

	return C1;
}

void PrintClientRecord(stClient C1) {
	
	cout << "Your Account Number : " << C1.AccountNumber << endl;
	cout << "Your Pin Code       : " << C1.PinCode << endl;
	cout << "Your Name           : " << C1.Name << endl;
	cout << "Your Phone          : " << C1.phone << endl;
	cout << "Your Account Balance: " << C1.AccountBalance << endl;
}

int main() {
	string LineData = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";
	cout << "Your line data is : \n" << LineData << endl;
	stClient C1 = ConvertLineToData(LineData);
	
	cout << "\nThe record of your line data is : " << endl;
	PrintClientRecord(C1);
}