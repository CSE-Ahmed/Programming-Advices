#include<iostream>
#include<cmath>
using namespace std;
void ReadNumber(float &a , float &d){
    
    cout << "Enter the lingth: ";
    cin >> a;
    cout << "Enter diagonal: ";
    cin >> d;
}
float CalculateArea(float a , float d){
    return a * sqrt(pow (d,2)-pow(a,2));
}
void PrintArea(float Area){
    cout << "Area : " << Area << endl;
}
int main(){
    float a , d ; 
    ReadNumber(a , d);
    PrintArea(CalculateArea(a , d));
}