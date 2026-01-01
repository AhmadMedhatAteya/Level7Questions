#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;
struct strClient
{
	string Name;
	string PhoneNumber;
	double AccountBalance;
	string PinCode;
	string AccountNumber;


};

strClient convertStringToStructClientData(string ClientData, string Delim)
{
	strClient strClientData;
	int pos = 0;
	if ((pos = ClientData.find(Delim)) != std::string::npos)
	{
		strClientData.AccountNumber = ClientData.substr(0, pos);
		ClientData.erase(0, pos + Delim.length());
	}


	if ((pos = ClientData.find(Delim)) != std::string::npos)
	{
		strClientData.PinCode = ClientData.substr(0, pos);
		ClientData.erase(0, pos + Delim.length());
	}


	if ((pos = ClientData.find(Delim)) != std::string::npos)
	{
		strClientData.Name = ClientData.substr(0, pos);
		ClientData.erase(0, pos + Delim.length());
	}


	if ((pos = ClientData.find(Delim)) != std::string::npos)
	{
		strClientData.PhoneNumber = ClientData.substr(0, pos);
		ClientData.erase(0, pos + Delim.length());
	}


	strClientData.AccountBalance = stod(ClientData);
	return  strClientData;


}
vector<strClient> vStrClientsData(vector <string> vClientsData)
{
	vector <strClient> vStructOfClientsData;
	for (int i = 0; i < vClientsData.size(); i++)
	{
		vStructOfClientsData.push_back(convertStringToStructClientData(vClientsData[i], "#//#"));
	}
	return vStructOfClientsData;
}
vector <string> readClientsDataFromFile(string FileName)
{
	vector <string> vStringClientsData;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		while (getline(MyFile, Line))
		{
			vStringClientsData.push_back(Line);
		}

	}
	MyFile.close();
	return vStringClientsData;
}

void printHeader()
{
	cout << "--------------------------------------------------------------------------------------------------------------\n\n";
	cout << "| " << left << setw(20) << "Account Number " << left << setw(15) << " | Pin Code " << left << setw(25) << "    | Client Name         " << left << setw(15) << "   | Phone      " << setw(15) << "  | Balance \n" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------\n\n";

}
void printClientsDataInScreen(vector <strClient> ClientsData)
{

	for (int i = 0; i < ClientsData.size(); i++)
	{
		cout << "| " << left << setw(20) << ClientsData[i].AccountNumber << " | " << left << setw(15) << ClientsData[i].PinCode << left << setw(25) << " | " + ClientsData[i].Name << setw(15) << " | " + ClientsData[i].PhoneNumber << setw(15) << " | " + to_string(ClientsData[i].AccountBalance) << endl;

	}
	cout << "\n";
	cout << "--------------------------------------------------------------------------------------------------------------\n";
}
int main()
{
	vector<string> stringCleintsFromFileToVector = readClientsDataFromFile("Clients.txt");
	vector <strClient> vectorOfStrClientsData = vStrClientsData(stringCleintsFromFileToVector);
	cout << setw(55) << "Client List (" << vectorOfStrClientsData.size() << ") Client(s).\n" << endl;
	printHeader();
	printClientsDataInScreen(vectorOfStrClientsData);

}