#include<iostream>
using namespace std;
int ReadTotalSales(){
    int totalSales;
    cout << "Enter the total sales: ";
    cin >> totalSales;
    return totalSales;
}
double CalculateCommission(int totalSales){
    double commission;
    if(totalSales >= 1000000){
        commission = totalSales * 0.01;
    }else if(totalSales >= 500000 && totalSales < 1000000){
        commission = totalSales * 0.02;
    }else if(totalSales >= 100000 && totalSales < 500000){
        commission = totalSales * 0.03;
    }else if(totalSales < 100000 &&  totalSales > 50000){
        commission = totalSales * 0.05;
    }
    else
    {
        commission = 0;
    }
    return commission;
}
void DisplayCommission(double commission){
    cout << "The commission is: " << commission << endl;
}
int main(){
    DisplayCommission(CalculateCommission(ReadTotalSales()));
    return 0;
}