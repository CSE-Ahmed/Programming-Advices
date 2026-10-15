#include<iostream>
#include<string>
#include<vector>
using namespace std;

string JoinString(vector <string> vString, string delim) {
	string S1 = "";
	for (string& s : vString) {
		S1 = S1 + s + delim;
	}
	return S1.substr(0, S1.length() - delim.length());
}

string JoinString(string ARR[], short lenght, string delim) {
	string S1 = "";
	
	for (short i = 0; i < lenght;i++) {
		S1 = S1 + ARR[i] + delim;
	}

	return S1.substr(0, S1.length() - delim.length());
}

int main() {
	vector <string> vString = { "Ahmed" , "Yasser", "Yousry" };
	string ARR[]            = { "Ahmed" , "Yasser", "Yousry" };
	cout << "After vector : " << JoinString(vString, " ") << endl;
	cout << "After Array  : " << JoinString(ARR, 3, " ");
}