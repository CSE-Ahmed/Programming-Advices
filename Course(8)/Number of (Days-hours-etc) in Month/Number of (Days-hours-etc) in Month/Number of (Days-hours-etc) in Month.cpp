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

short CountDaysInMonth  (short Year, short Month) {
	if (Month < 1 || Month > 12) {
		return 0;
	}
	if (Month == 2) {
		return IsLeapYear(Year) ? 29 : 28;
	}
	short arr31days[7] = { 1,3,5,7,8,10,12 };
	for (short i = 0; i < 7; i++) {
		if (arr31days[i] == Month) {
			return 31;
		}
	}
	return 30;
}

short CountHoursInMonth (short Year, short Month) {
	return CountDaysInMonth(Year, Month) * 24;
}

int CountMinutesInMonth (short Year, short Month) {
	return CountHoursInMonth(Year, Month) * 60;
}

int CountSecondsInMonth(short Year, short Month) {
	return CountMinutesInMonth(Year, Month) * 60;
}

int main() {
	short Year = ReadNumber("Enter Year : ");

	short Month = ReadNumber("Enter the Month : ");

	cout << "Number of Days    in Month [" << Month << "] is : " << CountDaysInMonth(Year, Month) << endl;
	cout << "Number of Hours   in Month [" << Month << "] is : " << CountHoursInMonth(Year, Month) << endl;
	cout << "Number of Minutes in Month [" << Month << "] is : " << CountMinutesInMonth(Year, Month) << endl;
	cout << "Number of Seconds in Month [" << Month << "] is : " << CountSecondsInMonth(Year, Month) << endl;

	system("pause >0");
	return 0;
}