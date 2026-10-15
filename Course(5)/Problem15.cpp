#include<iostream>
using namespace std;
int ReadNumber(){
    int Num;
    do{
        cout << "Enter a positive number: ";
        cin >> Num;
    }
    while (Num <=0);
    return Num;
}
void PrintedInvertedLetters(int Num){
    for (int i = 65 ; i <= 65 + Num - 1; i++){
        for(int l = 1 ; l <= i - 65 + 1 ; l++){
            cout << (char)i;
        }
        cout << endl;
    }
}
int main(){
    PrintedInvertedLetters(ReadNumber());
    return 0;
}