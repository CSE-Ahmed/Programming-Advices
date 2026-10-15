#include<iostream>
#include"DateManager.h"
using namespace std;

int main() {
	stPeriod period = ReadPeriod();

	cout << "\nPeriod Length in Days: " << GetPeriodLength(period) << endl;
	cout << "\nPeriod Length in Days (Including End Day): " << GetPeriodLength(period, true) << endl;
}
