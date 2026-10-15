#include<iostream>
using namespace std;
int ReadDay(){
    int day;
    cout << "Enter a day: ";
    cin >> day;
    return day;
}
string calculateDay(int day){
    switch(day){
        case 1:
            return "Sunday";
            break;
        case 2:
            return "Monday";
            break;
        case 3:
            return "Tuesday";
            break;
        case 4:
            return "Wednesday";
            break;
        case 5:
            return "Thursday";
            break;  
        case 6:
            return "Friday";
            break;
        case 7:
            return "Saturday";
            break;
        default:
            return "Invalid day";
    }
}
int main(){
    cout << calculateDay(ReadDay());
}