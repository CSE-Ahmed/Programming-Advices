#include<iostream>
#include<cmath>
using namespace std;
int ReadNumber(string Message) {
	int Number;
	cout << Message << "\n";
	cin >> Number;
	return Number;
}
int Abs(int Number) {
	if (Number < 0)
		return -Number;
	else
		return Number;
}
int main() {
	int Num = ReadNumber("Enter a number: ");
	cout << "My Abs function :";
	cout << Abs(Num) << "\n";
	cout << "C++ Abs function :";
	cout << abs(Num) << "\n";	
}