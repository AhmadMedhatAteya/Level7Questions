
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

void printEachWordInString(string S1)
{
	string sWord = "";
	string delim = " ";
	int pos = 0;
	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
			cout << sWord << endl;

		S1.erase(0, pos + delim.length());
	}
	if (S1 != "")
		cout << S1 << endl;
}
int main()
{

	string S1 = readStringFromUser("Please Enter Your String : ");
	printEachWordInString(S1);

}