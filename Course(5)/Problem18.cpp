#include<iostream>
using namespace std;
string ReadText(){
    string text;
    cout << "Enter your text?\n";
    getline(cin,text);
    return text;
}
string Encryption(string text , short EncryptionKey){
    for (int i = 0 ; i <= text.length() ; i++){
        text[i] = char((int)text[i] + EncryptionKey);
    }
    return text;
}
string Decryption(string text , short EncryptionKey){
    for (int i = 0 ; i <= text.length() ; i++){
        text[i] = char((int)text[i] - EncryptionKey);
    }
    return text;
}
int main(){
    const short EncryptionKey = 2;
    string Text = ReadText();
    string TextAfterEncryption = Encryption(Text , EncryptionKey);
    string TextAfterDecryption = Decryption(TextAfterEncryption , EncryptionKey);
    cout << "Your text after encryption : " << TextAfterEncryption <<"\n";
    cout << "Your text after decryption : " << TextAfterDecryption <<"\n";
}