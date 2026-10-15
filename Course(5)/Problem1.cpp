#include<iostream>
#include<string>
using namespace std;
void PrintHeader() {
    cout << "\t\t\t Multiplication table from 1 to 10\n";
    cout << "\t";
    for (int i = 1; i <= 10; i++) {
        cout << i << "\t";
    }
    cout << "\n____________________________________________________________________________________\n";
}
void Space(int i) {
    if (i < 10)
        cout << i << "  |\t";
    else
        cout << i << " |\t";
}
void Multiplication() {
    PrintHeader();
    for (int i = 1; i <= 10; i++) {
        Space(i);
        for (int z = 1; z <= 10; z++) {
            cout << i * z << "\t";
        }
        cout << endl;
    }
}
int main() {
    Multiplication();
}