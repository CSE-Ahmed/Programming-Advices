/*#include<iostream>
using namespace std;

struct stDate {
	short Day;
	short Month;
	short Year;
};

stDate ReadFullData() {
	stDate Date;
	cout << "Enter Day: ";
	cin >> Date.Day;
	cout << "Enter Month: ";
	cin >> Date.Month;
	cout << "Enter Year: ";
	cin >> Date.Year;
	return Date;
}

bool IsLeap(short Year) {
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

bool CompareDates(stDate date1, stDate date2) {
	if (date1.Year < date2.Year) {
		return true;
	}
	else if (date1.Year == date2.Year) {
		if (date1.Month < date2.Month) {
			return true;
		}
		else if (date1.Month == date2.Month) {
			if (date1.Day < date2.Day) {
				return true;
			}
		}
	}
	return false;
}

short GetNumberofDays(stDate &Date) {

	short MonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	if (Date.Month < 1 || Date.Month > 12) {
		return 0;
	}

	if (Date.Month == 2 && IsLeap(Date.Year)) {
		MonthDays[1] = 29;
	}

	if (Date.Day < 1 || Date.Day > MonthDays[Date.Month - 1]) {
		return 0;
	}

	short NumberDays = 0;

	for (short i = 0; i < Date.Month - 1; i++) {
		NumberDays += MonthDays[i];
	}

	NumberDays += Date.Day;

	return NumberDays;
}

short DiffInDays(stDate& date1, stDate& date2) {
	short Days1 = GetNumberofDays(date1);
	short Days2 = GetNumberofDays(date2);
	if (CompareDates(date1, date2)) {
		return Days2 - Days1;
	}
	else {
		cout << "Date 1 is greater than Date 2" << endl;
		return 0;
	}
}

int main() {
	cout << "Enter Date 1 : " << endl;
	cout << string(20, '_') << endl;
	stDate Date1 = ReadFullData();
	cout << string(20, '_') << endl;
	cout << "Enter Date 2 : " << endl;
	cout << string(20, '_') << endl;
	stDate Date2 = ReadFullData();

	cout << "The differnet between to dates is : " << DiffInDays(Date1, Date2) << endl;
	cout << "The differnet between to dates (including end date) is :  " << DiffInDays(Date1, Date2) + 1 << endl;
}*/
#include <iostream>
using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

stDate ReadDate()
{
	stDate Date;
	cout << "Enter Year: ";
	cin >> Date.Year;
	cout << "Enter Month: ";
	cin >> Date.Month;
	cout << "Enter Day: ";
	cin >> Date.Day;
	return Date;
}

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12) {
		return 0;
	}
		
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month,
		Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return IncludeEndDay ? ++Days : Days;
}

int main() {
	cout << "Enter Date 1: " << endl;
	cout << string(20, '_') << endl;
	stDate Date1 = ReadDate();
	cout << string(20, '_') << endl;
	cout << "Enter Date 2: " << endl;
	cout << string(20, '_') << endl;
	stDate Date2 = ReadDate();
	cout << "The difference between the two dates is: " << GetDifferenceInDays(Date1, Date2) << endl;
	cout << "The difference between the two dates (including end date) is: " << GetDifferenceInDays(Date1, Date2, true) << endl;
}