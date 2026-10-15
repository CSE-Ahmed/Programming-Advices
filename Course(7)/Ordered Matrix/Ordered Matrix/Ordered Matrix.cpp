#include<iostream>
using namespace std;
void FillMatrix(int ARR[3][3], short row, short col) {
	short counter = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			ARR[i][j] = ++counter;
		}
	}
}
void PrintMatrix(int ARR[3][3], short row, short col) {
	cout << "The following is the matrix after filled: \n";
	for (int i = 0; i < row;i++) {
		for (int j = 0; j < col; j++) {
			cout << ARR[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	int ARR[3][3];
	FillMatrix(ARR, 3, 3);
	PrintMatrix(ARR, 3, 3);
}