#include<iostream>
#include<cstdlib>
using namespace std;
int RandomNumber(int from , int to){
    int Random = rand() % (to - from + 1 ) + from;
    return Random;
}
enum enCharType {
    Small_letter = 1 , 
    Capital_letter = 2 , 
    Special_Characcter = 3 , 
    Digit = 4
};
char RandomCharacter(enCharType CharType){
    switch(CharType){
        case enCharType::Small_letter:
        {
            return char(RandomNumber(97,122));
            break;
        }
        case enCharType::Capital_letter:
        {
            return char(RandomNumber(65,90));
            break;
        }
        case enCharType::Special_Characcter:
        {
            return char(RandomNumber(33,47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48,57));
            break;
        }
    }
    return '\0';
}
int main(){
    srand((unsigned)time(NULL));
    cout << RandomCharacter(enCharType::Small_letter) << "\n";
    cout << RandomCharacter(enCharType::Capital_letter) << "\n";
    cout << RandomCharacter(enCharType::Special_Characcter) << "\n";
    cout << RandomCharacter(enCharType::Digit) << "\n";
    return 0;
}