#include<iostream>
#include<iomanip>
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
void MultiTwoMatrix(int Matrix[3][3], int Matrix2[3][3], int Matrix3[3][3], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Matrix3[i][j] = Matrix[i][j] * Matrix2[i][j];
		}
	}
} 
int main() {
	srand((unsigned)time(NULL));
	int Matrix[3][3], Matrix2[3][3], Matrix3[3][3];
	FillMatrix(Matrix, 3, 3);
	FillMatrix(Matrix2, 3, 3);
	cout << "the following is the first Matrix: \n";
	PrintMatrix(Matrix, 3, 3);
	cout << "The following is the second Matrix: \n";
	PrintMatrix(Matrix2, 3, 3);
	MultiTwoMatrix(Matrix, Matrix2, Matrix3, 3, 3);
	cout << "The following is the matrix after multi the two matrix: \n";
	PrintMatrix(Matrix3, 3, 3);
}