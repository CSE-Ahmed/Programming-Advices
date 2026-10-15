#include<iostream>
#include"DateManager.h"
using namespace std;



int main() {
	cout << "Enter Date1:" << endl;
	stDate Date1 = ReadDate();

	cout << "\nEnter Date2:" << endl;
	stDate Date2 = ReadDate();
	if (IsDate1AfterDate2(Date1, Date2)) {
		cout << "\nDate1 is after Date2" << endl;
	}
	else {
		cout << "\nDate1 is not after Date2" << endl;
	}
	return 0;
}