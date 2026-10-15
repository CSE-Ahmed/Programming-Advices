#include<iostream>
using namespace std;

char ReadCharacter(string Message) {
	char ch;
	cout << Message << endl;
	cin >> ch;
	return ch;
}

char invertingCase(char ch) {
	if (islower(ch)) {
		ch = toupper(ch);
	}
	else {
		ch = tolower(ch);
	}
	cout << "Your character after inverting: \n";
	return ch;
}

int main() {
	cout << invertingCase(ReadCharacter("Enter your character:"));
}