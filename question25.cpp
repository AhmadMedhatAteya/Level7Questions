#include <iostream>
#include <string>

using namespace std;
string readStringFromUser(string message)
{
	string s1;
	cout << message << endl;
	getline(cin, s1);
	return s1;
}
string LowerFirstLetterInEachWordInTheString(string S)
{
	bool isFirstLetter = true;
	for (short i = 0; i < S.length(); i++)
	{
		if (S[i] != ' ' && isFirstLetter)
		{
			S[i] = tolower(S[i]);
		}
		isFirstLetter = (S[i] == ' ' ? true : false);
	}
	return S;
}

int main()
{
	string s = readStringFromUser("Please Enter String : ");
	cout << "After Conv : \n" << LowerFirstLetterInEachWordInTheString(s);
}