#include<iostream>
using namespace std;

struct sDate
{
	short Year;
	short Month;
	short Day;
};

short ReadNumber(string Message){
	short Number;
	cout << Message;
	cin >> Number;
	return Number;
}

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12) {
		return 0;
	}

	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
		days[Month - 1];
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

sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
	sDate Date;
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

int main()
{
	short Day = ReadNumber("Please enter a Day? ");
	short Month = ReadNumber("Please enter a Month? ");
	short Year = ReadNumber("Please enter a Year? ");
	short DaysOrderInYear =
		NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);
	cout << "\nNumber of Days from the begining of the year is " << DaysOrderInYear << "\n\n";
	short AddDays = ReadNumber("Please enter the number of days to add? ");
	sDate Date;
	Date = GetDateFromDayOrderInYear(DaysOrderInYear + AddDays, Year);
	cout << "Date for [" << DaysOrderInYear + AddDays << "] is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
	system("pause>0");
	return 0;
}