#include<iostream>
#include<string>
#include<vector>
using namespace std;

string ReadString() {
	string str;
	cout << "Enter your string: \n";
	getline(cin, str);
	return str;
}

vector <string> splitString(string str, string delim) {
	vector <string> vString;
	short pos = 0;
	string sword;
	
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

int main() {
	vector <string> vString;
	vString = splitString(ReadString(), " ");
	cout << "Tokens : " << vString.size() << endl;

	for (string& s : vString)
	{
		cout << s << endl;
	}

 }