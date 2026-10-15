#include<iostream>
#include<string>
using namespace std;


string ReadString() {
	string S1;
	cout << "Enter your string: \n";
	getline(cin, S1);
	return S1;
}


string TrimLeft(string S1) {
	while (S1[0] == ' ') {
		S1.erase(0 , 1);
	}
	return S1;
}


string TrimRight(string S1) {

	while (S1[S1.length() - 1] == ' ') {
		S1.erase(S1.length() - 1, 1);
	}

	return S1;
}


string TrimAll(string S1) {
	return TrimRight(TrimLeft(S1));
}


int main() {
	cout << TrimAll(ReadString());
}