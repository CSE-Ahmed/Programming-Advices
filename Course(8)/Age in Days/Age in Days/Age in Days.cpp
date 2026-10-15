/*#include<iostream>
#include<ctime>
#pragma warning(disable : 4996)
using namespace std;

struct stDate {
	short Day;
	short Month;
	short Year;
};

stDate ReadDate(string Message) {
	stDate Date;
	cout << Message << endl;
	cout << "Enter Day: ";
	cin >> Date.Day;
	cout << "Enter Month: ";
	cin >> Date.Month;
	cout << "Enter Year: ";
	cin >> Date.Year;
	return Date;
}

bool IsLeapYear(short Year) {
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12) {
		return 0;
	}

	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

stDate GetSystemDate() {
	time_t t = time(0);
	tm* now = localtime(&t);
	stDate Date;
	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;
	return Date;
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
	stDate Date1 = ReadDate("Enter Your Birth Date ");
	stDate Date2 = GetSystemDate();
	int Days = GetDifferenceInDays(Date1, Date2);
	cout << "Your Age in Days is: " << Days << endl;
	return 0;
}*/

#pragma warning(disable:4996)
#include <iostream>
#include <ctime>
using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month;
	cout << "\nPlease enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "\nPlease enter a year? ";
	cin >> Year;
	return Year;
}

stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

stDate GetCurrentDate()
{
	stDate CurrentDate;

	time_t TimeInSeconds;
	TimeInSeconds = time(0);

	tm* pstrLocalTime;
	pstrLocalTime = localtime(&TimeInSeconds);

	CurrentDate.Day = pstrLocalTime->tm_mday;
	CurrentDate.Month = pstrLocalTime->tm_mon + 1;
	CurrentDate.Year = pstrLocalTime->tm_year + 1900;

	return CurrentDate;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year > Date2.Year) ? true : ((Date1.Year == Date2.Year) ? ((Date1.Month > Date2.Month) ? true : ((Date1.Month == Date2.Month) ? Date1.Day > Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return ((Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day));
}

bool isLeapYear(short Year)
{
	// if year is divisible by 4 AND not divisible by 100
	// OR if year is divisible by 400
	// then it is a leap year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
	short TotalDays = 0;
	for (int i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Year);
	}
	TotalDays += Day;
	return TotalDays;
}

int CalculateAgeInDays(stDate DateOfBirth, bool IsInclusive = false)
{
	stDate CurrentDate = GetCurrentDate();
	if (IsDate1AfterDate2(DateOfBirth, CurrentDate))
		return -1;
	else if (IsDate1EqualDate2(DateOfBirth, CurrentDate))
		return 0;
	else
	{

		short DifferenceBetweenTwoYears = CurrentDate.Year - DateOfBirth.Year;

		int AgeInDays = 0;

		if (DifferenceBetweenTwoYears != 0)
			AgeInDays += isLeapYear(DateOfBirth.Year) ? 366 : 365;

		for (short i = 1; i <= DifferenceBetweenTwoYears - 1; i++)
		{
			AgeInDays += isLeapYear(DateOfBirth.Year + i) ? 366 : 365;
		}

		short NumberOfDaysFromBeginingThisYear = NumberOfDaysFromTheBeginingOfTheYear
		(CurrentDate.Day, CurrentDate.Month, CurrentDate.Year);

		short NumberOfDaysFromBeginingBirthYear = NumberOfDaysFromTheBeginingOfTheYear
		(DateOfBirth.Day, DateOfBirth.Month, DateOfBirth.Year);

		AgeInDays += NumberOfDaysFromBeginingThisYear;
		AgeInDays -= NumberOfDaysFromBeginingBirthYear;

		return (IsInclusive) ? ++AgeInDays : AgeInDays;


	}
}

int main()
{
	stDate DateOfBirth;
	DateOfBirth = ReadFullDate();

	printf("Your Age is : %d Day(s).\n", CalculateAgeInDays(DateOfBirth));

	return 0;
}