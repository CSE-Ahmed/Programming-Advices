#include<iostream>
using namespace std;
void ReadNumbers(float &A , float &B){
    cout << "Enter the length: " ;
    cin >> A;
    cout << "Enter the width: ";
    cin >> B;
}
float CalculateArea(float A , float B){
    return A * B;
}
void printResult(float area){
    cout << "The area of rectangle is: " << area << "\n";
}
int main(){
    float A , B;
    ReadNumbers(A , B);
    printResult(CalculateArea(A , B));
}