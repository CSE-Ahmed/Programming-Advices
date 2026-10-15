#include<iostream>
using namespace std;
void ReadNumber(int &Num , int &Repeat){
    do{ 
       cout << "Enter positive digit number: ";
        cin >> Num;
        cout << "Enter the number which you want to know how many times it is repeated: ";
        cin >> Repeat;
    }

    while(Num < 0);
}
void ReapetedNumber(int Num , int Repeat){
    int Count = 0 , Remainder = 0;
    while (Num > 0){
        Remainder = Num % 10;
        Num = Num / 10;
        if (Remainder == Repeat){
            Count++;
        }
    }
    cout << "The number " << Repeat << " is repeated " << Count << " times in the given number\n";
}
int main(){
    int Num,Repeat ;
    ReadNumber(Num , Repeat);
    ReapetedNumber(Num , Repeat) ;
    return 0;
}