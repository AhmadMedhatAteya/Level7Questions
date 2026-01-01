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
int countCharInString(string S1, char Ch)
{
	int counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Ch)
			counter++;
	}
	return counter;
}
int main()
{
	string S1 = readStringFromUser("Please Enter Your Stirng ? ");
	char Ch = readCharFromUser("Please Enter a Character ? ");

	cout << "\nLetter " << "'" << Ch << "'" << "Count = " << countCharInString(S1, Ch);

}