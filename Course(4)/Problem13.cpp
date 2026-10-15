#include<iostream>
using namespace std;
void ReadNumbers(int &Num1 ,int &Num2, int &Num3 ){
    cout << "Enter the first number: ";
    cin >> Num1;
    cout << "Enter the second number: ";
    cin >> Num2;
    cout << "Enter the third number: ";
    cin >> Num3;
}
int CheckMaximumOf3Numbers(int Num1 , int Num2, int Num3){
    if (Num1 > Num2){
        if (Num1 > Num3)
            return Num1;
        else 
            return Num3 ;
    }
    else{
        if (Num2 > Num3)
            return Num2;
        else
            return Num3;
    }
}
int main(){
    int Num1, Num2 , Num3;
    ReadNumbers(Num1, Num2, Num3);
    cout << "The maximum number is: " << CheckMaximumOf3Numbers(Num1, Num2, Num3) << endl;
}