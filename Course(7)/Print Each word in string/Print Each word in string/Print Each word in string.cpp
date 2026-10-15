#include<iostream>
#include<string>
using namespace std;

string ReadString() {
	string str;
	cout << "Enter a string: ";
	getline(cin, str);
	return str;
}

void PrintEachWordInString(string str) {
	string delim = " ";
	short pos = 0;
	string sWord;
	while ((pos = str.find(delim)) != std::string::npos) {
		
		sWord = str.substr(0, pos);
		if (sWord != "") {
			cout << sWord << endl;
		}
		
		str.erase(0, pos + delim.length());

		
	}
	if (str != "") {
			cout << str << endl;
		}
}

int main() {
	PrintEachWordInString(ReadString());
}