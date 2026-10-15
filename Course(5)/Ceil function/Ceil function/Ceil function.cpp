#include<iostream>
#include<cmath>
using namespace std;
float ReadNumber() {
	float number;
	cout << "Enter a number: ";
	cin >> number;
	return number;
}
float GetFractionalPart(float number) {
	return number - (int)number;
}
int MyCeil(float Number) {
	if (abs(GetFractionalPart(Number)) > 0) {
		if (Number > 0)
			return (int)Number + 1;
		else
			return (int)Number;
	}
	else
		return (int)Number;
}
int main() {
	float number = ReadNumber();
	cout << "My MyCeil function: " << MyCeil(number) << endl;
	cout << "C++ ceil function: " << ceil(number) << endl;
	return 0;
}