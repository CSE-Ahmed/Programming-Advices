#include<iostream>
using namespace std;
int Random(int from, int to) {
	return rand() % (to - from + 1) + from;
}
void FillMatrix(int Matrix[3][3], short row, short col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Matrix[i][j] = Random(1, 10);
		}
	}
}
void PrintMatrix(int Matrix[3][3], short row, short col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %0*d ", 2, Matrix[i][j]);
		}
		cout << endl;
	}
}
int SumMatrix(int Matrix[3][3], short row, short col) {
	short sum = 0;
	for (int i = 0; i < row;i++) {
		for (int j = 0; j < col; j++) {
			sum += Matrix[i][j];
		}
	}
	return sum;
}
int main() {
	int Matrix[3][3];
	FillMatrix(Matrix, 3, 3);
	cout << "The matrix: \n";
	PrintMatrix(Matrix, 3, 3);
	cout << "The sum of this matrix is : " << SumMatrix(Matrix, 3, 3) << endl;
}