#include<iostream>
#include "DateManager.h"
using namespace std;



int main() {
	cout << "Enter the start of vacation date: \n";
	stDate StartDate = ReadDate();
	cout << "\nEnter the end of vacation date: \n\n";
	stDate EndDate = ReadDate();

	cout << "\nVacation from : " << DayOfWeekName(DayOfWeekOrder(StartDate)) << " , " << StartDate.Day << "/" << StartDate.Month << "/" << StartDate.Year << endl;
	cout << "Vacation to : " << DayOfWeekName(DayOfWeekOrder(EndDate)) << " , " << EndDate.Day << "/" << EndDate.Month << "/" << EndDate.Year << endl;
	cout << "\nActual Vaction days is : " << CalculateVacationDays(StartDate, EndDate) << " day(s)." << endl;
}