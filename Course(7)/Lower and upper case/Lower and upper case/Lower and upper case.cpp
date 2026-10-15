#include<iostream>
#include<string>
using namespace std;

string ReadString(string Message) {
	string S1;
	cout << Message << endl;
	getline(cin, S1);
	return S1;
}

string ToUpperCase(string S1) {
	for (short i = 0; i < S1.length(); i++) {
		S1[i] = toupper(S1[i]);
	}

	return S1;
}

string ToLowerCase(string S1) {
	for (short i = 0; i < S1.length(); i++) {
		S1[i] = tolower(S1[i]);
	}

	return S1;
}

int main() {
	string S1 = ReadString("Enter your string : ");

	cout << "Your string after upper case : \n" << ToUpperCase(S1) << endl;

	cout << "Your string after lower case : \n" << ToLowerCase(S1);
}