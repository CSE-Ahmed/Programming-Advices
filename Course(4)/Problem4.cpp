#include<iostream>
using namespace std;
struct hire{
    short age;
    bool HaveDrivingLicense;
};
hire ReadHire(){
    hire info;
    cout << "Enter your age: ";
    cin >> info.age;
    cout << "Do you have a driving license? (1 for yes, 0 for no): ";
    cin >> info.HaveDrivingLicense;
    return info;
}
void PrintHire(hire info){
    cout << "Your age is: " << info.age << endl;
    if (info.HaveDrivingLicense == 1 & info.age >=21)
        cout << "Hired!" << endl;
    else
        cout << "Rejected!" << endl;
}
int main(){
    PrintHire(ReadHire());
}