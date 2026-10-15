#include<iostream>
#include<cmath>
using namespace std;
float Readcircumference(){
    float L;
    cout << "enter the length of circum ference: ";
    cin >> L;
    return L;
}
float Area(float L){
    const float PI = 3.141592653589793238;
    float area = (pow (L,2)) / (4*PI);
    return area;
}
void PrintArea(float area){
    cout << "The area of the circle is: " << area << endl;
}
int main(){
    PrintArea(Area(Readcircumference()));
}