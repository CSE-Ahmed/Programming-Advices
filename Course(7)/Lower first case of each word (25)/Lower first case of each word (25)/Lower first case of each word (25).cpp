#include<iostream>
#include<string>
using namespace std;
string ReadString(string Message) {
	string S1;
	cout << Message << endl;
	getline(cin, S1);
	return S1;
}

void ToLower(string S1) {
	bool IsFirstLetter = true;
	for (short i = 0; i < S1.length(); i++) {
		if (S1[i] != ' ' && IsFirstLetter) {
			S1[i] = tolower(S1[i]);
		}

		IsFirstLetter = (S1[i] == ' ' ? 1 : 0);

	}

	cout << S1 << endl;
}

int main() {
	ToLower(ReadString("Enter your string : "));
}