#include<iostream>
#include"DateManager.h"
using namespace std;

int main() {
	cout << "Enter Period 1 : \n";
	stPeriod Period1 = ReadPeriod();
	cout << "\nEnter Period2 : \n";
	stPeriod Period2 = ReadPeriod();
	

	cout << "OverLap Days count is : " << CalculateDaysOfOverLap(Period1, Period2) << " day(s)\n";
}