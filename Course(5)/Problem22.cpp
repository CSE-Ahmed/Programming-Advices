#include<iostream>
using namespace std;
int ReadNumber(string message){
    int Num;
    do{
        cout << message << "\n";
        cin >> Num;
    }
    while(Num <= 0);
    return Num;
}
void ReadArr(int Arr[] , int Num){ 
    for (int i = 0 ; i < Num ; i++){
        cout << "Element["<<i+1<<"] : ";
        cin >> Arr[i];
    }
    cout << endl;
}
void PrintedArray(int Arr[] ,int Num ){
    cout << "Original array : ";
    for(int i = 0 ; i < Num ; i++){
        cout << Arr[i] << " ";
    }
    cout << endl;
}
void CheckRepeatedNumber(int Arr[] , int Repeated , int Num ){
    int counter = 0;
    for(int i = 0 ; i < Num ; i++){
        if (Arr[i] == Repeated)
            counter++;
    }
    cout << Repeated << " Is repeated " << counter << " time(s)";
}
int main(){
    int Num = ReadNumber("Enter the length of the array");
    int Arr[Num];
    ReadArr(Arr, Num);
    int Repeat = ReadNumber("Enter the number you want to check?");
    PrintedArray(Arr,Num); 
    CheckRepeatedNumber(Arr , Repeat , Num);
}