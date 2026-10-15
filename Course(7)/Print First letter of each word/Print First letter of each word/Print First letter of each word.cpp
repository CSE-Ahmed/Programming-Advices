#include<iostream>
#include<string>
using namespace std;
string ReadString(string Message) {
	string S1;
	cout << Message << endl;
	getline(cin, S1);
	return S1;
}

void PrintFirstLetter(string S1) {
	bool IsFirstLetter = true;
	for (short i = 0; i < S1.length(); i++) {
		if (S1[i] != ' ' && IsFirstLetter) {
			cout << S1[i] << endl;
		}

		IsFirstLetter = (S1[i] == ' ' ? true : false);
	}
}

int main() {
	PrintFirstLetter(ReadString("Enter your string : "));
}