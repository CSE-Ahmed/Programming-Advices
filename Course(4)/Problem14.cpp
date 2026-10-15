#include<iostream>
using namespace std;
void ReadNumbers(int &Num1, int &Num2){
    cout << "Enter the first number: " ;
    cin >> Num1;
    cout << "Enter the second number: ";
    cin >> Num2;
}
void BeforeSwap(int Num1 , int Num2){
    cout << "\nBefore swapping\n" ;
    cout << "\nNum1 = " << Num1 << "\n";
    cout << "Num2 = " << Num2 << "\n";
}
void Swap(int &Num1 , int &Num2){
    int temp;
    temp = Num1;
    Num1 = Num2;
    Num2 = temp;
}
void PrintSwap(int Num1 , int Num2){
    cout << "\nAfter swapping\n" ;
    cout << "\nNum1 = " << Num1 << "\n";
    cout << "Num2 = " << Num2 << "\n";
}
int main(){
    int Num1, Num2;
    ReadNumbers(Num1 , Num2);
    BeforeSwap(Num1,Num2);
    Swap(Num1,Num2);
    PrintSwap(Num1 , Num2);
}