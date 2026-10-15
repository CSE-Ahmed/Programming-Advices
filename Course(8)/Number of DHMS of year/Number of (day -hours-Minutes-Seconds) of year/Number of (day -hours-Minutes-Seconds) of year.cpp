#include<iostream>
using namespace std;

short ReadYear() {
	short Year;
	cout << "Enter Year : \n";
	cin >> Year;
	return Year;
}

bool IsLeapYear(short Year) {
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

short NumberOfDaysInYear(short Year) {
	return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInYear(short Year) {
	return NumberOfDaysInYear(Year) * 24;
}

int NumberOfMinutesInYear(short Year) {
	return NumberOfHoursInYear(Year) * 60;
}

int NumberOfSecondsInYear(short Year) {
	return NumberOfMinutesInYear(Year) * 60;
}

int main() {
	short Year = ReadYear();

	cout << "Numebr of days    in Year [" << Year << "] is : " << NumberOfDaysInYear(Year) << endl;
	cout << "Numebr of Hours   in year [" << Year << "] is : " << NumberOfHoursInYear(Year) << endl;
	cout << "Numebr of Minutes in Year [" << Year << "] is : " << NumberOfMinutesInYear(Year) << endl;
	cout << "Number of seconds in year [" << Year << "] is : " << NumberOfSecondsInYear(Year) << endl;

	system("pause > 0");
	return 0;
}