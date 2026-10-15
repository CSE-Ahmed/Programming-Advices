#include<iostream>
#include<iomanip>
using namespace std;
int Random(int from, int to) {
	int RandomNumber = rand() % (to - from + 1) + from;
	return RandomNumber;
}
void FillMatrix(int ARR[3][3], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col;j++) {
			ARR[i][j] = Random(1, 100);
		}
	}
}
void PrintMatrix(int ARR[3][3], int row, int col) {
	cout << "The following is the matrix after filled: \n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << setw(3) << ARR[i][j] << " ";
		}
		cout << endl;
	}
}
int SumCol(int ARR[3][3], int row, int col) {
	int sum = 0;
	for (int i = 0; i < row; i++) {
		sum += ARR[i][col];
	}
	return sum;
}
void sumEachColInArray(int ARR[3][3], int Arr[3], int row, int col) {
	for (int i = 0; i < col; i++) {
		Arr[i] = SumCol(ARR, row, i);
	}
}
void PrintSumOfEachCol(int Arr[3], int col) {
	cout << "The following is the sum of each col: \n";
	for (int i = 0; i < col; i++) {
		cout << "the sum of col [" << i << "] is = " << Arr[i] << endl;
	}
}
int main() {
	srand((unsigned)time(NULL));
	int ARR[3][3], Arr[3];
	FillMatrix(ARR, 3, 3);
	PrintMatrix(ARR, 3, 3);
	sumEachColInArray(ARR, Arr, 3, 3);
	PrintSumOfEachCol(Arr, 3);
}