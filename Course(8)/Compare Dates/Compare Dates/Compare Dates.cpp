#include<iostream>
#include "DateManager.h"
using namespace std;

int main() {
	cout << "Enter Date 1 : \n\n";
    stDate Date1 = ReadDate();

	cout << "Enter Date 2 : \n\n";
	stDate Date2 = ReadDate();

	cout << "Compare Result = " << CompareDates(Date1, Date2) << endl;
}