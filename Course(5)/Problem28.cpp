#include<iostream>
#include<cstdlib>
using namespace std;
int RandomNumber(int from , int to){
    int Random = rand() % (to - from + 1) + from;
    return Random;
}
int ReadNumber(string message){
    int Number;
    do{
        cout << message << endl;
        cin >> Number;
    }
    while(Number < 0);
    return Number;
}
void FillRandomArray(int Arr[100] , int Num){
    for (int i = 0 ; i < Num ; i++){
        Arr[i] = RandomNumber(1 , 100);
    }
}
void PrintArray(int Arr[100] , int Num){
    for (int i = 0 ; i < Num ; i++){
        cout << Arr[i] << " ";
    }
    cout << endl;
}
void CopyArray(int Arr[100] , int Arr2[100] , int Num){
    for (int i = 0 ; i < Num ; i++){
        Arr2[i] = Arr[i];
    }
}
int main(){
    srand((unsigned)time(NULL));
    int Num = ReadNumber("Enter the number of elements in the array");
    int Arr[100];
    int Arr2[100];
    FillRandomArray(Arr , Num);
    CopyArray(Arr , Arr2 , Num);
     cout << "The original array is: ";
    PrintArray(Arr , Num);
    cout << "The copied array is: ";
    PrintArray(Arr2 , Num);
    return 0;
}