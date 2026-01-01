#include <iostream>
#include <string>
#include <vector>

using namespace std;
string ReplaceWordInStringUsingBuiltInFunc(string S1, string stringToReplace, string sReplaceTo)
{
	short pos = S1.find(stringToReplace);
	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, stringToReplace.length(), sReplaceTo);
		pos = S1.find(stringToReplace); // find next
	}
	return S1;
}
int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "Jordan";
	string ReplaceTo = "USA";
	cout << "\nOrigial String\n" << S1;
	cout << "\n\nString After Replace:";
	cout << "\n" << ReplaceWordInStringUsingBuiltInFunc(S1, StringToReplace, ReplaceTo);
	system("pause>0");
}





/* another way
string readStringFromUser(string Message)
{
	string S1;
	cout << Message << endl;
	getline(cin, S1);
	return S1;
}
vector <string> vWordsOfString(string S1)
{
	string Delim = " ";
	string tmpString = "";
	vector <string> vWords;
	int pos = 0;
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		tmpString = S1.substr(0, pos);
		if (tmpString != "")
		{
			vWords.push_back(tmpString);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vWords.push_back(S1);
	}
	return vWords;
}
string fromVectorToString(vector<string>vWords)
{
	string delim = " ";
	string String = "";
	for (string S : vWords)
	{
		String = String + S + delim;
	}
	return (String.substr(0, String.length() - delim.length()));
}
vector <string> replaceWordInVectorOfStrings(string FromString , vector <string> vWords , string ToString )
{

	for (int i = 0; i < vWords.size(); i++)
	{
		if (vWords[i] == FromString)
		{
			vWords[i] = ToString;
		}
	}
	return vWords;
}

int main()
{
	string OriginalString = readStringFromUser("Please Enter Original String : ");
	cout << "\nOriginal String : \n" << OriginalString << endl;

	vector <string> vWordsOfStrinG = vWordsOfString(OriginalString);
	string FromWord = readStringFromUser("\nPelease Enter The Word The U Need To Update it in The String : ");
	string ToWord = readStringFromUser("\nPlease Enter The New Word That U Need To Replace : ");

	vWordsOfStrinG = replaceWordInVectorOfStrings(FromWord, vWordsOfStrinG, ToWord);
	cout << "\n\nString After Replace : \n";
	cout << fromVectorToString(vWordsOfStrinG);


}
*/