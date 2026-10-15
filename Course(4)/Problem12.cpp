#include<iostream>
using namespace std;
void ReadNumbers(int &Num1 ,int &Num2 ){
    cout << "Enter the first number: ";
    cin >> Num1;
    cout << "Enter the second number: ";
    cin >> Num2;
}
int CheckMaximum(int Num1 , int Num2){
    if (Num1 > Num2)
        return Num1 ;
    else if (Num2 > Num1)
        return Num2;
    else 
         cout << "Num 1 = Num 2";
}
int main(){
    int Num1, Num2;
    ReadNumbers(Num1, Num2);
    cout << "The maximum number is: " << CheckMaximum(Num1, Num2) << endl;
}
