#include<iostream>
#include<cmath>
using namespace std;
float ReadNumber() {
	float number;
	cout << "Enter a number: ";
	cin >> number;
	return number;
}
int FloorFunction(float Number) {
	if (Number < 0) {
		return int(Number) - 1;
	}
	else
		return int(Number);
}
int main() {
	float Number = ReadNumber();
	cout << "My floor function: " << FloorFunction(Number) << "\n";
	cout << "C++ floor function: " << floor(Number) << "\n";
}