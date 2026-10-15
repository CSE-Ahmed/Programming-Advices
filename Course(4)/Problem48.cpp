#include <iostream>
using namespace std;
struct Loan{
    float LoanAmount;
    float MonthsToPayOff;
};
Loan ReadLoan(){
    Loan loan;
    cout << "Enter the loan amount: ";
    cin >> loan.LoanAmount;
    cout << "Enter the monthly payment: ";
    cin >> loan.MonthsToPayOff;
    return loan;
}
float Monthlyinstallmentamount(Loan loan){
    return loan.LoanAmount / loan.MonthsToPayOff;
}
int main(){
    float LoanAmount =  Monthlyinstallmentamount(ReadLoan());
    cout << " Monthly installment amount: " << LoanAmount;
}