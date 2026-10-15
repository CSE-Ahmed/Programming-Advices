#include<iostream>
#include<cstdlib>
using namespace std;
int ReadNumber(string Message){
    int Num;
    do{
        cout << Message << "\n";
        cin >> Num;
    }
    while(Num <= 0);
    return Num;
}
int RandomNumber(int from, int to){
    return rand() % (to - from + 1) + to;
}
void FillArray(int Arr[100] , int& LengthArr){
    for (int i = 0; i < LengthArr; i++){
        Arr[i] = RandomNumber(1, 100);
    }
}
void AddArrayElements(int Number, int Arr[100], int& LengthArr){
    LengthArr++;
    Arr[LengthArr - 1] = Number;
}
void CopyArray(int Arr[100] , int Arr2[100], int LengthArr, int& LengthArr2){
    for (int i = 0; i < LengthArr; i++){
        AddArrayElements(Arr[i], Arr2, LengthArr2);
    }
}
void PrintArray(int Arr[100] , int LengthArr){
    for (int i = 0; i < LengthArr; i++){
        cout << Arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int Arr[100], Arr2[100], LengthArr = 0, LengthArr2 = 0;
    LengthArr = ReadNumber("Enter the length of the array: ");
    FillArray(Arr, LengthArr);
    CopyArray(Arr, Arr2, LengthArr, LengthArr2);
    cout << "The numbers in the first array are: ";
    PrintArray(Arr, LengthArr);
    cout << "The numbers in the second array are: ";
    PrintArray(Arr2, LengthArr2);
    return 0;
}