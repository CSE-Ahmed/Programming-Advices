#include<iostream>
using namespace std;
void fillArray(int Arr[], int &lengthArr) {
	lengthArr = 10;
	Arr[0] = 10;
	Arr[1] = 10;
	Arr[2] = 10;
	Arr[3] = 10;
	Arr[4] = 20;
	Arr[5] = 20;
	Arr[6] = 20;
	Arr[7] = 50;
	Arr[8] = 50;
	Arr[9] = 90;
}
void PrintArray(int Arr[], int& LengthArr) {
	for (int i = 0; i < LengthArr; i++) {
		cout << Arr[i] << " ";
	}
	cout << endl;
}
short FindNumberPositionINArry( int Number,int Arr[], int LengthArr) {
	for (int i = 0; i < LengthArr; i++) {
		if (Arr[i] == Number) {
			return i;
		}
	}
	return -1;
}
bool IsNumberInArray(int Number,int Arr[], int LengthArr) {
	return FindNumberPositionINArry(Number,Arr,LengthArr) != -1;
}
void AddArrayElement(int Number,int Arr[], int lengthArr) {
	lengthArr++;
	Arr[lengthArr - 1] = Number;
}
void CopyDistinctNumbersToArray(int ArrSource[], int ArrDest[], int LengthArrSource, int& LengthArrDest) {
	for (int i = 0; i < LengthArrSource; i++) {
		if (!IsNumberInArray(ArrSource[i], ArrDest, LengthArrDest)) {
			AddArrayElement(ArrSource[i], ArrDest, LengthArrDest);
			LengthArrDest++;
		}
	}
}
int main() {
	int ArrSource[100], ArrDest[100], LengthArrSource, LengthArrDest = 0;
	fillArray(ArrSource, LengthArrSource);
	cout << "Array 1 elements\n";
	PrintArray(ArrSource, LengthArrSource);
	CopyDistinctNumbersToArray(ArrSource, ArrDest, LengthArrSource, LengthArrDest);
	cout << "Array 2 elements\n";
	PrintArray(ArrDest, LengthArrDest);
}