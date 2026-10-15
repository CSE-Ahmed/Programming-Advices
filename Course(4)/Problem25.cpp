#include<iostream>
using namespace std;
int ReadAge(){
    int Age;
    cout << "Enter your age: ";
    cin >> Age;
    return Age;
}
bool ReadValidAge(int Age, int from, int to){
    return (Age >= from && Age <= to);
}
int ReadUntilValidAge(int from, int to){
    int Age = 0;
    do{
        Age = ReadAge();
    }
    while(!ReadValidAge(Age , from , to));
    return Age;
}
void PrintResult(int Age){
    cout << "Your age is: " << Age << endl;
}
 int main(){
    short from , to;
    cout << "Enter the range of age:\n ";
    cout << "From ? \n";
    cin >> from; 
    cout << "To\n";
    cin >> to;
    PrintResult(ReadUntilValidAge(from , to));
 }
