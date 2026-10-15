#include<iostream>
#include<cstdlib>
using namespace std;
int ReadNumber(string message){
    int Number;
    do {
        cout << message << endl;
        cin >> Number;
    }
    while(Number < 0);
    return Number;
}
int RandomNumber (int from , int to){
    int Random = rand() % (to - from  + 1) + from;
    return Random;
}
void FillRandomArray(int arr[100] , int Number){
    for(int i = 0; i < Number; i++){
        arr[i] = RandomNumber(1, 100);
    }
}
void PrintArray(int arr[100] , int Number){
    for(int i = 0; i < Number; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void SumOf2Arrays(int arr[100] , int arr2[100] , int arr3[100] , int Number){
    for(int i = 0; i < Number; i++){
        arr3[i] = arr[i] + arr2[i];
    }
}
int main(){
    srand((unsigned)time(NULL));
    int Number = ReadNumber("Enter the number of elements in the array?");
    int arr[100] , arr2[100] , arr3[100];
    FillRandomArray(arr, Number);
    FillRandomArray(arr2, Number);
    SumOf2Arrays(arr, arr2, arr3, Number);
    cout << "First array: ";
    PrintArray(arr, Number);
    cout << "Second array: ";
    PrintArray(arr2, Number);
    cout << "Sum of arrays: ";
    PrintArray(arr3, Number);
    return 0;
}