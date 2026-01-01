#include <iostream>
#include <string>
using namespace std;

string readStringFromUser(string Message)
{
	cout << Message << endl;
	string S1;
	getline(cin, S1);
	return S1;
}
int CountEachWordInString(string S1)
{
	string sWord = "";
	int pos = 0;
	int counter = 0;
	string Delim = " ";

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
			counter++;

		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
		counter++;

	return counter;
}

int main()
{
	string S1 = readStringFromUser("Please Enter String ? ");
	cout << "The number of words in ur string is : " << CountEachWordInString(S1);

	system("pause>0");
}