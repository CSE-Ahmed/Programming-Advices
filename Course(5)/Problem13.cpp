#include<iostream>
using namespace std;
int ReadNumber(){
    int Num;
    do{
       cout << "Enter positive digit number: ";
        cin >> Num;
    }
    while(Num < 0);
    return Num;
}
void PrintedNumberPattern(int Num){
    for (int i = 1 ; i <= Num; i++){
        for (int j = 0 ; j < i ; j++){
            cout << i;
        }
        cout << endl;
    }
}
int main(){
    PrintedNumberPattern(ReadNumber());
    return 0;
}