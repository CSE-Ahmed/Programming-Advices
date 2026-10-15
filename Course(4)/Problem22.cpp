#include<iostream>
#include<cmath>
using namespace std;
void ReadNumbers(float &A , float &B){
    cout << "Enter the length of base: " ;
    cin >> A ; 
    cout << "Enter the length of triangle: ";
    cin >> B;
}
float Area(float A , float B){
    const float PI = 3.141592653589793238;
    float area = PI * (pow(B,2)/4) * ((2 * A - B) / (2 * A + B));
    return area;
}
void PrintArea(float area){
    cout << "The area of the circle is: " << area << endl;
}
int main(){
    float A , B ;
    ReadNumbers(A,B);
    PrintArea(Area(A,B));
}