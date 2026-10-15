#include<iostream>
using namespace std;
int ReadNumber(){
    int number;
    cout << "Enter a number: ";
    cin >> number;
    return number;
}
int Sum(int number){
    int sum = 0;
    do{
        sum += number;
        number = ReadNumber();
    }
    while(number != -99);
    return sum;
}
int main(){
    cout << Sum(ReadNumber());
}