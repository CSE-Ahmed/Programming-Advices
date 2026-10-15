#include<iostream>
#include<string>
using namespace std;
string ReadName(){
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    return name;
}
void PrintName(string name){
    cout << "Your name is: " << name << endl;
}
int main(){
    
    PrintName(ReadName());
}

