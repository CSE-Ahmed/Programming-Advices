#include<iostream>
using namespace std;
char PrintLetter(){
   char letter;
    for (char i = 'A'; i <= 'Z'; i++){
       cout << i << " " << endl;
   }
    return letter; 
}
int main(){
    PrintLetter();
}   