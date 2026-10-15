#include <iostream>
using namespace std;
enum PerfectOrNot {Perfect = 1 , NotPerfect = 2};
int ReadNumber() {
    int Number;
    do {
		cout << "Enter a positive number: ";
		cin >> Number;
    }
	while (Number <= 0);
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
	else {
		return PerfectOrNot::NotPerfect;
	}
}	
void PrintResult(PerfectOrNot Result) {
	if (Result == PerfectOrNot::Perfect) {
		cout << "The number is perfect." << endl;
	}
	else {
		cout << "The number is not perfect." << endl;
	}
}
int main()
{
	PrintResult(CheckPerfectNumber(ReadNumber()));
}