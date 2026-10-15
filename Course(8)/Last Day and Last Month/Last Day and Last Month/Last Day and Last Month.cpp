#include<iostream>
using namespace std;

struct stDate {
	short day;
	short month;
	short year;
};

stDate ReadDate() {
	stDate Date;
	cout << "Please enter the day: ";
	cin >> Date.day;
	cout << "Please enter the month: ";
	cin >> Date.month;
	cout << "Please enter the year: ";
	cin >> Date.year;
	return Date;
}
bool IsLeapYear(short year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool IsLastMonthInYear(short Month) {
	return (Month == 12);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12) {
	
		return 0;
	
	}
	
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];

}

bool IsLastDayInMonth(stDate Date) {
	return (Date.day == NumberOfDaysInAMonth(Date.month, Date.year));
}	

int main() {
	stDate Date = ReadDate();
	
	if (IsLastDayInMonth(Date)) {
		cout << "The date is the last day in the month." << endl;
	}
	else {
		cout << "The date is not the last day in the month." << endl;
	}
	if (IsLastMonthInYear(Date.month)) {
		cout << "The month is the last month in the year." << endl;
	}
	else {
		cout << "The month is not the last month in the year." << endl;
	}
	return 0;
}