#include<iostream>
using namespace std;
void FillArray(int Arr[100], int& LengthArr){
    int temp[] = {10, 10, 10, 50, 50, 70, 70, 70, 70, 90};
    LengthArr = 10;
    for (int i = 0; i < LengthArr; i++) {
        Arr[i] = temp[i];
    }
}
void PrintArray(int Arr[100]){
    for (int i = 0 ; i < 10 ; i++){
        cout << Arr[i] << " ";
    }
    cout << "\n";
}
void AddArrayElements(int Number, int Arr[100], int& LengthArr){
    LengthArr++;
    Arr[LengthArr - 1] = Number;
}
void ReapeatArrayElements(int Number, int Arr[100], int& LengthArr){
    for (int i = 0 ; i < LengthArr ; i++){
        if (Arr[i] == Number){
            AddArrayElements(Number, Arr, LengthArr);     
        }
    FillArray(Arr, LengthArr);
}
}
int main(){
    int Arr[100], LengthArr = 0;
    FillArray(Arr, LengthArr);
    cout << "Source Array:\n";
    PrintArray(Arr);
    for (int i = 0 ; i < 10 ; i++){
        ReapeatArrayElements(Arr[i], Arr, LengthArr);
    }
    cout << "Destination Array:\n";
    PrintArray(Arr);
    return 0;
}