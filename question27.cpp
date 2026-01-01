#include <iostream>
#include <string>

using namespace std;
char readCharFromUser(string message)
{
	char Ch1;
	cout << message << endl;
	cin >> Ch1;
	return Ch1;
}
char InvertCharacterCase(char Character)
{
	return Character = (isupper(Character) ? tolower(Character) : toupper(Character));
}

int main()
{
	char Ch1 = readCharFromUser("Please Enter Character : ");
	cout << "Char after inverting case : " << InvertCharacterCase(Ch1) << endl;
	system("pause>0");
}