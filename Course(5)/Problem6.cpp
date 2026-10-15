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
int sumOfDigits(int Num){
    int sum = 0 , Remainder = 0;
    while (Num > 0){
        Remainder = Num % 10;
        Num = Num / 10;
        sum = sum + Remainder;
    }
    return sum;
}
int main(){
    cout << sumOfDigits(ReadNumber()) << "\n";
    return 0;
}