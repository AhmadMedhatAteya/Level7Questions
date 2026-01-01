#include <iostream>
#include <string>
#include <vector>
using namespace std;

string readStringFromUser(string Message)
{
	cout << Message << endl;
	string S1;
	getline(cin, S1);
	return S1;
}
vector <string> SplitTheStringToVectorOfWords(string S1, string Delim)
{
	vector <string> vWords;
	string tmpWord = "";
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
void printElementsOfStringVector(vector<string> vString)
{
	for (const string& S1 : vString)
	{
		cout << S1 << endl;
	}
}
int main()
{
	string S1 = readStringFromUser("Please Enter String ? ");
	string Delim = readStringFromUser("Please Enter The Delim : ");
	vector <string> vWords = SplitTheStringToVectorOfWords(S1, Delim);
	cout << "\nTokens : " << vWords.size();
	cout << "\nWords Of The String : \n";
	printElementsOfStringVector(vWords);
	system("pause>0");
}