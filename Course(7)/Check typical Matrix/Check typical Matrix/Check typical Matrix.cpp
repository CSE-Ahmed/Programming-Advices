#include<iostream>
using namespace std;
#define ROW 3
#define COL 3
int Random(int from, int to) {
	return rand() % (to - from + 1) + from;
}
void FillMatrix(int Matrix[ROW][COL], short row, short col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Matrix[i][j] = Random(1, 2);
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
bool CheckTypicalMatrix(int MAX1[ROW][COL], int MAX2[ROW][COL], short row, short col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (MAX2[i][j] != MAX1[i][j]) {
				return false;
			}
		}
	}
	return true;
}
void PrintTypical(int MAX1[ROW][COL], int MAX2[ROW][COL], short row, short col) {
	if (!CheckTypicalMatrix(MAX1, MAX2, row, col))
	{
		cout << "The Matrix doesn't typical\n";
	}
	else {
		cout << "The Matrix is typical\n";
	}
}
int main() {
	int Max1[ROW][COL], Max2[ROW][COL];
	srand((unsigned)time(NULL));
	FillMatrix(Max1, ROW, COL);
	FillMatrix(Max2, ROW, COL);
	cout << "The first Matrix:\n";
	PrintMatrix(Max1, 3, 3);
	cout << "The Second Matrix:\n";
	PrintMatrix(Max2, 3, 3);
	PrintTypical(Max1, Max2, 3, 3);
}