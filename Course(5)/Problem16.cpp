#include<iostream>
using namespace std;
void PrintFromAAAtoZZZ(){
    for(int i = 65 ; i <= 90 ; i++){
        for(int j = 65 ; j <= 90 ; j++){
            for(int l = 65 ; l <= 90 ; l++){
                cout << char(i) << char (j) << char(l) << "\n";
            }
        }
    }
}
int main(){
    PrintFromAAAtoZZZ();
}