#include<iostream>
#include<iomanip>
using namespace std;
short Random(short from, short to) {
	return rand() % (to - from + 1) + from;
}
void Fill_Matrix(short ARR[3][3], short row, short col) {
	for (short i = 0; i < row; i++) {
		for (short j = 0; j < col; j++) {
			ARR[i][j] = Random(1, 10);
		}
	}
}
void Print_Matrix(short ARR[3][3], short row, short col) {
	cout << "The following is the matrix after filled:\n";
	for (short i = 0; i < row; i++) {
		for (short j = 0; j < col; j++) {
			cout << setw(2) << ARR[i][j] << " ";
		}
		cout << endl;
	}
}
short Row_Sum(short ARR[3][3], short row, short col) {
	short sum = 0; 
	for (short i = 0; i < col; i++) {
		sum += ARR[row][i];
	}
	return sum;
}
void Sum_Each_Row(short ARR[3][3], short Arr[3], short row, short col) {
	for (short i = 0; i < row; i++) {
		Arr[i] = Row_Sum(ARR, i, col);
	}
}
void Print_Each_Row(short Arr[3], short row) {
	cout << "The following is the sum of each row: \n";
	for (short i = 0; i < row; i++) {
		cout << "Row [" << i << "] is : " << Arr[i] << endl;
	}
}
int main() {
	srand((unsigned)time(NULL));
	short ARR[3][3], Arr[3];
	Fill_Matrix(ARR, 3, 3);
	Print_Matrix(ARR, 3, 3);
	Sum_Each_Row(ARR, Arr, 3, 3);
	Print_Each_Row(Arr, 3);
}