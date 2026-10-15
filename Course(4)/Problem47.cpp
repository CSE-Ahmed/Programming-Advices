#include <iostream>
using namespace std;
struct Loan{
    int LoanAmount;
    int MonthlyPayment;
};
Loan ReadLoan(){
    Loan loan;
    cout << "Enter the loan amount: ";
    cin >> loan.LoanAmount;
    cout << "Enter the monthly payment: ";
    cin >> loan.MonthlyPayment;
    return loan;
}
int MonthsToPayOff(Loan loan){
    return loan.LoanAmount / loan.MonthlyPayment;
}
int main(){
    float LoanAmount =  MonthsToPayOff(ReadLoan());
    cout << "Months to pay off: " << LoanAmount;
}
