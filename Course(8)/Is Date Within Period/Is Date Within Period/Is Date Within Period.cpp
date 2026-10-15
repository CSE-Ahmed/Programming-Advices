#include<iostream>
#include"DateManager.h"
using namespace std;

int main() {
	stPeriod Period = ReadPeriod();
	cout << "\nEnter Date : \n";
	stDate Date = ReadDate();
	if (IsDateWithinPeriod(Date, Period)) {
		cout << "\nThe date is within the period.\n";
	}
	else {
		cout << "\nThe date is not within the period.\n";
	}
	return 0;
}