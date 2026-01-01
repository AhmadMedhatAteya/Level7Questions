#include <iostream>
#include <string>
#include <vector>

using namespace std;
string removeAllPunctuationsFromString(string S1)
{
	string S = "";
	int pos = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i]))
			S += S1[i];
	}
	return S;
}

int main()
{
	string S1 = "Welomce To Jordan , Jordan is a nice countr; it's amazing";
	cout << "String Before Remove Punc : " << S1 << endl;
	cout << "\nString After Remove Punc : " << removeAllPunctuationsFromString(S1) << endl;
	system("pause>0");
}

