#include<iostream>
#include "DateManager.h"
using namespace std;

void DecreaseDateByOneDay(stDate& Date) {
	if (IsFirstDayInMonth(Date)) {
		if (IsFirstMonthInYear(Date.month)) {
			Date.day = 31;
			Date.month = 12;
			Date.year--;
		}
		else {
			Date.month--;
			Date.day = NumberOfDaysInAMonth(Date.month, Date.year);
		}
	}
	else {
		Date.day--;
	}
}

void DecreaseDateByXDays(stDate& Date, short Days) {
	for (short i = 0; i < Days; i++) {
		DecreaseDateByOneDay(Date);
	}
}

void DecreaseDateByOneWeek(stDate& Date) {
	DecreaseDateByXDays(Date, 7);
}

void DecreaseDateByXWeeks(stDate& Date, short Weeks) {
	for (short i = 0; i < Weeks; i++) {
		DecreaseDateByOneWeek(Date);
	}
}

void DecreaseDateByOneMonth(stDate& Date) {
	if (IsFirstMonthInYear(Date.month)) {
		Date.month = 12;
		Date.year--;
	}
	else {
		Date.month--;
	}
}

void DecreaseDateByXMonths(stDate& Date, short Months) {
	for (short i = 0; i < Months; i++) {
		DecreaseDateByOneMonth(Date);
	}
}

void DecreaseDateByOneYear(stDate& Date) {
	Date.year--;
}

void DecreaseDateByXYears(stDate& Date, short Years) {
	for (short i = 0; i < Years; i++) {
		DecreaseDateByOneYear(Date);
	}
}

void DecreaseDateByXYearsFaster(stDate& Date, short Years) {
	Date.year -= Years;
}

void DecreaseDateByOneDecade(stDate& Date) {
	DecreaseDateByXYearsFaster(Date, 10);
}

void DecreaseDateByXDecades(stDate& Date, short Decades) {
	DecreaseDateByXYearsFaster(Date, Decades * 10);
}

void DecreaseDateByXDecadesFaster(stDate& Date, short Decades) {
	Date.year -= Decades * 10;
}

void DecreaseDateByOneCentury(stDate& Date) {
	Date.year += 100;
}

void DecreaseDateByOneMillennium(stDate& Date) {
	Date.year += 1000;
}

int main() {
	stDate Date = ReadDate();

	cout << "\nDate After : \n\n";
	DecreaseDateByOneDay(Date);
	cout << "01 - Decreasing one day is : " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	DecreaseDateByXDays(Date, 10);
	cout << "02 - Decreasing 10 days is : " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	DecreaseDateByOneWeek(Date);
	cout << "03 - Decreasing one week is : " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	DecreaseDateByXWeeks(Date, 10);
	cout << "04 - Decreasing 10 weeks is : " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	DecreaseDateByOneMonth(Date);
	cout << "05 - Decreasing one Month is : " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	DecreaseDateByXMonths(Date, 5);
	cout << "06 - Decreasing 5 Months is : " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	DecreaseDateByOneYear(Date);
	cout << "07 - Decreasing one Year is : " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	DecreaseDateByXYears(Date, 10);
	cout << "08 - Decreasing 10 Years is : " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	DecreaseDateByXYearsFaster(Date, 10);
	cout << "09 - Decreasing 10 Years (Faster) is : " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	DecreaseDateByOneDecade(Date);
	cout << "10 - Decreasing one Decade is : " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	DecreaseDateByXDecades(Date, 10);
	cout << "11 - Decreasing 10 Decades is : " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	DecreaseDateByXDecadesFaster(Date, 10);
	cout << "12 - Decreasing 10 Decades (faster) is : " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	DecreaseDateByOneCentury(Date);
	cout << "13 - Decreasing one Century is : " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	DecreaseDateByOneMillennium(Date);
	cout << "14 - Decreasing one Millennium is : " << Date.day << "/" << Date.month << "/" << Date.year << endl;

}