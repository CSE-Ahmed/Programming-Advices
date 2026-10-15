#include <iostream>
using namespace std;

enum enpassFail {fail = 1 , pass = 2};

int ReadMark(){
    int mark;
    cout << "Enter your mark: ";
    cin >> mark;
    return mark;

}

enpassFail checkNumber(int mark){
    if (mark >= 50)
        return enpassFail::pass;
    else
        return enpassFail::fail;
}

void PrintResult(int mark){
    if (enpassFail::pass ==  checkNumber(mark))
        cout << "Pass";
    else
        cout << "Fail";
}
int main(){
    PrintResult(ReadMark());
    return 0;
}