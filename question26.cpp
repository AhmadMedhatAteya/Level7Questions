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
string UpperAllLettersOfString(string S)
{
	for (short i = 0; i < S.length(); i++)
	{
		S[i] = toupper(S[i]);
	}
	return S;
}
string LowerAllLettersOfString(string S)
{
	for (short i = 0; i < S.length(); i++)
	{
		S[i] = tolower(S[i]);
	}
	return S;
}

int main()
{
	string S = readStringFromUser("Please Enter Ur String : ");
	cout << "After Upper Ur String : \n" << UpperAllLettersOfString(S) << endl;
	cout << "After Lower Ur String : \n" << LowerAllLettersOfString(S) << endl;
}