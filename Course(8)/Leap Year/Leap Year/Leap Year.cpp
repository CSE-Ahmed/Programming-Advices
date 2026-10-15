#include<iostream>
using namespace std;

short ReadYear() {
	short Year;
	cout << "Enter year : ";
	cin >> Year;
	return Year;
}

bool CheckLeapOrNot(short Year) {
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

int main() {
	short Year = ReadYear();
	if (CheckLeapOrNot(Year)) {
		cout << "\nYes, year [" << Year << "] is a Leap Year\n";
	}
	else {
		cout << "\nNo, year [" << Year << "] isn't a Leap Year\n";
	}
}