#include<iostream>
using namespace std;

struct stDate {
	short day;
	short month;
	short year;
};

stDate ReadDate() {
	stDate date;
	cout << "Enter day: ";
	cin >> date.day;
	cout << "Enter month: ";
	cin >> date.month;
	cout << "Enter year: ";
	cin >> date.year;
	return date;
}

bool CompareDates(stDate date1, stDate date2) {
	if (date1.year < date2.year) {
		return true;
	}
	else if (date1.year == date2.year) {
		if (date1.month < date2.month) {
			return true;
		}
		else if (date1.month == date2.month) {
			if (date1.day < date2.day) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	cout << "Enter Date 1:" << endl;
	cout << string(20, '-') << endl;
	stDate date1 = ReadDate();
	cout << string(20, '-') << endl;
	cout << "Enter Date 2:" << endl;
	stDate date2 = ReadDate();
	cout << string(20, '-') << endl;
	if (CompareDates(date1, date2)) {
		cout << "Date 1 is less than Date 2" << endl;
	}
	else {
		cout << "Date 1 is not less than Date 2" << endl;
	}
	return 0;
}