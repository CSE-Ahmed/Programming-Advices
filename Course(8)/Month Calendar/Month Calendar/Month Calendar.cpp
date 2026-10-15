#include<iostream>
#include<iomanip>
using namespace std;

string Months[13] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

short ReadNumber(string Message) {
    short Number;
    cout << Message;
    cin >> Number;
    return Number;
}

bool IsLeap(short Year) {
    return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

short CountDayFromWeek(short Year, short Month, short Day) {
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

void PrintCalendar(short Year, short Month) {
    short Monthsday[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    if (Month < 1 || Month >12) {
        return;
    }

    if (Month == 2 && IsLeap(Year)) {
        Monthsday[1] = 29;
    }

    cout << "----------------" << Months[Month] << "----------------\n";

    cout << "  Sun  Mon  Tus  Wed  Thu  Fri  Sat\n";

    short CurrentDay = CountDayFromWeek(Year, Month, 1);

    for (short i = 0; i < CurrentDay; i++) {
        cout << "     ";
    }

    for (short i = 1; i < Monthsday[Month - 1]; i++) {
        cout << setw(5) << i;
        if (++CurrentDay == 7) {
            CurrentDay = 0;
            cout << "\n";
        }
    }

    cout << "\n-----------------------------------\n";

    }

int main() {
    short Year = ReadNumber("Enter Year : ");
    short Month = ReadNumber("Enter Month : ");

    PrintCalendar(Year, Month);

    system("pause>0");
    return 0;
}