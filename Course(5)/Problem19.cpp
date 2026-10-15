#include<iostream>
#include<cstdlib>
using namespace std;
int RandomNumber(int from , int to){
    int RandNum = rand() % (to - from + 1) + from;
    return RandNum;
}
int main(){
    srand((unsigned)time(NULL));
    cout << RandomNumber (1 , 20) << endl;
    cout << RandomNumber (1 , 10) << endl;
    cout << RandomNumber (1 , 10) << endl;
    return 0;
}