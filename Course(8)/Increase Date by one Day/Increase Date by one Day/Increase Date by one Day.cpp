#include<iostream>
using namespace std;

struct stDate {
	short day;
	short month;
	short year;
};

stDate ReadDate() {
	stDate date;
	cout << "Enter day: ";
	cin >> date.day;
	cout << "Enter month: ";
	cin >> date.month;
	cout << "Enter year: ";
	cin >> date.year;
	return date;
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

void AddDay(stDate& Date) {
	if (IsLastDayInMonth(Date)) {
		Date.day = 1;
		if (IsLastMonthInYear(Date.month)) {
			Date.month = 1;
			Date.year++;
		}
		else {
			Date.month++;
		}
	}
	else {
		Date.day++;
	}
}

int main() {
	stDate date = ReadDate();
	AddDay(date);
	cout << "The next date is: " << date.day << "/" << date.month << "/" << date.year << endl;
	return 0;
}