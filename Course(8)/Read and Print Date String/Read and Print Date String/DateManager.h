#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct stDate {
	int Day;
	int Month;
	int Year;
};

struct stPeriod {
	stDate StartDate;
	stDate EndDate;
};

enum enCompareDates {
	enBefore = -1,
	enEqual = 0,
	enAfter = 1
};

// ----------------- I/O -----------------

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

stPeriod ReadPeriod() {
	stPeriod Period;
	cout << "Enter Start Date:\n\n";
	Period.StartDate = ReadDate();
	cout << "\nEnter End Date:\n\n";
	Period.EndDate = ReadDate();
	return Period;
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

// ----------------- Validation helpers -----------------

bool IsLeapYear(short year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year) {
	if (Month < 1 || Month > 12) {
		return 0;
	}
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

bool IsLastMonthInYear(short Month) {
	return (Month == 12);
}

bool IsFirstMonthInYear(short Month) {
	return (Month == 1);
}

bool IsLastDayInMonth(stDate Date) {
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsFirstDayInMonth(stDate Date) {
	return (Date.Day == 1);
}

// ----------------- Date arithmetic -----------------

stDate IncreaseDateByOneDay(stDate Date) {
	if (IsLastDayInMonth(Date)) {
		if (IsLastMonthInYear(Date.Month)) {
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else {
			Date.Day = 1;
			Date.Month++;
		}
	}
	else {
		Date.Day++;
	}
	return Date;
}

void swapDates(stDate& Date1, stDate& Date2) {
	stDate temp = Date1;
	Date1 = Date2;
	Date2 = temp;
}

// ----------------- Day of week -----------------

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

bool IsWeekend(stDate Date) {
	short DayOfWeek = DayOfWeekOrder(Date);
	return (DayOfWeek == 5 || DayOfWeek == 6);
}

bool IsItBusinessDay(stDate Date) {
	return !IsWeekend(Date);
}

// ----------------- Day counts & conversions -----------------

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
	short TotalDays = 0;
	for (int i = 1; i <= Month - 1; i++) {
		TotalDays += NumberOfDaysInAMonth(i, Year);
	}
	TotalDays += Day;
	return TotalDays;
}

short NumberOfDaysFromTheBeginingOfTheYear(stDate Date) {
	return NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
}

stDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year) {
	stDate Date;
	Date.Year = Year;
	short RemainingDays = DateOrderInYear;
	short MonthDays = 0;
	Date.Month = 1;
	while (true) {
		MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
		if (RemainingDays > MonthDays) {
			RemainingDays -= MonthDays;
			Date.Month++;
			if (Date.Month > 12) {
				Date.Month = 1;
				Year++;
			}
		}
		else {
			Date.Day = RemainingDays;
			Date.Year = Year;
			break;
		}
	}
	return Date;
}

// ----------------- Comparisons -----------------

bool AreDatesEqual(stDate Date1, stDate Date2) {
	return (Date1.Day == Date2.Day && Date1.Month == Date2.Month && Date1.Year == Date2.Year);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
	if (AreDatesEqual(Date1, Date2)) {
		return false;
	}
	else if (Date1.Year < Date2.Year) {
		return true;
	}
	else if (Date1.Year == Date2.Year && Date1.Month < Date2.Month) {
		return true;
	}
	else if (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day) {
		return true;
	}
	else {
		return false;
	}
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
	return !IsDate1BeforeDate2(Date1, Date2) && !AreDatesEqual(Date1, Date2);
}

enCompareDates CompareDates(stDate Date1, stDate Date2) {
	if (IsDate1AfterDate2(Date1, Date2)) {
		return enCompareDates::enAfter;
	}
	if (IsDate1BeforeDate2(Date1, Date2)) {
		return enCompareDates::enBefore;
	}
	return enCompareDates::enEqual;
}

bool IsOverLapPeriod(stPeriod Period1, stPeriod Period2) {
	if (CompareDates(Period2.EndDate, Period1.StartDate) == enCompareDates::enBefore
		||
		CompareDates(Period2.StartDate, Period1.EndDate) == enCompareDates::enAfter) {
		return false;
	}
	else {
		return true;
	}
}

// ----------------- Differences & vacations -----------------

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) {
	int Days = 0;
	short swapFlags = 1;

	if (!IsDate1BeforeDate2(Date1, Date2)) {
		swapDates(Date1, Date2);
		swapFlags = -1;
	}

	while (IsDate1BeforeDate2(Date1, Date2)) {
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return IncludeEndDay ? ++Days * swapFlags : Days * swapFlags;
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

short GetPeriodLength(stPeriod Period, bool IncludeEndDay = false) {
	return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}

bool IsDateWithinPeriod(stDate Date, stPeriod Period) {
	return (CompareDates(Date, Period.StartDate) != enCompareDates::enBefore
		&& CompareDates(Date, Period.EndDate) != enCompareDates::enAfter);
}

short CalculateDaysOfOverLap(stPeriod Period1, stPeriod Period2) {

	if (!IsOverLapPeriod(Period1, Period2)) {
		return 0;
	}

	int Period1Length = GetPeriodLength(Period1, true);
	int Period2Length = GetPeriodLength(Period2, true);
	short CounterOverLap = 0;

	if (Period1Length < Period2Length) {
		while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate) || AreDatesEqual(Period1.StartDate, Period1.EndDate)) {

			if (IsDateWithinPeriod(Period1.StartDate, Period2)) {
				CounterOverLap++;
			}

			Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
		}
	}
	else {
		while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate) || AreDatesEqual(Period2.StartDate, Period2.EndDate)) {

			if (IsDateWithinPeriod(Period2.StartDate, Period1)) {
				CounterOverLap++;
			}

			Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
		}
	}

	return CounterOverLap;
}

bool IsValidateDate(stDate Date) {
	//Check Month
	if (Date.Month < 1 || Date.Month > 12) {
		return false;
	}
	//Check Day
	if (Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year) || Date.Day < 1 ) {
		return false;
	}

	return true;
}