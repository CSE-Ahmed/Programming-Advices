#include<iostream>
using namespace std;
int Random(short from , short to) {
	return rand() % (to - from + 1) + 1;
}
void FillMatrix(int ARR[3][3], short row, short col) {
	for (short i = 0; i < row; i++) {
		for (short j = 0; j < col; j++) {
			ARR[i][j] = Random(1, 10);
		}
	}
}
void printMatrix(int ARR[3][3], short row, short col) {
	for (short i = 0; i < row; i++) {
		for (short j = 0; j < col; j++) {
			cout << ARR[i][j] << "\t";
		}
		cout << endl;
	}
}
int SumRows(int ARR[3][3], short rowIndex, short col) {
    int sum = 0;
    for (short i = 0; i < col; ++i) {
        sum += ARR[rowIndex][i];
    }
    return sum;
}
void Print_Each_Row(int ARR[3][3], short row, short col) {
	cout << "the following is the Sum of each row\n";
	for (short i = 0; i < row; i++) {
		cout << "Row[" << i << "] is " << SumRows(ARR, i, col) << endl;
	}
}
int main() {
	srand((unsigned)time(NULL));
	int ARR[3][3];
	FillMatrix(ARR, 3, 3);
	cout << "The matrix after filled is: \n";
	printMatrix(ARR, 3, 3);
	Print_Each_Row(ARR, 3, 3);
}