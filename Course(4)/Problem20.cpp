#include<iostream>
#include<cmath>
using namespace std;
const float PI = 3.14159;
void ReadLingth(float &a){
    cout << "Enter the length of square: ";
    cin >> a;
}
float Area(float a){
    return  (PI * pow(a , 2)) / 4;
}
void PrintArea(float area){
    cout << "The area of the circle is: " << area << endl;
}
int main(){
    float a;
    ReadLingth(a);
    PrintArea(Area(a));
}