#include<iostream>
using namespace std;
enum Month{
    January = 1, February, March, April, May, June, July, August, September, October, November, December
};
int ReadMonth(){
    int month;
    cout << "Enter a month: (1) January, (2) February, (3) March, (4) April, (5) May, (6) June, (7) July, (8) August, (9) September, (10) October, (11) November, (12) December: ";
    cin >> month;
    return month;
}
Month CheckMonth(int month){
    return (Month)ReadMonth();
}
string checkMonth(){
    switch(CheckMonth(ReadMonth())){
        case January:
            return "January";
            break;
        case February:
            return "February";
            break;
        case March:
            return "March";
            break;
        case April:
            return "April";
            break;
        case May:
            return "May";
            break;
        case June:
            return "June";
            break;
        case July:
            return "July";
            break;
        case August:
            return "August";
            break;
        case September:            
            return "September";
            break;                      
        case October:

            return "October";
            break;  
        case November:

            return "November";
            break;
        case December:
        
            return "December";
            break;  

        default:
            return "Invalid month";
    }
}
int main(){
    cout << checkMonth();
}