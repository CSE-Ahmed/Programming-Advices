#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> SplitString(string S1, string delim) {
	vector<string> vString;
	short pos = 0;
	string sword;

	while ((pos = S1.find(delim)) != std::string::npos) {
		
		sword = S1.substr(0, pos);
		
		if (sword != "") {

			vString.push_back(sword);
		}

		S1.erase(0, pos + delim.length());
	}

	if (S1 != "") {

		vString.push_back(S1);
	}

	return vString;
}

string JoinString(vector<string> vString, string delim) {
	
	string S1;
	
	for (string& s : vString) {
		
		S1 = S1 + s + delim;
	}

	return S1.substr(0, S1.length() - delim.length());

}

string LowerString(string S1) {
	
	for (short i = 0; i < S1.length(); i++) {
		
		S1[i] = tolower(S1[i]);
	}

	return S1;
}

string ReplaceWords(string S1, string toReplace, string ReplaceTo, bool Matchcase = true) {
	
	vector <string> vString = SplitString(S1, " ");
	
	for (string& s : vString) {
	
		if (Matchcase) {
		
			if (s == toReplace) {
			
				s = ReplaceTo;
			}
		}
		
		else {
		
			if (LowerString(s) == LowerString(toReplace)) {
			
				s = ReplaceTo;
			
			}
		}
	}
	
	return JoinString(vString, " ");
}

int main() {
	vector <string> vString;
	string S1 = "i love Cairo";
	string toReplace = "cairo";
	string Replaceto = "Alexandria";
	
	cout << "The Origianl String is : " << S1 << endl;
	
	cout << "The Replace String with matchcase : " << ReplaceWords(S1, toReplace, Replaceto, true) << endl;

	cout << "The Replace String without matchcase : " << ReplaceWords(S1, toReplace, Replaceto, false);
}