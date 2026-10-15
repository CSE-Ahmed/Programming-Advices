#include<iostream>
#include"DateManager.h"
using namespace std;

int main() {
	cout << "Enter Period 1:\n\n";
	stPeriod Period1 = ReadPeriod();
	cout << "\nEnter Period 2:\n\n";
	stPeriod Period2 = ReadPeriod();
	if (IsOverLapPeriods(Period1, Period2)) {
		cout << "\nThe periods overlap." << endl;
	}
	else {
		cout << "\nThe periods do not overlap." << endl;
	}
	return 0;
}