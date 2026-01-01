#include <iostream>
using namespace std;
#include <string>
string readStringFromUser(string message)
{
	string S1;
	cout << message << endl;
	getline(cin, S1);
	return S1;
}

void printFirstLetterOfEachWordInString(string s1)
{
	bool isFirstLetter = true;
	cout << "First Letters Of this String : \n";

	for (short i = 0; i < s1.length(); i++)
	{
		if (s1[i] != ' ' && isFirstLetter)
		{
			cout << s1[i] << endl;
		}
		isFirstLetter = (s1[i] == ' ' ? true : false);
	}
}

int main()
{
	string S1 = readStringFromUser("Please Enter Your String ? ");
	printFirstLetterOfEachWordInString(S1);
	system("pause>0");

}