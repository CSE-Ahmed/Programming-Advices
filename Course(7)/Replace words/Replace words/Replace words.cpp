#include<iostream>
#include<string>

using namespace std;

string ReadString() {
	string str;
	cout << "Enter your string : \n";
	getline(cin, str);
	return str;
}

string ReplaceWords(string S1) {
	string S2 , S3;
	cout << "Enter the word that you want to replace : \n";
	cin >> S2;
	short pos = S1.find(S2);
	short length = S2.length();
	cout << "Enter the replace word : \n";
	cin >> S3;
	while (S1.find(S2) != string::npos) {
		S1.replace(pos, length, S3);

		pos = S1.find(S2);
	}
	cout << "The string after replace : \n";
	return S1;
}

int main() {
	string str = ReadString();
	cout << ReplaceWords(str);
}