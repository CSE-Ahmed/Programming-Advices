#include<iostream>
using namespace std;
int ReadNumber(){
    int Num;
    cout << "Enter a number: ";
    cin >> Num;
    return Num;
}
void ArrayElements(int Number, int Arr[100], int& LengthArr){
    LengthArr++;
    Arr[LengthArr - 1] = Number;
}
void ReadNumbersFromUser(int Arr[100], int& LengthArr){
    bool AddMore = true;
    do{
        ArrayElements(ReadNumber(), Arr, LengthArr);
        cout << "Do you want to add more numbers? (1 for Yes, 0 for No): ";
        cin >> AddMore;
    }
    while (AddMore);
}
void PrintArray(int Arr[100] , int LengthArr){
    for (int i = 0; i < LengthArr; i++){
        cout << Arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int Arr[100], LengthArr = 0;
    ReadNumbersFromUser(Arr, LengthArr);
    cout << "The numbers you entered are: ";
    PrintArray(Arr, LengthArr);
    cout << "The length of the array is: " << LengthArr << endl;
}