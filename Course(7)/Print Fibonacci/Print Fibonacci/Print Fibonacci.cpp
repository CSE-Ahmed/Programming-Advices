#include<iostream>
using namespace std;
void PrintFibonacci(short Number) {
	short FebNumber = 0;
	short prev2 = 0, prev1 = 1;
	cout << "1 ";
	for (short i = 2; i <= Number; i++) {
		FebNumber = prev1 + prev2;
		cout << FebNumber << " ";
		prev2 = prev1;
		prev1 = FebNumber;
	}
}

int main() {
	PrintFibonacci(10);
}