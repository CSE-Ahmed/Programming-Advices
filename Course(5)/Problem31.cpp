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
void Swap(int &a , int &b){
    int temp = a;
    a = b;
    b = temp;
}
void FillArrayFrom1toN(int arr[100] , int Number){
    for(int i = 0; i < Number; i++){
        arr[i] = i +1;
    }
    cout << endl;
}
void ShuffleArray(int arr[100] , int LengthArr){
    for (int i = 0 ; i < LengthArr; i++){
        Swap(arr[RandomNumber(1, LengthArr) - 1], arr[RandomNumber(1, LengthArr) - 1]);
    }
}
void PrintArray(int arr[100] , int Number){
    for(int i = 0; i < Number; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    srand((unsigned)time(NULL));
    int Number = ReadNumber("Enter the number of elements in the array?");
    int arr[100];
    FillArrayFrom1toN(arr, Number);
    cout << "Before Shuffle: ";
    PrintArray(arr, Number);
    ShuffleArray(arr, Number);
    cout << "After Shuffle: ";
    PrintArray(arr, Number);   
    return 0;
}


