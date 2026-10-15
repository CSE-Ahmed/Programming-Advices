
#include <iostream>
using namespace std;
int number (){
int number =0;
cout << "enter number: ";
cin >> number;
return number;
}
int half(int number){
int half = 0;
half = (number / 2);
return half;
}
void print(){
int num = number();
cout << "half of " << num << " is: " << half(num);
}
int main() {
   
}