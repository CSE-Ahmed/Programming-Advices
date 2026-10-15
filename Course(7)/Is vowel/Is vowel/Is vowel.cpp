#include<iostream>
using namespace std;
char ReadChar(string Messages) {
	char ch;
	cout << Messages << endl;
	cin >> ch;
	return ch;
}
void toLower(char ch) {
	ch = tolower(ch);
}
bool isVowel(char ch) {
	toLower(ch);
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
		return true;
	}
	else {
		return false;
	}
}
void PrintResult(char ch, bool isVowel) {
	if (isVowel) {
		cout << ch << " is a vowel." << endl;
	}
	else {
		cout << ch << " is not a vowel." << endl;
	}
}
int main() {
	char ch = ReadChar("Enter a character: ");
	bool vowel = isVowel(ch);
	PrintResult(ch, vowel);
	return 0;
}	