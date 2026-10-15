#include<iostream>
using namespace std;
int ReadAge(){
    int Age;
    cout << "Enter your age: ";
    cin >> Age;
    return Age;
}
int Result(int Age){
    int result = (Age >= 18 && Age <= 45);
    return result;
}
void PrintResult(int result){
    bool x = true;
    if (result == x)
        cout << "Valid age";
    else   
        cout << "Invalid age";
}
int main(){
    PrintResult(Result(ReadAge()));
}