#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string FileName = "Clients.txt";

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string PhoneNumber;
    double AccountBalance;
};

vector<string> splitterStringToRecord(string S1, string Splitter = "#//#")
{
    vector<string> vClients;
    int pos;

    while ((pos = S1.find(Splitter)) != string::npos)
    {
        vClients.push_back(S1.substr(0, pos));
        S1.erase(0, pos + Splitter.length());
    }

    if (!S1.empty())
        vClients.push_back(S1);

    return vClients;
}

stClient convertVectorToStruct(vector<string> vClient)
{
    stClient ClientData;

    ClientData.AccountNumber = vClient[0];
    ClientData.PinCode = vClient[1];
    ClientData.Name = vClient[2];
    ClientData.PhoneNumber = vClient[3];
    ClientData.AccountBalance = stod(vClient[4]);

    return ClientData;
}

string convertRecordToLine(stClient Client, string Delim = "#//#")
{
    string S1 = "";

    S1 += Client.AccountNumber + Delim;
    S1 += Client.PinCode + Delim;
    S1 += Client.Name + Delim;
    S1 += Client.PhoneNumber + Delim;
    S1 += to_string(Client.AccountBalance);

    return S1;
}

vector<stClient> loadClientsFromFile()
{
    vector<stClient> Clients;
    fstream MyFile(FileName, ios::in);
    string Line;

    while (getline(MyFile, Line))
    {
        if (!Line.empty())
            Clients.push_back(convertVectorToStruct(splitterStringToRecord(Line)));
    }

    MyFile.close();
    return Clients;
}

void saveToFile(vector<stClient> Clients)
{
    fstream MyFile(FileName, ios::out);

    for (stClient C : Clients)
        MyFile << convertRecordToLine(C) << endl;

    MyFile.close();
}

void printClientDetails(stClient Client)
{
    cout << "\nAccount Number : " << Client.AccountNumber;
    cout << "\nPin Code       : " << Client.PinCode;
    cout << "\nName           : " << Client.Name;
    cout << "\nPhone          : " << Client.PhoneNumber;
    cout << "\nAccount Balance: " << Client.AccountBalance << endl;
}

int findClientIndexByAccountNumber(vector<stClient>& Clients, string AccountNumber)
{
    for (int i = 0; i < Clients.size(); i++)
    {
        if (Clients[i].AccountNumber == AccountNumber)
            return i;
    }
    return -1;
}

void ClientDataUpdate(vector<stClient>& Clients)
{
    string AccountNumber;
    char Answer;

    cout << "Please Enter Account Number: ";
    cin >> AccountNumber;

    int Index = findClientIndexByAccountNumber(Clients, AccountNumber);

    if (Index == -1)
    {
        cout << "Client Not Found\n";
        return;
    }

    printClientDetails(Clients[Index]);

    cout << "\nAre you sure you want to update this client? y/n: ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
        cout << "\nEnter Pin Code: ";
        cin >> Clients[Index].PinCode;

        cout << "Enter Name: ";
        cin >> Clients[Index].Name;

        cout << "Enter Phone: ";
        cin >> Clients[Index].PhoneNumber;

        cout << "Enter Account Balance: ";
        cin >> Clients[Index].AccountBalance;

        saveToFile(Clients);

        cout << "\nClient Updated Successfully\n";
    }
}

int main()
{
    vector<stClient> vClients = loadClientsFromFile();
    ClientDataUpdate(vClients);
    return 0;
}
