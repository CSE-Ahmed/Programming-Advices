#include<iostream>
#include<string>
using namespace std;

string ReadString(string Message) {
	string S1;
	cout << Message << endl;
	getline(cin, S1);
	return S1;
}
char InvertingCharCase(char ch) {
	return isupper(ch) ? tolower(ch) : toupper(ch);
}
string InvertingAllLowerCase(string S1) {
	for (short i = 0; i < S1.length(); i++) {
		S1[i] = InvertingCharCase(S1[i]);
	}
	cout << "The string after Inverting: \n";
	return S1;
}

int main() {
	cout << InvertingAllLowerCase(ReadString("Enter your string: "));
}