#include <iostream>
using namespace std;
enum EvenOrOdd{even = 1 , odd = 2};
int ReadNumber(){
    int number;
    cout << "Enter number: ";
    cin >> number;
    return number;
}
int CheckEvenOrOdd(int number){
    if (number%2==0)
        return EvenOrOdd::even;
    else
        return EvenOrOdd::odd;
}
int Sum(int number){
    int sum = 0 ;
    for (int counter = 0 ; counter <= number ; counter++){
        if (CheckEvenOrOdd(counter) == EvenOrOdd::even)
        {
            sum = sum + counter;
        }
        
    }
    return sum;
}
void PrintSum(int sum){
    cout << "The sum of even numbers is: " << sum << endl;
}
int main(){
    PrintSum(Sum(ReadNumber()));
}