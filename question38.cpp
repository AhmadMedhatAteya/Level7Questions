#include <iostream>
#include <string>
#include <vector>
using namespace std;
enum enTrim { TrimRight = 1, TrimLeft = 2, TrimAll = 3 };
int readNumberFromUser()
{
	int number;
	while (true)
	{
		cin >> number;

		if (!cin.fail() && number >= 1 && number <= 3)
			return number;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "You Entered a Wrong Value, Please Enter Number Between 1 & 3:\n";
	}
}

string readStringFromUser(string Message)
{
	cout << Message << endl;
	string S1;
	getline(cin, S1);
	return S1;
}
enum enTrim readTrimFromUser()
{
	int number = 0;
	cout << "Please Enter What U Need to do : \n[1]Trim Right\n[2]Trim Left \n[3]Trim All\n";
	number = readNumberFromUser();
	return enTrim(number);
}
string TrimRightForString(string S1)
{
	for (int i = S1.length() - 1; i >= 0; i--)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(0, i + 1);
		}
	}
	return "";
}
string TrimLeftForString(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(i, S1.length() - i);
		}

	}
	return "";
}
string TrimAllForString(string S1)
{
	return (TrimLeftForString(TrimRightForString(S1)));
}
string stringAfterTrim(enTrim TrimType, string S1)
{
	if (TrimType == enTrim::TrimRight)
	{
		return TrimRightForString(S1);
	}
	else if (TrimType == enTrim::TrimLeft)
	{
		return TrimLeftForString(S1);
	}
	return TrimAllForString(S1);
}

int main()
{
	string S1 = readStringFromUser("Please Enter Ur String : ");
	enTrim Type = readTrimFromUser();
	cout << "\nString After Trim : " << stringAfterTrim(Type, S1) << endl << endl;

}