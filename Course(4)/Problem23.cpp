#include <iostream>
#include <cmath>
using namespace std;
void Read3SideOfTriangel(float &A, float &B, float &C)
{
    cout << "Enter the first side of triangle: ";
    cin >> A;
    cout << "Enter the second side of triangle: ";
    cin >> B;
    cout << "Enter the third side of triangle: ";
    cin >> C;
}
float Area(float A, float B, float C, float P)
{
    const float PI = 3.141592653589793238;
    P = (A + B + C) / 2;
    float area = (A * B * C) / (4 * (sqrt(P * (P - A) * (P - B) * (P - C))));
    area = PI * pow(area, 2);
    return area;
}
void PrintArea(float area)
{
    cout << "The area of the circle: " << area << endl;
}
int main()
{
    float A, B, C, P;
    Read3SideOfTriangel(A, B, C);
    PrintArea(Area(A, B, C, P));
}