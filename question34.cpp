
#include <iostream>
#include <cctype>
#include <string>
using namespace std;
string readStringFromUser(string message)
{
	string S1;
	cout << message << endl;
	getline(cin, S1);
	return S1;
}
bool CheckVowelOrNot(char Ch)
{
	Ch = tolower(Ch);
	return (Ch == 'a' || Ch == 'e' || Ch == 'i' || Ch == 'o' || Ch == 'u');
}
void printVowlesInString(string S1)
{
	cout << "Vowels in string are : ";
	for (short i = 0; i < S1.length(); i++)
	{
		if (CheckVowelOrNot(S1[i]))
			cout << S1[i] << "\t";
	}
}

int main()
{
	string S1 = readStringFromUser("Please Enter Your String ? ");
	printVowlesInString(S1);


}