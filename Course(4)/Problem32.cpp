#include<iostream>
#include<cmath>
using namespace std;
void ReadNumbers(int &Num , int &power){
    cout << "Enter the number: ";
    cin >> Num;
    cout << "Enter the power: ";
    cin >> power;
}
int Power(int Num , int power){
    return pow(Num , power);
}
int main(){
    int Num , power;
    ReadNumbers(Num , power);
    cout << "The result is: " << Power(Num , power) << endl;
    return 0;
}