#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
#include "DateManager.h"
using namespace std;

bool IsItWeekend(stDate Date) {
	short DayOfWeek = DayOfWeekOrder(Date);
	return (DayOfWeek == 5 || DayOfWeek == 6);
}

bool IsEndOfWeek(stDate Date) {
	return(DayOfWeekOrder(Date) == 6);
}

short DaysUntilEndOfWeek(stDate Date) {
	
	return 6 - DayOfWeekOrder(Date);
}

short DaysUntilEndOfMonth(stDate Date) {
	return (NumberOfDaysInAMonth(Date.Month, Date.Year) - Date.Day);
}

short DaysUntilEndOfYear(stDate Date) {
		short DaysInYear = IsLeapYear(Date.Year) ? 366 : 365;
		short DaysfromtheBegginingOfTheYear = PrintNumberofDays(Date);
		return (DaysInYear - DaysfromtheBegginingOfTheYear);
}
int main() {
	stDate Date = GetSystemDate();
	cout << "Today is : " << DayOfWeekName(DayOfWeekOrder(Date)) << " " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	cout << "\nIs It End Of Week ?\n" << (IsEndOfWeek(Date) ? "Yes it is\n" : "No it isn't\n");
	cout << "\nIs It Weekend ?\n" << (IsItWeekend(Date) ? "Yes it is\n" : "No it isn't\n");
	cout << "\nIs It Business Day ?\n" << (!IsItWeekend(Date) ? "Yes it is\n" : "No it isn't\n");
	cout << "\nDays until End of Week   : " << DaysUntilEndOfWeek(Date) << " day(s)\n";
	cout << "Days until End of Month  : " << DaysUntilEndOfMonth(Date) << " day(s)\n";
	cout << "Days until End of Year   : " << DaysUntilEndOfYear(Date) << " day(s)\n";
	return 0;
}