#pragma once
#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

struct stDate {
	short Day;
	short Month;
	short Year;
};

short ReadNumber(string Message) {
	short Number;
	cout << Message;
	cin >> Number;
	return Number;
}

stDate ReadDate() {
	stDate date;
	cout << "Enter day: ";
	cin >> date.Day;
	cout << "Enter month: ";
	cin >> date.Month;
	cout << "Enter year: ";
	cin >> date.Year;
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
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

stDate GetSystemDate() {
	time_t t = time(0);
	tm* now = localtime(&t);
	stDate Date;
	Date.Day = now->tm_mday;
	Date.Month = now->tm_mon + 1;
	Date.Year = now->tm_year + 1900;
	return Date;
}

short DayOfWeekOrder(short Day, short Month, short Year) {
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date) {
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayOfWeekName(short DayOfWeekOrder) {
	string Days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return Days[DayOfWeekOrder];
}

short PrintNumberofDays(stDate Date) {

	short MonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	if (Date.Month < 1 || Date.Month > 12) {
		return 0;
	}

	if (Date.Month == 2 && IsLeapYear(Date.Year)) {
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

bool IsFirstMonthInYear(short Month) {
	return (Month == 1);
}

bool IsFirstDayInMonth(stDate Date) {
	return (Date.Day == 1);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	if (Date1.Year < Date2.Year)
		return true;
	else if (Date1.Year == Date2.Year && Date1.Month < Date2.Month)
		return true;
	else if (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day)
		return true;
	else
		return false;
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

void swapDates(stDate& Date1, stDate& Date2)
{
	stDate temp = Date1;
	Date1 = Date2;
	Date2 = temp;
}

bool IsWeekend(stDate Date)
{
	short DayOfWeek = DayOfWeekOrder(Date);
	return (DayOfWeek == 5 || DayOfWeek == 6);
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	short swapFlags = 1;

	if (!IsDate1BeforeDate2(Date1, Date2))
	{
		swapDates(Date1, Date2);
		swapFlags = -1;
	}

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return IncludeEndDay ? ++Days * swapFlags : Days * swapFlags;
}

bool IsItBusinessDay(stDate Date)
{
	return !IsWeekend(Date);
}

short CalculateVacationDays(stDate DateFrom, stDate DateTo) {
	short DaysCount = 0;
	while (IsDate1BeforeDate2(DateFrom, DateTo)) {
		if (IsItBusinessDay(DateFrom)) {
			DaysCount++;
		}

		DateFrom = IncreaseDateByOneDay(DateFrom);
	}
	return DaysCount;
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
	short TotalDays = 0;
	for (int i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Year);
	}
	TotalDays += Day;
	return TotalDays;
}

short NumberOfDaysFromTheBeginingOfTheYear(stDate Date) {
	short TotalDays = 0;
	for (int i = 1; i <= Date.Month - 1; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Date.Year);
	}
	TotalDays += Date.Day;
	return TotalDays;
}

stDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
	stDate Date;
	Date.Year = Year;
	short RemainingDays = DateOrderInYear;
	short MonthDays = 0;
	Date.Month = 1;
	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
			if (Date.Month > 12)
			{
				Date.Month = 1;
				Year++;
			}
		}
		else
		{
			Date.Day = RemainingDays;
			Date.Year = Year;
			break;
		}
	}
	return Date;
}

stDate CalculateReturnDate(stDate StartDate, short VacationDays) {
	stDate ReturnDate = StartDate;
	
	short DaysCounted = 0;
	
	while (DaysCounted <= VacationDays) {
	
		ReturnDate = IncreaseDateByOneDay(ReturnDate);
		
		if (IsItBusinessDay(ReturnDate)) {
			DaysCounted++;
		}
	}
	return ReturnDate;
}