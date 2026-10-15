#include<iostream>
using namespace std;
int ReadNumber(){
    int Num;
    cout << "Enter Number: \n";
    cin >> Num;
    return Num;
}
void PrintResult(int Num){
    for ( int i = Num ; i > 0 ; i--){
        cout << i << endl;
    }
}
int main(){
    PrintResult(ReadNumber());
}