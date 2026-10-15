#include<iostream>
using namespace std;
int ReadNumber(){
    int Num;
    cout << "Enter Number: \n";
    cin >> Num;
    return Num;
}
void PrintResultUsingFor(int Num){
    for ( int i = 1 ; i <= Num ; i++){
        cout << i << endl;
    }
}
void PrintResultUsingWhlie(int Num){
    int Counter = 1;
    while (Counter <= Num){
        cout << Counter << endl;
        Counter++;
    } 
}
void PrintResultUsingDo_While(int Num){
    int counter = 0;
    do{
        counter++;
        cout << counter << endl;
    }
    while(counter < Num);
}
int main(){
    cout << "Print using for loop: \n";
    PrintResultUsingFor(ReadNumber());
    cout << endl;
    cout << "Print using while loop: \n";
    PrintResultUsingWhlie(ReadNumber());
    cout << endl;
    cout << "Print using Do..while loop: \n";
    PrintResultUsingDo_While(ReadNumber());
}

