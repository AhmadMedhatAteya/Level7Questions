#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
struct strClientData
{
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	double AccountBalance;
};
string readStringFromUser(string message)
{
	string S1;
	cout << message;
	getline(cin, S1);
	return S1;

}
double readDoubleFromUser(string message)
{
	double number;
	cout << message;
	cin >> number;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');

		cout << "You Entered a Wrong value , please try again :  ";
		cin >> number;
	}
	return number;
}
strClientData ReadClientData()
{
	strClientData Client;
	Client.AccountNumber = readStringFromUser("Please Enter Account Number : ");
	Client.PinCode = readStringFromUser("Enter Pin Code : ");
	Client.Name = readStringFromUser("Enter Name : ");
	Client.PhoneNumber = readStringFromUser("Enter Phone Number : ");
	Client.AccountBalance = readDoubleFromUser("Enter AccountBalance : ");

	return Client;
}
string structClientToStringClient(strClientData ClientData, string Delim)
{
	string S = ClientData.AccountNumber + Delim + ClientData.Name + Delim + ClientData.PinCode + Delim + ClientData.PhoneNumber + Delim + to_string(ClientData.AccountBalance);
	return S;
}
vector <string> VectorOfClientsData()
{
	string tmpStringClientData;
	strClientData tmpClientData;
	vector <string> vClientsData;
	char choice;
	cout << "Do U Want To Add a Client ? [Y/N] : ";
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	while (choice == 'Y' || choice == 'y')
	{
		system("cls");
		cout << "Adding New Client : \n\n";

		tmpClientData = ReadClientData();
		tmpStringClientData = structClientToStringClient(tmpClientData, "#//#");
		vClientsData.push_back(tmpStringClientData);
		cout << "Client Added Sucessfuly , do you want to add more clients ? [Y/N] : ";
		cin >> choice;
		cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');

	}
	system("cls");
	return vClientsData;
}
void saveClientsDataToFile(vector <string> vClientData, string FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::app | ios::out);

	if (MyFile.is_open())
	{
		for (const string& S : vClientData)
		{
			if (S != "")
				MyFile << S << endl;
		}
	}
	MyFile.close();

}
int main()
{
	vector <string> vClientsData = VectorOfClientsData();
	saveClientsDataToFile(vClientsData, "MyFilee.txt");
}