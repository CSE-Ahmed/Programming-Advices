#include<iostream>
using namespace std;

short ReadNumber(string Message) {
	short Number;
	cout << Message;
	cin >> Number;
	return Number;
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDayNames[DayOfWeekOrder];
}

short CountDayFromWeek(short year, short Month, short Day) {
	short a = (14 - Month) / 12;
	short y = year - a;
	short m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

int main() {
	short Year  = ReadNumber("Enter Year  : ");
	short Month = ReadNumber("Enter Month : ");
	short Day   = ReadNumber("Enter Day   : ");

	short CountDayOfWeek = CountDayFromWeek(Year, Month, Day);

	cout << "\nDate : " << Day << "/" << Month << "/" << Year << endl;

	cout << "Day Order : " << CountDayOfWeek << endl;

	cout << "Day Name  : " << DayShortName(CountDayOfWeek) << endl;
}

void PrintCalendar(short Year, short Month) {
    short MonthsDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (Month < 1 || Month > 12) {
        return;
    }

    if (Month == 2 && IsLeap(Year)) {
        MonthsDays[1] = 29;
    }

    cout << "\n  _______________" << Months[Month] << "_______________\n\n";
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

    short currentColumn = CountDayFromWeek(Year, Month, 1);

    for (short i = 0; i < currentColumn; i++) {
        cout << "     ";
    }

    for (short i = 1; i <= MonthsDays[Month - 1]; i++) {
        cout << setw(5) << i;
        if (++currentColumn == 7) {
            currentColumn = 0;
            cout << "\n";
        }
    }
    cout << "\n  _________________________________\n";
}