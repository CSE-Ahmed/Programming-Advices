#include<iostream>
using namespace std;
int ReadNumberOfHours(){
    int hours;
    cout << "Enter the number of hours: ";
    cin >> hours;
    return hours;
}
float CalculateDays(int hours){
    float days = (float)hours / 24;
    return days;
}
float CalculateWeeks(int hours){
    float weeks = (float)hours / 168;
    return weeks;
}
int main(){
    float hours = ReadNumberOfHours();
    cout << "Days: " << CalculateDays(hours) << endl;
    cout << "Weeks: " << CalculateWeeks(hours) << endl;
}