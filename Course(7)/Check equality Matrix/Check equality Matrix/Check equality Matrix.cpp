#include<iostream>
using namespace std;
#define ROW 3
#define COL 3
int Random(int from , int to) {
	return rand() % (to - from + 1) + from;
}
void FillMatrix(int Matrix[ROW][COL], short row, short col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Matrix[i][j] = Random(1, 100);
		}
	}
}
void PrintMatrix(int Matrix[ROW][COL], short row, short col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %0*d ", 2, Matrix[i][j]);
		}
		cout << endl;
	}
}
int SumMatrix(int Matrix[ROW][COL], short row, short col) {
	short sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col;j++) {
			sum += Matrix[i][j];
		}
	}
	return sum;
}
bool CheckEquality(short Sum1, short Sum2, short row, short col) {
	if (Sum1 == Sum2) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	srand((unsigned)time(NULL));
	int Matrix[ROW][COL], Matrix2[ROW][COL];
	FillMatrix(Matrix, ROW, COL);
	FillMatrix(Matrix2, ROW, COL);
	cout << "Matrix1: \n";
	PrintMatrix(Matrix, ROW, COL);
	cout << "Matrix2: \n";
	PrintMatrix(Matrix2, 3, 3);
	short Sum1 = SumMatrix(Matrix, ROW, COL);
	short Sum2 = SumMatrix(Matrix2, ROW, COL);
	cout << "-------------------------------------\n";
	if (CheckEquality(Sum1, Sum2, ROW, COL)) {
		cout << "Sum1 = " << Sum1 << "\nSum2 = " << Sum2 << endl;
		cout << "The Matrix is Equality\n";
	}
	else {
		cout << "Sum1 = " << Sum1 << "\nSum2 = " << Sum2 << endl;
		cout << "The Matrix doesn't Equality\n";
	}
}