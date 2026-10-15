#include<iostream>
#include<cstdlib>
using namespace std;
int ReadNumber(string Message){
    int Number;
    do{
        cout << Message << endl;
        cin >> Number;
    }
    while(Number < 0 || Number > 100);
    return Number;
}
int RandomNumber(int from , int to){
    int Random = rand() % (to - from + 1 ) + from;
    return Random;
}
void FillArray(int Arr[100] , int LengthArr){
    for (int i = 0 ; i < LengthArr; i++){
        Arr[i] = RandomNumber(1, 100);
    }
}
void CoppyArrWithReversed(int Arr[100] , int LengthArr , int Arr2[100]){
    for (int i = 0 ; i < LengthArr ; i++){
        Arr2[i] = Arr[LengthArr - i - 1];
    }
}
void PrintArray(int Arr[100] , int LengthArr){
    for (int i = 0 ; i < LengthArr ; i++){
        cout << Arr[i] << " ";
    }
    cout << endl;
}
int main(){
    srand((unsigned)time(NULL));
    int Arr[100] , Arr2[100];
    int LengthArr = ReadNumber("Enter the length of the array (0-100): ");
    FillArray(Arr, LengthArr);
    cout << "Original array: ";
    PrintArray(Arr, LengthArr);
    CoppyArrWithReversed(Arr, LengthArr , Arr2);
    cout << "Reversed array: ";
    PrintArray(Arr2, LengthArr);
    return 0;  
}