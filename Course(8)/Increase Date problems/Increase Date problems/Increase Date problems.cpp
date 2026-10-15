#include<iostream>
#include "DateManager.h"
using namespace std;

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

void IncreaseDateByXDays(short Days, stDate& Date) {
	for (short i = 0; i < Days; i++) {
		AddDay(Date);
	}
}

void IncreaseDateByOneWeek(stDate& Date) {
	IncreaseDateByXDays(7, Date);
}

void IncreaseDateByXWeeks(short Weeks, stDate& Date) {
	for (short i = 0; i < Weeks; i++) {
		IncreaseDateByOneWeek(Date);
	}
}

void IncreaseDateByOneMonth(stDate& Date) {
	if (IsLastMonthInYear(Date.month)) {
		Date.month = 1;
		Date.year++;
	}
	else {
		Date.month++;
	}

	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.month, Date.year);
	if (Date.day > NumberOfDaysInCurrentMonth) {
		
		Date.day = NumberOfDaysInCurrentMonth;
	
	}
}

void IncreaseDateByXMonths(short Months, stDate& Date) {
	for (short i = 0; i < Months; i++) {
		IncreaseDateByOneMonth(Date);
	}
}

void IncreaseDateByOneYear(stDate& Date) {
	if (IsLeapYear(Date.year) && Date.month == 2 && Date.day == 29) {
		Date.day = 28;
	}
	Date.year++;
}

void IncreaseDateByXYears(short Years, stDate& Date) {
	for (short i = 0; i < Years; i++) {
		IncreaseDateByOneYear(Date);
	}
}

void IncreasedateByXYearsFaster(short Years, stDate& Date) {
	if (IsLeapYear(Date.year) && Date.month == 2 && Date.day == 29) {
		Date.day = 28;
	}
	Date.year += Years;
}

void IncreaseDateByOneDecade(stDate& Date) {
	IncreasedateByXYearsFaster(10, Date);
}

void IncreaseDateByXDecades(short Decades, stDate& Date) {
	for (short i = 0; i < Decades; i++) {
		IncreaseDateByOneDecade(Date);
	}
}

void IncreaseDateByXDecadesFaster(short Decades, stDate& Date) {
	if (IsLeapYear(Date.year) && Date.month == 2 && Date.day == 29) {
		Date.day = 28;
	}
	Date.year += Decades * 10;
}

void IncreaseDateByOneCentury(stDate& Date) {
	Date.year += 100;
}

void IncreaseDateByOneMillennium(stDate& Date) {
	Date.year += 1000;
}

int main() {
	stDate date = ReadDate();
	cout << "\nDate After : \n\n";
	AddDay(date);
	cout << "01 - Adding one day is : " << date.day << "/" << date.month << "/" << date.year << endl;
	IncreaseDateByXDays(10, date);
	cout << "02 - Adding 10 days is : " << date.day << "/" << date.month << "/" << date.year << endl;
	IncreaseDateByOneWeek(date);
	cout << "03 - Adding one week is : " << date.day << "/" << date.month << "/" << date.year << endl;
	IncreaseDateByXWeeks(10, date);
	cout << "04 - Adding 10 weeks is : " << date.day << "/" << date.month << "/" << date.year << endl;
	IncreaseDateByOneMonth(date);
	cout << "05 - Adding one Month is : " << date.day << "/" << date.month << "/" << date.year << endl;
	IncreaseDateByXMonths(5, date);
	cout << "06 - Adding 5 Months is : " << date.day << "/" << date.month << "/" << date.year << endl;
	IncreaseDateByOneYear(date);
	cout << "07 - Adding one Year is : " << date.day << "/" << date.month << "/" << date.year << endl;
	IncreaseDateByXYears(10, date);
	cout << "08 - Adding 10 Years is : " << date.day << "/" << date.month << "/" << date.year << endl;
	IncreasedateByXYearsFaster(10, date);
	cout << "09 - Adding 10 Years (Faster) is : " << date.day << "/" << date.month << "/" << date.year << endl;
	IncreaseDateByOneDecade(date);
	cout << "10 - Adding one Decade is : " << date.day << "/" << date.month << "/" << date.year << endl;
	IncreaseDateByXDecades(10, date);
	cout << "11 - Adding 10 Decades is : " << date.day << "/" << date.month << "/" << date.year << endl;
	IncreaseDateByXDecadesFaster(10, date);
	cout << "12 - Adding 10 Decades (faster) is : " << date.day << "/" << date.month << "/" << date.year << endl;
	IncreaseDateByOneCentury(date);
	cout << "13 - Adding one Century is : " << date.day << "/" << date.month << "/" << date.year << endl;
	IncreaseDateByOneMillennium(date);
	cout << "14 - Adding one Millennium is : " << date.day << "/" << date.month << "/" << date.year << endl;

	return 0;
}