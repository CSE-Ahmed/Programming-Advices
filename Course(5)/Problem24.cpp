#include<iostream>
#include<cstdlib>
using namespace std;
int RandomNumber(int from , int to){
    int Random = rand() % (to - from + 1) + from;
    return Random;
}
int ReadNumber(string message){
    int Num;
    do{
        cout << message << endl;
        cin >> Num;
    }
    while(Num <= 0 || Num > 100);
    return Num;
}
void fillArray(int Arr[100] , int Num){
    for (int i = 0 ; i < Num ; i++){
        Arr[i] = RandomNumber(1,100);
    }
}
void PrintedArray(int Arr[100] , int Num){
    cout << "Array elements: ";
    for(int i= 0 ; i < Num ; i++){
        cout << Arr[i] << "  ";
    }
    cout << endl;
}
int MaxNumber(int Arr[100], int Num) {
    int max = Arr[0];
    for (int i = 1; i < Num; i++) { 
        if (Arr[i] > max) {
            max = Arr[i];
        }
    } 
    return max;
}

int main(){
    srand((unsigned)time(NULL));
    int Arr[100];
    int Length = ReadNumber("Enter the number of elemnts?");
    fillArray(Arr , Length);
    PrintedArray(Arr , Length);
    cout <<  MaxNumber(Arr , Length);
}