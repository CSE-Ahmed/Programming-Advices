#include<iostream>
#include"DateManager.h"
#include"Operations.h"
using namespace std;

string ReadString() {
	string str;
	cout << "Please Enter Date dd/mm/yyyy ? \n";
	getline(cin, str);
	return str;
}

stDate ConvertStringToDate(string S1) {
	vector<string> vString;
	
	vString = SplitString(S1,"/");

	stDate Date;

	Date.Day = stoi(vString[0]);
	Date.Month = stoi(vString[1]);
	Date.Year = stoi(vString[2]);

	return Date;
}

string ConvertDateToString(stDate Date, string Seperator = "/") {
	string Dato = "";
	Dato += to_string(Date.Day) + Seperator;
	Dato += to_string(Date.Month) + Seperator;
	Dato += to_string(Date.Year);

	return Dato;
}

int main() {
	stDate Date = ConvertStringToDate(ReadString());

	cout << "\nDay : " << Date.Day << endl;
	cout << "Month : " << Date.Month << endl;
	cout << "Year : " << Date.Year << endl;

	cout << "\nYou Entered : " << ConvertDateToString(Date);
}