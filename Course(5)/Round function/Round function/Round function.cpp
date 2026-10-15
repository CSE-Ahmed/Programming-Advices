#include <iostream>
#include<cmath>
using namespace std;
double ReadNumber() {
	double num;
	cout << "Enter a number: ";
	cin >> num;
	return num;
}
float GetFractionalPart(float Number) {
	return Number - int(Number);
}
int RoundNumber(float Number) {
	int InPart = int(Number);
	float FrPart = GetFractionalPart(Number);
	if (abs(FrPart) >= 0.5) {
		if (InPart >= 0) {
			return InPart + 1;
		}
		else {
			return InPart - 1;
		}
	}
	else {
		return InPart;
	}
}
int main() {
	float Number = ReadNumber();
	int RoundedNumber = RoundNumber(Number);
	cout << "\n My round function \n" << RoundedNumber << "\n";
	cout << "\n c++ round function \n" << round(Number) << "\n";
	return 0;
}
