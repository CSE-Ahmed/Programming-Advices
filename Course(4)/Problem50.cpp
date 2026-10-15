#include<iostream>
using namespace std;
int ReadATMPassCode(){
    int passcode;
    cout << "Enter your ATM passcode: ";
    cin >> passcode;
    return passcode;
}
bool Login(){
    int passcode;
    int counter = 3;
    do{
        counter--;
        passcode = ReadATMPassCode();
        if (passcode == 1234){
            return true;
        }
        else{
            cout << "Wrong passcode. Try again. You have " << counter << " attempts left." << endl;
        }
    }
    while(passcode != 1234 && counter > 0);
    return false;
}
int main(){
    if (Login()){
        system("color 2F");
        cout << "Your balance is 7500$";
    }
    else{
        cout << "Your account is locked. Please contact the bank.";
    }
}