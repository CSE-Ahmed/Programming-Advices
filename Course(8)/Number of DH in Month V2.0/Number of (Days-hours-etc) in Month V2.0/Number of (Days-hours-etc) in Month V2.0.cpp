#include<iostream>
using namespace std;

short ReadNumber(string Message) {
	short Number;
	cout << Message << endl;
	cin >> Number;
	return Number;
}

bool IsLeapYear(short Year) {
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

short CountDaysInMonth(short Year, short Month) {
	if (Month < 1 && Month > 12) {
		return 0;
	}

	int ArrNumber[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? IsLeapYear(Year) ? 29 : 28 : ArrNumber[Month - 1];

}

int main() {
	short Year = ReadNumber("Enter Year : ");

	short Month = ReadNumber("Enter Month : ");

	cout << "Number of Days in Month [" << Month << "] is : " << CountDaysInMonth(Year, Month) << " day" << endl;

}