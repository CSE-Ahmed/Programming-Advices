#include<iostream>
#include<cmath>
using namespace std;
float ReadNumber()
{
	float number;
	cout << "Enter a number: ";
	cin >> number;
	return number;
}
float MySqrt(float Number) {
	return pow(Number, 0.5);
}
int main() {
	float number = ReadNumber();
	cout << "My MySqrt function: " << MySqrt(number) << endl;
	cout << "C++ sqrt function: " << sqrt(number) << endl;
	return 0;
}