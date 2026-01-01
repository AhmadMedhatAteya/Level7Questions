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
string UpperCaseTheFirstLetterOfEachWordInString(string S1)
{
	bool isFirstLetter = true;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFirstLetter)
		{
			S1[i] = toupper(S1[i]);
		}
		isFirstLetter = (S1[i] == ' ' ? true : false);
	}

	return S1;
}

int main()
{
	string S1 = readStringFromUser("Enter String : ");
	cout << "String After Conv : \n";
	cout << UpperCaseTheFirstLetterOfEachWordInString(S1);
}
