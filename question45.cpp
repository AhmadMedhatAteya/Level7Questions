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
strClientData ReadClientData()
{
	strClientData ClientData;
	cout << "Enter Account Number     : "; getline(cin, ClientData.AccountNumber);
	cout << "Enter PIN Code           : "; getline(cin, ClientData.PinCode);
	cout << "Enter Name               : "; getline(cin, ClientData.Name);
	cout << "Enter Phone              : "; getline(cin, ClientData.PhoneNumber);
	cout << "Enter Account Balance    : "; cin >> ClientData.AccountBalance;
	return ClientData;
}
string convertClientDataToOneLine(strClientData ClientData, string Delim)
{
	string S = "";
	S = S + ClientData.AccountNumber + Delim + ClientData.PinCode + Delim + ClientData.Name + Delim + ClientData.PhoneNumber + Delim + (to_string)(ClientData.AccountBalance);
	return S;
}
int main()
{
	cout << "Please Enter Client Data  \n\n";
	strClientData Client1 = ReadClientData();
	cout << "\n\nClient Record For string is : \n";
	cout << convertClientDataToOneLine(Client1, "#//#");

}

