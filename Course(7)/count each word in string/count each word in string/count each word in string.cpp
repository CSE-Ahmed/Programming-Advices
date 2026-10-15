#include<iostream>
#include<string>
using namespace std;

string ReadString() {
	string str;
	cout << "Enter your string: \n";
	getline(cin, str);
	return str;
}

short countEachWord(string str) {
	string delim = " ";
	short pos = 0;
	string sword;
	short counter = 0;
	while ((pos = str.find(delim)) != std::string::npos) {
		
		sword = str.substr(0, pos);
		if (sword != "") {
			counter++;
		}

		str.erase(0, pos + delim.length());
	}
	if (str != "") {
		counter++;
	}
	return counter;
}

int main() {
	string str = ReadString();
	cout << "The number of words is: " << countEachWord(str);
}