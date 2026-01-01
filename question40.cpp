#include <iostream>
#include <vector >
#include <string>
using namespace std;

string ArrayOfStringsToOneString(string ArrOfStrings[], int lengthOfArry, string Delim)
{
	string S1;
	for (int i = 0; i < lengthOfArry; i++)
	{
		if (ArrOfStrings[i] != "")
		{
			S1 += ArrOfStrings[i];
			S1 += Delim;
		}
	}
	return S1.substr(0, S1.length() - Delim.length());
}


int main()
{
	string ArrOfStrings[] = { "Ahmad", "Mohammed" , "Fadi" , "Ali" };
	cout << "Array After Join : \n";
	cout << ArrayOfStringsToOneString(ArrOfStrings, 4, "-");
}