#include<iostream>
#include<cstdlib>
using namespace std;
int ReadNUmber(string Message) {
	int Number;
	do {
		cout << Message << "\n";
		cin >> Number;
	} while (Number <= 0 || Number > 100);
	return Number;
}
int RandomNumber(int from, int to) {
	int Random = rand() % (to - from + 1) + from;
	return Random;
}
void FillArray(int Arr[], int LengthArr) {
	for (int i = 0; i < LengthArr; i++) {
		Arr[i] = RandomNumber(1, 100);
	}
}
void PrintArray(int Arr[], int LengthArr) {
	for (int i = 0; i < LengthArr; i++) {
		cout << Arr[i] << " ";
	}
	cout << "\n";
}
int IsEven(int Arr[], int LengthArr) {
	int count = 0;
	for (int i = 0; i < LengthArr; i++) {
		if (Arr[i] % 2 == 0) {
			count++;
		}
	}
	return count;
}
int main() {
	srand((unsigned)time(NULL));
	int Arr[100];
	int LengthArr = ReadNUmber("Enter the length of the array (1-100): ");
	FillArray(Arr, LengthArr);
	cout << "\nArray elements\n";
	PrintArray(Arr, LengthArr);
	cout << "\nCount of even numbers: " << IsEven(Arr, LengthArr) << "\n";
}
