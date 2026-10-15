#include <iostream>
#include <cmath>
using namespace std;
int ReadNumber(){
    int num;
    cout << "Enter number: ";
    cin >> num; 
    return num;
}
void CalculatePower(int num){
    int power;
    for (int i = 2 ; i <= 4 ; i++){
        power = pow(num , i);
        cout << "the power " << i << " of " << num << " is: " << power <<endl;      
    }
}
int main(){
    CalculatePower(ReadNumber());
}