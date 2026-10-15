#include<iostream>
using namespace std;
int ReadNumber(){
    int Num;
    do{
       cout << "Enter positive digit number: ";
        cin >> Num;
    }
    while(Num < 0);
    return Num;
}
int ReverseOfDigits(int Num){
    int Num2 = 0 , Remainder = 0;
    while (Num > 0){
        Remainder = Num % 10;
        Num = Num / 10;
        Num2 = Num2 * 10 + Remainder;
    }
    return Num2;
}
int main(){
    cout <<  ReverseOfDigits(ReadNumber()) ;
    return 0;
}