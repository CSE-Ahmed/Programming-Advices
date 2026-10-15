#include<iostream>
using namespace std;
struct hire{
    short age;
    bool HaveDrivingLicense;
    bool HasRecommendation;
};
hire ReadHire(){
    hire info;
    cout << "Enter your age: ";
    cin >> info.age;
    cout << "Do you have a driving license? (1 for yes, 0 for no): ";
    cin >> info.HaveDrivingLicense;
    cout << "Do you have a recommendation? (1 for yes, 0 for no): ";
    cin >> info.HasRecommendation;
    return info;
}
void PrintHire(hire info){
    if (info.HasRecommendation == 1)
        cout << "Hired\n";
    else if (info.age >= 21 && info.HaveDrivingLicense == 1)
        cout << "Hired\n";
    else
        cout << "Not Hired\n";     
}
int main(){
    PrintHire(ReadHire());
}