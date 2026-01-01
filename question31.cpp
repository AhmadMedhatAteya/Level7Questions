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
char readCharFromUser(string message)
{
	char Ch1;
	cout << message << endl;
	cin >> Ch1;
	return Ch1;
}
string upperAllLettersInString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = toupper(S1[i]);
	}
	return S1;
}
int countOfCharacterInStringIgnoreCase(string S1, char Ch)
{

	int counter = 0;
	S1 = upperAllLettersInString(S1);
	Ch = toupper(Ch);
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Ch)
			counter++;
	}
	return counter;
}
int counterOfCharacterInString(string S1, char Ch)
{
	int count = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Ch)
			count++;
	}
	return count;
}
int main()
{
	string S1 = readStringFromUser("Please Enter Ur String : ");
	char Ch = readCharFromUser("Please Enter Ur Char : ");
	cout << "Letter " << (char)tolower(Ch) << " Or " << (char)toupper(Ch) << " = " << countOfCharacterInStringIgnoreCase(S1, Ch);


	cout << "\nLetter " << "'" << Ch << "' Count = " << counterOfCharacterInString(S1, Ch);
}