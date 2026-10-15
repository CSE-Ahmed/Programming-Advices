#include <iostream>
#include <cstdlib>
using namespace std;

int ReadNumber() {
    int Number;
    cout << "Enter a number: ";
    cin >> Number;
    return Number;
}

enum enEvenOdd { Even = 1, Odd = 2 };

enEvenOdd CheckOdd(int Number) {
    return (Number % 2 == 1) ? enEvenOdd::Odd : enEvenOdd::Even;
}

int RandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void FillArray(int Arr[100], int LengthArr) {
    for (int i = 0; i < LengthArr; i++) {
        Arr[i] = RandomNumber(1, 100);
    }
}

void PrintArray(int Arr[100], int LengthArr) {
    for (int i = 0; i < LengthArr; i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;
}
void AddArrayElements(int Number, int Arr[100], int& LengthArr){
    LengthArr++;
    Arr[LengthArr - 1] = Number;
}
int ExtractOddNumbers(int Arr[100], int OddArr[100], int LengthArr) {
    int OddCount = 0;
    for (int i = 0; i < LengthArr; i++) {
        if (CheckOdd(Arr[i]) == enEvenOdd::Odd) {
            AddArrayElements(Arr[i], OddArr, OddCount);
        }
    }
    return OddCount;
}
int main() {
    srand((unsigned)time(NULL)); // Seed the random number generator
    int LengthArr = ReadNumber();
    int Arr[100], OddArr[100];
    
    FillArray(Arr, LengthArr);

    cout << "Original array: ";
    PrintArray(Arr, LengthArr);

    int OddCount = ExtractOddNumbers(Arr, OddArr, LengthArr);

    cout << "Odd numbers in the array: ";
    PrintArray(OddArr, OddCount);

    return 0;
}
