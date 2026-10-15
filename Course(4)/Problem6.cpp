#include<iostream>
#include<string>
using namespace std;
struct stInfo{
    string FirstName;
    string LastName;
};
stInfo GetInfo(stInfo info){
    cout << "Enter your first name: ";
    cin >> info.FirstName;
    cout << "Enter your last name: ";
    cin >> info.LastName;
    return info;
}
void Print(stInfo info){
    cout << info.FirstName << " " << info.LastName;
}
int main(){
    stInfo info;
    Print(GetInfo(info));
}