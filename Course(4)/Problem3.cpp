#include <iostream>
using namespace std;
enum Number{even = 0, odd = 1};
int ReadNumber(){
    int Num;
    cout << "Enter a number: ";
    cin >> Num;
    return Num;
}
Number checkNumber(int Num){
    if (Num % 2 == 0)
        return even;
    else
        return odd;
}
void PrintNumber(Number num){
    if (num == even)
        cout << "The number is even" << endl;
    else
        cout << "The number is odd" << endl;
}
int main(){
 PrintNumber(checkNumber(ReadNumber()));   

}