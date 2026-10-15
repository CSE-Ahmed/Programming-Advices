#include<iostream>
using namespace std;
int ReadATMPasscode(){
    int passcode;
    cout << "Enter your ATM passcode: ";
    cin >> passcode;
    return passcode;
}
string ATMTransaction(int passcode){
    if(passcode == 1234){
        return "Your balance is 7500$";
    }
    return "Wrong passcode";
}
int main(){
    cout << ATMTransaction(ReadATMPasscode());
}