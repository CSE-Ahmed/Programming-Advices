#include<iostream>
#include<cstdlib>
using namespace std;
int ReadNumber(){
    int Num;
    do{
        cout << "Enter positive number?\n";
        cin >> Num;
    }
    while(Num <= 0);
    return Num;
}
enum enCharType{
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCharacter = 3,
    Digit = 4
};
int RandomCharacter(int from , int to){
    int Random = rand() % (to - from + 1) + from;
    return Random;
}
char RandomCharacter(enCharType CharType){
    switch(CharType)
    {
        case enCharType::CapitalLetter:
        {
            return char(RandomCharacter(65,90));
            break;
        }
        case enCharType::SmallLetter:
        {
            return char(RandomCharacter(97,122));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomCharacter(33,47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomCharacter(48,57));
            break;
        }
    }
    return '\0';
}
string GenerateWord(enCharType CharType , short length){
    string word;
    for (int i = 0 ; i <= length ; i++){
        word = word + RandomCharacter(CharType);
    }
    return word;
}
string GenerateKey(){
    string key;
    key = GenerateWord(enCharType::CapitalLetter , 4) + "-";
    key = key + GenerateWord(enCharType::CapitalLetter , 4) + "-";
    key = key + GenerateWord(enCharType::CapitalLetter , 4) + "-";
    key = key + GenerateWord(enCharType::CapitalLetter , 4);
    return key;
}
void GenerateKeys(int NumberOfKeys){
    for (int i = 1 ; i <= NumberOfKeys ; i++){
        cout << "Key["<<i<<"] : ";
        cout << GenerateKey() << "\n";
    }
}
int main(){
    srand((unsigned)time(NULL));
    GenerateKeys(ReadNumber());
}