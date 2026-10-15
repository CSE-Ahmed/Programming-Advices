#include<iostream>
#include"DateManager.h"
using namespace std;

int main() {
	cout << "Enter the start date of your vacation:\n\n";
	
	stDate StartDate = ReadDate();

	short VacationDays = ReadNumber("\nEnter the number of vacation days: ");

	stDate DateTo = CalculateReturnDate(StartDate, VacationDays);
	
	string DayName = DayOfWeekName(DayOfWeekOrder(DateTo));
	
	cout << "\nReturn in : " << DayName << " , " << DateTo.Day << " / " << DateTo.Month << " / " << DateTo.Year << endl;
}