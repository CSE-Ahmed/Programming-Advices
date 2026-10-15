#include<iostream>
using namespace std;
int ReadNumber()
{
    int Num;
    do{ 
       cout << "Enter positive digit number: ";
        cin >> Num;
        return Num;
    }

    while(Num < 0);
}
int ReapetedNumber(int Num , int Repeat){
    int Count = 0 , Remainder = 0;
    while (Num > 0){
        Remainder = Num % 10;
        Num = Num / 10;
        if (Remainder == Repeat){
            Count++;
        }
    }
    return Count;
}
void PrintDigit(int Num){
    for (int i = 0; i < 10; i++){
        short Digit = ReapetedNumber(Num , i);
        if (Digit > 0){
            cout << "The number " << i << " is repeated " << Digit << " times in the given number\n";
        }

    }
}
int main(){
    PrintDigit(ReadNumber());
    return 0;
}