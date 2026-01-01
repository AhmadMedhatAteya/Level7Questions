#include <iostream>
#include <string>

using namespace std;
enum enWhatToCount { Small = 1, Capital = 2, All = 3 };



string readStringFromUser(string message)
{
	string S1;
	cout << message << endl;
	getline(cin, S1);
	return S1;
}
int CounterForLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
{
	int Counter = 0;
	if (WhatToCount == enWhatToCount::Small)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
				Counter++;
		}
		return Counter;
	}
	else if (WhatToCount == enWhatToCount::Capital)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
				Counter++;
		}
		return Counter;
	}

	return S1.length();

}
enWhatToCount readWhatToCountFromUser()
{
	int Choice;
	cout << "Please Enter What U Need To Counter : \n[1]Small Letter \n[2]Capital Letters \n[3]All Letters \nUr Choice :  ";
	cin >> Choice;
	return enWhatToCount(Choice);

}
void PrintResultChoice(enWhatToCount WhatToCount)
{
	switch (WhatToCount)
	{
	case enWhatToCount::Small: cout << "Small Letters : ";
		break;
	case enWhatToCount::Capital: cout << "Capital Letters : ";
		break;
	default: cout << "All Letters : ";
		break;
	}
}
int main()
{
	string S = readStringFromUser("Please Enter Your String ? ");
	cout << endl;
	enWhatToCount WhatToCount = readWhatToCountFromUser();

	PrintResultChoice(WhatToCount);
	cout << CounterForLetters(S, WhatToCount);
}