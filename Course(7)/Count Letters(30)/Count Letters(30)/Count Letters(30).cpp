#include<iostream>
#include<string>
using namespace std;

string ReadString(string Message) {
	string S1;
	cout << Message << endl;
	getline(cin, S1);
	return S1;
}
char ReadChar(string Message) {
	char ch;
	cout << Message << endl;
	cin >> ch;
	return ch;
}
int CountLetter(string S1, char ch) {
	short counter = 0;
	for (short i = 0; i < S1.length(); i++) {
		if (S1[i] == ch) {
			counter++;
		}
	}
	cout << "letter '" << ch << "' count = ";
	return counter;
}

int main() {
	string S1 = ReadString("Enter your string: ");
	char ch = ReadChar("Enter your charachter: ");
	cout << CountLetter(S1, ch);
}