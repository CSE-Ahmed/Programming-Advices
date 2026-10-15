#include <iostream>
using namespace std;

void ReadNumbers(int Number[3]) {
    for (int i = 0; i < 3; i++) {
        cout << "Enter Number " << i + 1 << ": ";
        cin >> Number[i];
    }
}

int SumOf3Numbers(int Number[3]) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += Number[i];  
    }
    return sum;
}

void PrintSum(int sum) {
    cout << "The sum of the three numbers is: " << sum << endl;
}

int main() {
    int Number[3];
    ReadNumbers(Number);  
    PrintSum(SumOf3Numbers(Number)); 
    return 0;
}
