#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct strClientData
{
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	double AccountBalance;
};
vector <string> splitterStringToVectorOfStrings(string S1, string Delim)
{
	vector <string> vDataOfString;
	string tmpString = "";
	int pos = 0;
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		tmpString = S1.substr(0, pos);
		if (tmpString != "")
		{
			vDataOfString.push_back(tmpString);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vDataOfString.push_back(S1);
	}
	return vDataOfString;
}
strClientData vectorDataToStructData(vector <string> vClientDataLine)
{
	strClientData ClientData;

	ClientData.AccountNumber = vClientDataLine[0];
	ClientData.PinCode = vClientDataLine[1];
	ClientData.Name = vClientDataLine[2];
	ClientData.PhoneNumber = vClientDataLine[3];
	ClientData.AccountBalance = stod(vClientDataLine[4]);

	return ClientData;

}
void printClientData(strClientData ClientData)
{
	cout << "\nThe Following is extracted Client Record : \n\n";
	cout << "Account Number  : " << ClientData.AccountNumber;
	cout << "\nPin Code        : " << ClientData.PinCode << endl;
	cout << "Name            : " << ClientData.Name << endl;
	cout << "Phone           : " << ClientData.PhoneNumber << endl;
	cout << "Account Balance : " << ClientData.AccountBalance << endl;
}
int main()
{
	string LineOfData = "A150#//#1234#//#Mohammad Abu Hadhoud#//#043724#//#5210";
	vector <string> vClientDataInVector = splitterStringToVectorOfStrings(LineOfData, "#//#");
	strClientData ClientData = vectorDataToStructData(vClientDataInVector);
	printClientData(ClientData);
	system("pause>0");

}

