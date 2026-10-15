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
void PrintMatrix(int ARR[3][3], int row , int col) {
	cout << "The following is the matrix after filled: \n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << setw(3) << ARR[i][j] << " ";
		}
		cout << endl;
	}
}
int SumCol(int ARR[3][3] , int row , int col) {
	int sum = 0; 
	for (int i = 0; i < row; i++) {
		sum += ARR[i][col];
	}
	return sum;
}
void SumEachCol(int ARR[3][3] , int row , int col) {
	cout << "the following is the sum of each col: \n";
	for (int i = 0; i < col; i++) {
		cout << "the sum of Row [" << i << "] is = " << SumCol(ARR, row, i) << endl;
	}
}
int main() {
	int ARR[3][3];
	FillMatrix(ARR, 3, 3);
	PrintMatrix(ARR, 3, 3);
	SumEachCol(ARR, 3, 3);
}