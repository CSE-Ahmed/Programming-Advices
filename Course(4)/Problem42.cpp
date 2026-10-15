#include<iostream>
using namespace std;
struct Time{
    int days;
    int hours;
    int minutes; 
    int seconds;
};
Time ReadTime(){
    Time time;
    cout << "Enter days: ";
    cin >> time.days;
    cout << "Enter hours: ";
    cin >> time.hours;
    cout << "Enter minutes: ";
    cin >> time.minutes;
    cout << "Enter seconds: ";
    cin >> time.seconds;
    return time;
}
float DaystoSeconds(Time time){
    return time.days * 24 * 60 * 60;
}
float HourstoSeconds(Time time){
    return time.hours * 60 * 60;
}
float MinutestoSeconds(Time time){
    return time.minutes * 60;
}
float TotalSeconds(Time time){
    return DaystoSeconds(time) + HourstoSeconds(time) + MinutestoSeconds(time) + time.seconds;
}
int main(){
    cout << "Total seconds: " << TotalSeconds(ReadTime());
}