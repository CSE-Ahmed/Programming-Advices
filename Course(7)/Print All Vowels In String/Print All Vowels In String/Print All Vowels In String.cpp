#include<iostream>
#include<string>
using namespace std;

string ReadString(string Message) {
	string str;
	cout << Message << endl;
	getline(cin, str);
	return str;
}

bool IsVowel(char ch) {
	ch = tolower(ch);
	return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void PrintAllVowelsInString(string str) {
	cout << "Vowels in the string are: ";
	for (short i = 0; i < str.length(); i++) {
		if (IsVowel(str[i])) {
			cout << str[i] << " ";
		}
	}
	cout << endl;
}

int main() {
	string str = ReadString("Enter a string: ");
	PrintAllVowelsInString(str);
	return 0;
}