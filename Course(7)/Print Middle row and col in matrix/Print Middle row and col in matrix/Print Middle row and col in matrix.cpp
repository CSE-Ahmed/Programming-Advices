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
void PrintMiddleRow(int Matrix[3][3], short row, short col) {
	short MiddleRow = row / 2;
	for (int i = 0; i < col; i++) {
		printf(" %0*d ", 2, Matrix[MiddleRow][i]);
	}
	cout << endl;
}
void PrintMiddleCol(int Matrix[3][3], short row, short col) {
	short MiddleCol = col / 2;
	for (int i = 0; i < col; i++) {
		printf(" %0*d ", 2, Matrix[i][MiddleCol]);

	}
	cout << endl;
}
int main() {
	srand((unsigned)time(NULL));
	int Matrix[3][3];
	FillMatrix(Matrix, 3, 3);
	cout << "The matrix: \n";
	PrintMatrix(Matrix, 3, 3);
	cout << "The middle Row: \n";
	PrintMiddleRow(Matrix, 3, 3);
	cout << "The middle col: \n";
	PrintMiddleCol(Matrix, 3, 3);
}

