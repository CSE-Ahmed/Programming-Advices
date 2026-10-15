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
void ReverseNumber(int Num){
    while (Num > 0){
        cout << Num % 10;
        Num = Num / 10;
    }
}
int main(){
     ReverseNumber(ReadNumber());
    return 0;
}