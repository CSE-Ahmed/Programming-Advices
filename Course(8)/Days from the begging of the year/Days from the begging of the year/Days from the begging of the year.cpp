#include<iostream>
using namespace std;

short ReadNumber(string Message) {
	short Number;
	cout << Message ;
	cin >> Number;
	return Number;
}

bool IsLeap(short Year) {
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

short PrintNumberofDays(short Year, short Month, short Day) {
	
	short MonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	if (Month < 1 || Month > 12) {
		return 0;
	}

	if (Month == 2 && IsLeap(Year)) {
		MonthDays[1] = 29;
	}

	if (Day < 1 || Day > MonthDays[Month - 1]) {
		return 0;
	}

	short NumberDays = 0;

	for (short i = 0; i < Month - 1; i++) {
		NumberDays += MonthDays[i];
	}

	NumberDays += Day;
	
	return NumberDays;
}

int main() {
	short Year = ReadNumber("Enter Year : ");
	short Month = ReadNumber("Enter Month : ");
	short Day = ReadNumber("Enter Day : ");

	cout << "Number of days from the begging of the year is : " << PrintNumberofDays(Year, Month, Day) <<endl;

	system("pause > 0");
}