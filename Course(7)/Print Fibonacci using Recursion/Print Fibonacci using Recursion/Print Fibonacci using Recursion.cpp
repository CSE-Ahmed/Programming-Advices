#include<iostream>
using namespace std;
void PrintFibonacciWithSeries(short Number, short prev1, short prev2) {
	short FebNumber = 0;
	
	if (Number > 0) {
		FebNumber = prev1 + prev2;
		cout << FebNumber << " ";
		prev2 = prev1;
		prev1 = FebNumber;
		PrintFibonacciWithSeries(Number - 1, prev1, prev2);
	}
}
int main() {
	PrintFibonacciWithSeries(10, 0, 1);
}