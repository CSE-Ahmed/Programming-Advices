#include <iostream>
using namespace std;
struct PiggyBank{
    int pinnes;
    int nickels;
    int dimes;
    int quarters;
    int dollar;
};
PiggyBank stPiggyBank(){
    PiggyBank piggyBank;
    cout << "Enter the number of pinnes: ";
    cin >> piggyBank.pinnes;
    cout << "Enter the number of nickels: ";
    cin >> piggyBank.nickels;
    cout << "Enter the number of dimes: ";
    cin >> piggyBank.dimes;
    cout << "Enter the number of quarters: ";
    cin >> piggyBank.quarters;
    cout << "Enter the number of dollar: ";
    cin >> piggyBank.dollar;
    return piggyBank;
}
float calculatePinnes(PiggyBank piggyBank){
    int pinnes = piggyBank.pinnes * 1 + piggyBank.nickels * 5 + piggyBank.dimes * 10 + piggyBank.quarters * 25 + piggyBank.dollar * 100;
    return pinnes;
}
float calculateDollars(int pinnes){
    return (float)pinnes / 100.0;
}
int main(){
    int pinnes = calculatePinnes(stPiggyBank());
    cout << "Total pinnes: " << pinnes<< endl;
    cout << "Total dollars: " << calculateDollars(pinnes) << endl;
}