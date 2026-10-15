#include<iostream>
#include<iomanip>
using namespace std;
int Random(short from, short to) {
	return rand() % (to - from + 1) + from;
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
int main() {
	srand((unsigned)time(NULL));
	int ARR[3][3];
	FillMatrix(ARR, 3, 3);
	printMatrix(ARR, 3, 3);
}