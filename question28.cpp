#include <iostream>
#include <string>

using namespace std;
string readStringFromUser(string message)
{
	string S1;
	cout << message << endl;
	getline(cin, S1);
	return S1;
}
char InvertCharacterCase(char Character)
{
	return Character = (isupper(Character) ? tolower(Character) : toupper(Character));
}
string InvertAllLettersInString(string S1)
{

	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = InvertCharacterCase(S1[i]);
	}
	return S1;
}
int main()
{
	string S1 = readStringFromUser("Enter Ur String To Invert Case  : ");
	cout << "After Invert :\n" << InvertAllLettersInString(S1) << endl;
	system("pause>0");
}