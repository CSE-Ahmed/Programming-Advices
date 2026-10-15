#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int ReadNumber(string Message){
    int Number;
    do{
        cout << Message << "\n";
        cin >> Number;
    }
    while(Number < 1 || Number > 100);
    return Number;
}
enum enPrimeNumbers{
    Prime = 0 ,
    NotPrime = 1
};
enPrimeNumbers CheckPrime(int Number)
{
    int M = round(Number / 2);
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimeNumbers::NotPrime;
    }
    return enPrimeNumbers::Prime;
}

int RandomNumber(int from , int to){
    int Random = rand() % (to - from + 1) + from;
    return Random;
}
void FillArray(int Array[], int Size){
    for(int i = 0; i < Size; i++){
        Array[i] = RandomNumber(1, 100);
    }
}
void PrintArray(int Array[], int Size){
    for(int i = 0; i < Size; i++){
        cout << Array[i] << " ";
    }
    cout << "\n";
}
void AddArrayElements(int Number, int Arr[100], int& LengthArr){
    LengthArr++;
    Arr[LengthArr - 1] = Number;
}
void CopyOnlyPrimeNumbers(int SourceArr[100], int DestArr[100], int SourceLength, int& DestLength){
    for(int i = 0; i < SourceLength; i++){
        if(CheckPrime(SourceArr[i]) == enPrimeNumbers::Prime){
            AddArrayElements(SourceArr[i], DestArr, DestLength);
        }
    }
}
int main(){
    srand((unsigned)time(NULL));
    int SourceArr[100], DestArr[100], SourceLength, DestLength = 0;
    SourceLength = ReadNumber("Enter number of elements:");
    FillArray(SourceArr, SourceLength);
    cout << "Source Array:\n";
    PrintArray(SourceArr, SourceLength);
    CopyOnlyPrimeNumbers(SourceArr, DestArr, SourceLength, DestLength);
    cout << "Destination Array:\n";
    PrintArray(DestArr, DestLength);
    return 0;
}