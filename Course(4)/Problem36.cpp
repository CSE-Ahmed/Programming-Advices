#include <iostream>
using namespace std;
enum OperationType{
    ADDITION = '+',
    SUBTRACTION = '-',
    MULTIPLICATION = '*',
    DIVISION = '/'
};
float ReadNumber(string message){
    float number;
    cout << message;
    cin >> number;
    return number;
}
OperationType ReadOperationType(string message){
    char operation;
    cout << message;
    cin >> operation;
    return (OperationType)operation;
}
float Calculate(float number1, float number2, OperationType operation){
    switch(operation){
        case ADDITION:
            return number1 + number2;
        case SUBTRACTION:
            return number1 - number2;
        case MULTIPLICATION:
            return number1 * number2;
        case DIVISION:
            return number1 / number2;
        default:
            return 0;
    }
}
int main(){
    float number1 = ReadNumber("Enter the first number: ");
    float number2 = ReadNumber("Enter the second number: ");
    OperationType operation = ReadOperationType("Enter the operation (+, -, *, /): ");
    cout << "The result is: " << Calculate(number1, number2, operation) << endl;
    return 0;
}