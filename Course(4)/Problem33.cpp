#include<iostream>
using namespace std;
int ReadGrade(int from , int to){
    int grade;
    do{
        cout << "Enter grade between " << from << " and " << to << ": ";
        cin >> grade;
    }while(grade < from || grade > to);
    return grade;
}
char PrintGrade(int grade){
    if (grade<= 100 && grade >= 90){
        return 'A';
    }
    else if (grade < 90 && grade >= 80){
        return 'B';
    }
    else if (grade < 80 && grade >= 70){
        return 'C';
    }
    else if (grade < 70 && grade >= 60){
        return 'D';
    }
    else if (grade < 60 && grade >= 50){
        return 'E';
    }
    else{
        return 'F';
    }
}
int main(){
    cout << PrintGrade(ReadGrade(0,100));
}