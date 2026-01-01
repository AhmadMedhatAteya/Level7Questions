#include <iostream>
#include <vector >
#include <string>
using namespace std;

string readStringFromUser(string message)
{
	string S1;
	cout << message;
	getline(cin, S1);
	return S1;
}
string VectorToString(vector <string> vStrings, string Delim)
{
	string resultString = "";
	for (const string& S : vStrings)
	{
		resultString += S;
		resultString += Delim;
	}
	resultString = resultString.substr(0, resultString.length() - Delim.length());
	return resultString;
}

int main()
{
	vector <string> vStrings = { "Ahmad" , "Mohammed" , "Fadi" , "Ali" };
	cout << "Vector After Join : \n" << VectorToString(vStrings, "-");

}