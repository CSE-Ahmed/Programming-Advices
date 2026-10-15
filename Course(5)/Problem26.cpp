#include<iostream>
#include<cstdlib>
using namespace std;
int ReadNumber(string Message)
{
    int Num;
    do{
        cout << Message << endl;
        cin >> Num;
    }
    while(Num <= 0);
    return Num;
}
int RandomNumber(int from , int to){
    int Random = rand() % (to - from + 1) + from;
    return Random;
}
void RandomArray(int Arr[100] , int Num){ 

    for (int i = 0 ; i < Num ; i++){
        Arr[i] = RandomNumber(1,100);
    }
}
void PrintedArray(int Arr[100] , int Num){
    for(int i = 0 ; i < Num ; i++){
        cout << Arr[i] << " ";
    }
    cout << "\n";
}
int SumOfTheArray(int Arr[100] , int Num){
    int sum = 0;
    for (int i = 0 ; i < Num ; i++){
        sum = sum + Arr[i];
    }
    return sum;
}
int main(){
    int Arr[100];
    int Num = ReadNumber("Enter the length of the array?");
    RandomArray(Arr , Num);
    cout << "\nArray elements: ";
    PrintedArray(Arr , Num);
    cout << "The sum of the array is: ";
    cout << SumOfTheArray(Arr , Num);
}