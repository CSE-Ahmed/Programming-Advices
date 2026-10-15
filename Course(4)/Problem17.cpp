#include<iostream>
#include<cmath>
using namespace std;
void ReadNumbers(float &a , float&h){
    cout << "Enter the Base length: " ;
    cin >> a ;
    cout << "Enter the hieght: ";
    cin >> h;
}
float AreaOfTriangle(float a , float h){
    return 0.5 * h * a;
}
void PrintArea(float area){
    cout << "The area of triangle is: " << area << endl;
}
int main(){
    float a,h;
    ReadNumbers(a , h);
    PrintArea(AreaOfTriangle(a, h));
}