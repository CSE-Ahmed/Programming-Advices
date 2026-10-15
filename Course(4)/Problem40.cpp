#include<iostream>
using namespace std;
float ReadBillValue(){
    float billValue;
    cout << "Enter the bill value: ";
    cin >> billValue;
    return billValue;
}
int AddTax(int billValue){
    float totalBill = (float)billValue * 1.1;
    totalBill = totalBill * 1.16;
    return totalBill;
}
int main(){
    float totalBill = AddTax(ReadBillValue());
    cout << "The total bill is: " << float(totalBill);
}