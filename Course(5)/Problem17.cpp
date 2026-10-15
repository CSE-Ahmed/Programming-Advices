#include<iostream>
using namespace std;
string ReadPassword(){
    string Password;
    do{
        cout << "Enter the password (3 char) : ";
        cin >> Password;
    }
    while (Password.length() != 3);
    return Password;
}
bool GuessPassword(string password){
    string word = "";
    int counter = 0;
    for(int i = 65 ; i <= 90 ; i++){
        for(int j = 65 ; j <= 90 ; j++){
            for(int l = 65 ; l <= 90 ; l++){
                word = word + char(i);
                word = word + char(j);
                word = word + char(l);
                counter++;
                cout << "Trial ["<<counter<<"] : "<< word<<"\n";
                if (password == word){    
                    cout << "\nThe password is : " << word << "\n";
                    cout << "Found after : " << counter << " Trial"<<"\n";
                    return true;
                }
                word = "";
            }
        }
    }
    return false;
}
int main(){
    GuessPassword(ReadPassword());
}