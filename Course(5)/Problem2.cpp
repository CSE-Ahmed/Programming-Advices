#include<iostream>
#include <cmath>
#include<string>
using namespace std;
enum enPrimeNumber { prime = 1 , NotPrime = 2 };
int ReadPrime() {
	int Number;
	do {
		cout << "Enter a positive number: ";
		cin >> Number;
	}
	while (Number <= 0 );
	return Number;	
}
enPrimeNumber CheckPrime(int Number) {
	int M = round(Number/2);
	for (int i = 2; i <= M; i++) {
		if (Number % i == 0) {
			return enPrimeNumber::NotPrime;
		}
		
	}
	return enPrimeNumber::prime;
}
void PrintPrimeNumber(int Number) {
	for (int i = 2; i <= Number ; i++) {
		if (CheckPrime(i) == enPrimeNumber::prime) {
			cout << i << endl;
		}
	}
}
int main() {
	PrintPrimeNumber(ReadPrime());
}
