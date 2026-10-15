#include<iostream>
using namespace std;
enum EvenOdd{even = 1 , odd = 2};
int ReadNumber(){
    int number;
    cout << "Enter number: ";
    cin >> number;
    return number;
}
EvenOdd CheckEvenOrOdd(int number){
    if (number % 2 != 0)
        return EvenOdd::odd;
    else
        return EvenOdd::even;
}
int SumOddNumbers(int number){
    int sum = 0 ;
    for (int i = 0 ; i < number ; i++){
        if (CheckEvenOrOdd(i) == EvenOdd::odd)
             sum = sum + i;
    }
    return sum;
}
void PrintSumming(int sum){
    cout << "The sum of odd numbers: " << sum << "\n";
}
int main(){
    PrintSumming(SumOddNumbers(ReadNumber()));
}