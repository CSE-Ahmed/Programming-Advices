/*#include<iostream>
#include<string>
using namespace std;
string ReadString(string Message)
{
	string str;
	cout << Message;
	getline(cin, str);
	return str;
}
bool isVowel(char ch) {
	ch = tolower(ch);
	return ((ch == 'a') || (ch == 'e') || (ch == 'o') || (ch == 'i') || (ch == 'u'));
}
int CountVowel(string str) {
	short counter = 0;
	for (short i = 0; i < str.length(); i++) {
		if (isVowel(str[i])) {
			counter++;
		}
	}
	cout << "The number of vowels character is : ";
	return counter;
}
int main() {
	cout << CountVowel(ReadString("Enter your string : "));

}*/
#include <string>
#include <iostream>
using namespace std;
string ReadString()
{
	string S1;
	cout << "\nPlease Enter Your String?\n";
	getline(cin, S1);
	return S1;
}
bool IsVowel(char Ch1)
{
	Ch1 = tolower(Ch1);
	return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1
		== 'o') || (Ch1 == 'u'));
}
short CountVowels(string S1)
{
	short Counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (IsVowel(S1[i]))
			Counter++;
	}
	return Counter;
}
int main()
{
	string S1 = ReadString();
	cout << "\nNumber of vowels is: " << CountVowels(S1);
	system("pause>0");
}