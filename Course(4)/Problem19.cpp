#include<iostream>
#include<cmath>
using namespace std;
const float PI = 3.14159;
void ReadDiameter(float &d){
    cout << "Enter the diameter of circle: ";
    cin >> d;
}
float Area(float d){
    return (PI * pow(d , 2)) / 4 ;
}
void PrintArea(float area){
    cout << "The area of the circle is: " << area << endl;
}
int main(){
    float d;
    ReadDiameter(d);
    PrintArea(Area(d));
}