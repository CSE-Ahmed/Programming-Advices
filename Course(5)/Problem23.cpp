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
}
int main(){
    int Arr[100];
    srand((unsigned)time(NULL));
    int Num = ReadNumber("Enter how many numbers?");
    fillArray(Arr, Num);
    PrintedArray(Arr, Num);
    return 0;  
}