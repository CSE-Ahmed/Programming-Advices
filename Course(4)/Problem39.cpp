#include<iostream>
using namespace std;
struct Cash_Bill{
    int cashPaid;
    int TotalBill;
};
Cash_Bill ReadCash(){
    Cash_Bill cash;
    cout << "Enter the total bill: ";
    cin >> cash.TotalBill;
    cout << "Enter the cash paid: ";
    cin >> cash.cashPaid;
    return cash;
}
int calculateChange(Cash_Bill cash){
    return cash.cashPaid - cash.TotalBill;
}
int main(){
    cout << "The rest is " << calculateChange(ReadCash());
}