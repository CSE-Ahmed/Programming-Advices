#include<iostream>
#include"DateManager.h"
using namespace std;

int main() {
	stDate Date = ReadDate();
	
	if (IsValidateDate(Date)) {
		cout << "\nDate is validated\n";
	}
	else {
		cout << "\nDate isn't validated\n";
	}
}