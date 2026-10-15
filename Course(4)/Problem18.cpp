#include<iostream>
#include<cmath>
using namespace std;
const float PI = 3.14159;
void ReadRadius(float &r){
    cout << "Enter the radius of circle: ";
    cin >> r;
}
float Area(float r){
    return PI * pow(r , 2);
}
void PrintArea(float area){
    cout << "The area of the circle is: " << area << endl;
}
int main(){
    float r;
    ReadRadius(r);
    PrintArea(Area(r));
}