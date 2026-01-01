
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

char readCharFromUser(string message)
{
	char Ch1;
	cout << message << endl;
	cin >> Ch1;
	return Ch1;
}
bool CheckVowelOrNot(char Ch)
{
	Ch = tolower(Ch);
	return (Ch == 'a' || Ch == 'e' || Ch == 'i' || Ch == 'o' || Ch == 'u');
}

int main()
{

	char Ch = readCharFromUser("Please Enter Ur Char : ");
	if (CheckVowelOrNot(Ch))
		cout << "Vowel";
	else
		cout << "Not Vowel";
}