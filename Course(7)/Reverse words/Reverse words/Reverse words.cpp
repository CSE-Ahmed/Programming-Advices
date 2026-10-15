#include<iostream>
#include<vector>
#include<string>
using namespace std;

string ReadString() {
	string str;
	cout << "Enter your string : \n";
	getline(cin, str);
	return str;
}

vector <string> SplitString(string str) {
	string delim = " ";
	short pos = 0;
	string sword;
	vector <string> vString;

	while ((pos = str.find(delim)) != std::string::npos) {
		sword = str.substr(0, pos);

		if (sword != "") {
			vString.push_back(sword);
		}

		str.erase(0, pos + delim.length());
	}

	if (str != "") {
		vString.push_back(str);
	}

	return vString;
}

string ReverseString(string str) {
	vector <string> vString;
	string S2 = "";
	vString = SplitString(str);
	vector <string>::iterator iter = vString.end();
	
	while (iter != vString.begin()) {
		--iter;
		S2 += *iter + " ";
	}
	S2 = S2.substr(0, S2.length() - 1);
	return S2;
}

int main() {
	string str = ReadString();

	cout << "String after reverse is : \n" << ReverseString(str) << endl;
}