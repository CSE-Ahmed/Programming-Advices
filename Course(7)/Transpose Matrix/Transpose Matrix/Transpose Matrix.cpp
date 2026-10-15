#include<iostream>
using namespace std;
void FillOrderedMatrix(int Matrix[3][3], short row, short col) {
	short counter = 0;
	for (int i = 0; i < row;i++) {
		for (int j = 0; j < col; j++) {
			Matrix[i][j] = ++counter;
		}
	}
}
void PrintMatrix(int Matrix[3][3], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void TransposeMatrix(int Matrix[3][3], int Matrix2[3][3], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Matrix2[i][j] = Matrix[j][i];
		}
	}
}
int main() {
	int Matrix[3][3], Matrix2[3][3];
	FillOrderedMatrix(Matrix, 3, 3);
	cout << "The following is the ordered matrix: \n";
	PrintMatrix(Matrix, 3, 3);
	TransposeMatrix(Matrix, Matrix2, 3, 3);
	cout << "The following is the transposed Matrix: \n";
	PrintMatrix(Matrix2, 3, 3);
}