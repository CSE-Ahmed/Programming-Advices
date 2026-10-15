#include <iostream>
using namespace std;
int ReadNumber(){
    int number;
    cout << "Enter Your number: ";
    cin >> number;
    return number;
}
int CalculatFactorialUsingForLoop(int number){
    int Factorial = 1;
    for(int i = 1 ; i <= number ; i ++){
        Factorial *= i ;
    }
    return Factorial;
}
int CalculateFactorialUsingWhileLoop(int number){
    int Factorial;
    int counter = 1;
    while(counter < number){
        Factorial *= counter;
        counter++;
    }
    return Factorial;
}
int CalculateFactorialUsingDo_While(int number){
    int Factorial;
    int counter = 1;
    do{
        Factorial *= counter;
        counter++;
    }
    while (counter < number);
    return Factorial;
}
void PrintResult(int Factorial){
    cout << "The factorial is: " << Factorial <<endl;
}
int main(){
    PrintResult(CalculatFactorialUsingForLoop(ReadNumber()));
    PrintResult(CalculateFactorialUsingWhileLoop(ReadNumber()));
    PrintResult(CalculateFactorialUsingDo_While(ReadNumber()));
}