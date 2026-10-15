#include<iostream>
using namespace std;
enum PerfectOrNot { Perfect = 1, NotPerfect = 2 };
int ReadNumber() {
	int Number;
	do {
		cout << "Enter a positive number: ";
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
PerfectOrNot CheckPerfectNumber(int Number) {
	int sum = 0;
	for (int i = 1; i < Number; i++) {
		if (Number % i == 0)
			sum = sum + i;

	}
	if (sum == Number) {
		return PerfectOrNot::Perfect;
	}
    return PerfectOrNot::NotPerfect;
}
void PrintResult(int Number) {
	for (int i = 1; i < Number; i++) {
		if (CheckPerfectNumber(i) == PerfectOrNot::Perfect) {
			cout << i << endl;
		}
	}
}
int main()
{
	PrintResult(ReadNumber());
}