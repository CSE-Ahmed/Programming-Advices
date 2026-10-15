#include<iostream>
#include<cstdlib>
using namespace std;
int ReadNumber(string Message){
    int Num;
    do{
        cout << Message << endl;
        cin >> Num;    
    }
    while(Num <= 0 || Num > 100);
    return Num;
}
int RandomNumber(int from , int to){
    int Random = rand() % (to - from + 1) + from;
    return Random;
}
void FillArray(int Arr[100] , int LengthArr){
    for (int i = 0 ; i < LengthArr ; i++){
        Arr[i] = RandomNumber(1 , 100);
    }
}
short CheckNumber(int Arr[100] , int LengthArr , int Num){
    for (int i = 0 ; i < LengthArr ; i++){
        if (Arr[i] == Num){
            return i;
        }
    }
    return -1;
}
bool IsNumberInArray(int Arr[100] , int LengthArr , int Num){
    return CheckNumber(Arr , LengthArr , Num) != -1;
}
void PrintArray(int Arr[100] , int LengthArr){
    for (int i = 0 ; i < LengthArr ; i++){
        cout << Arr[i] << " ";
    }
    cout << endl;
}
int main(){
    srand((unsigned)time(NULL));
    int LengthArr = ReadNumber("Enter the length of the array (0-100): ");
    int Arr[100];
    FillArray(Arr , LengthArr);
    cout << "Array 1 elements: " << endl;
    PrintArray(Arr , LengthArr);
    int Num = ReadNumber("Enter a number to check if it is in the array (0-100): ");
    cout << "Number you are looking for: " << Num << endl;
   short NumberPosition = CheckNumber(Arr , LengthArr , Num);
    if (!IsNumberInArray(Arr , LengthArr , Num) ){
        cout << "No, The number isn't found" << endl;
    }
    else{
        cout << "Yes, The Number is found" << endl;
    }
    return 0;
}