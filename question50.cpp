#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const string FileName = "Clients.txt";

struct strClientData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string PhoneNumber;
    double AccountBalance;
    bool MarkForDelete = false;
};

vector<string> splitLineToVector(string Line, string Delim)
{
    vector<string> vClientsData;
    int pos;

    while ((pos = Line.find(Delim)) != string::npos)
    {
        vClientsData.push_back(Line.substr(0, pos));
        Line.erase(0, pos + Delim.length());
    }

    if (!Line.empty())
        vClientsData.push_back(Line);

    return vClientsData;
}

strClientData stClientsData(vector<string> vClientData)
{
    strClientData ClientData;

    ClientData.AccountNumber = vClientData[0];
    ClientData.PinCode = vClientData[1];
    ClientData.Name = vClientData[2];
    ClientData.PhoneNumber = vClientData[3];
    ClientData.AccountBalance = stod(vClientData[4]);

    return ClientData;
}

vector<strClientData> LoadClientsFromFile()
{
    vector<strClientData> vClients;
    fstream MyFile(FileName, ios::in);
    string Line;

    while (getline(MyFile, Line))
    {
        if (!Line.empty())
            vClients.push_back(
                stClientsData(splitLineToVector(Line, "#//#"))
            );
    }

    MyFile.close();
    return vClients;
}

string ConvertVectorToLine(strClientData Client, string Delim)
{
    string ClientLineData = "";

    ClientLineData += Client.AccountNumber + Delim;
    ClientLineData += Client.PinCode + Delim;
    ClientLineData += Client.Name + Delim;
    ClientLineData += Client.PhoneNumber + Delim;
    ClientLineData += to_string(Client.AccountBalance);

    return ClientLineData;
}

void PrintClientCard(strClientData Client)
{
    cout << "\nAccount Number  : " << Client.AccountNumber;
    cout << "\nPin Code        : " << Client.PinCode;
    cout << "\nName            : " << Client.Name;
    cout << "\nPhone           : " << Client.PhoneNumber;
    cout << "\nAccount Balance : " << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, vector<strClientData> vClients, strClientData& Client)
{
    for (strClientData C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<strClientData>& vClients)
{
    for (strClientData& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

void SaveClientsDataToFile(string FileName, vector<strClientData> vClients)
{
    fstream MyFile(FileName, ios::out);

    for (strClientData C : vClients)
    {
        if (!C.MarkForDelete)
            MyFile << ConvertVectorToLine(C, "#//#") << endl;
    }

    MyFile.close();
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<strClientData>& vClients)
{
    strClientData Client;
    char Answer;

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "\nDelete this client? y/n: ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveClientsDataToFile(FileName, vClients);
            return true;
        }
    }
    return false;
}

int main()
{
    vector<strClientData> vClients = LoadClientsFromFile();

    string AccountNumber;
    cout << "Enter Account Number: ";
    cin >> AccountNumber;

    if (DeleteClientByAccountNumber(AccountNumber, vClients))
        cout << "\nClient Deleted Successfully\n";
    else
        cout << "\nClient Not Found\n";

    return 0;
}
