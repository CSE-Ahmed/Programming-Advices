#include<iostream>
using namespace std;

void fillArray(int Arr[], int &LengthArr) {
    LengthArr = 6;
    Arr[0] = 10;
    Arr[1] = 20;
    Arr[2] = 30;
    Arr[3] = 70;
    Arr[4] = 20;
    Arr[5] = 10;
}

void PrintArray(int Arr[], int LengthArr) {
    for (int i = 0; i < LengthArr; i++) {
        cout << Arr[i] << " ";
    }
    cout << "\n";
}

void ReverseArray(int ArrSource[], int ArrDest[], int ArrlengthSource) {
    for (int i = 0; i < ArrlengthSource; i++) {
        ArrDest[i] = ArrSource[ArrlengthSource - 1 - i];
    }
}

string CheckPalindrome(int ArrSource[], int ArrDest[], int Arrlength) {
    for (int i = 0; i < Arrlength; i++) {
        if (ArrSource[i] != ArrDest[i]) {
            return "No, Array is not Palindrome";
        }
    }
    return "Yes, Array is Palindrome";
}

int main() {
    int Arr[100], ArrDest[100], LengthArr;
    fillArray(Arr, LengthArr);
    cout << "Array elements\n";
    PrintArray(Arr, LengthArr);
    ReverseArray(Arr, ArrDest, LengthArr);
    cout << "Reversed Array elements\n";
    PrintArray(ArrDest, LengthArr);
    cout << CheckPalindrome(Arr, ArrDest, LengthArr);
}