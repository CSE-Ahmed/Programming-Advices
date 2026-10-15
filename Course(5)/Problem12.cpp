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
void InvertedNumber(int Num){
    for (int i = Num ; i > 0; i--){
        for (int j = 0 ; j < i ; j++){
            cout << i;
        }
        cout << endl;
    }
}
int main(){
    InvertedNumber(ReadNumber());
    return 0;
}