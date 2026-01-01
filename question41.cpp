#include <iostream>
#include <vector >
#include <string>
using namespace std;
string readStringFromUser(string Message)
{
	string S1;
	cout << Message << endl;
	getline(cin, S1);
	return S1;
}
vector <string> splitStringToVector(string S1)
{
	string Delim = " ";
	string tmpWord = "";
	vector <string> vWords;
	int pos = 0;
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		tmpWord = S1.substr(0, pos);
		if (tmpWord != "")
			vWords.push_back(tmpWord);

		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
		vWords.push_back(S1);

	return vWords;

}
string reverseString(vector<string> vWordsOfString, string Delim = " ")
{
	string reversedString = "";
	for (int i = vWordsOfString.size() - 1; i >= 0; i--)
	{
		if (vWordsOfString[i] != " ")
			reversedString = reversedString + vWordsOfString[i] + Delim;
	}

	return reversedString.substr(0, reversedString.length() - Delim.length());
}


int main()
{
	string S1 = readStringFromUser("Please Enter String : ");
	vector <string> vWords = splitStringToVector(S1);
	cout << "\nString After Reversing Words : \n" << reverseString(vWords);
}