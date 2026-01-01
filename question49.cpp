#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

const string FileName = "Clients.txt";

struct Client
{
    string account;
    string pin;
    string name;
    string phone;
    double balance;
};

string inputString(const string& msg)
{
    cout << msg;
    string s;
    getline(cin, s);
    return s;
}

vector<string> readFileLines(const string& file)
{
    vector<string> lines;
    fstream fs(file, ios::in);
    if (fs.is_open())
    {
        string line;
        while (getline(fs, line))
            if (!line.empty())
                lines.push_back(line);
        fs.close();
    }
    return lines;
}

vector<string> splitLine(const string& line, const string& delim)
{
    vector<string> tokens;
    size_t pos;
    string temp = line;
    while ((pos = temp.find(delim)) != string::npos)
    {
        string token = temp.substr(0, pos);
        if (!token.empty())
            tokens.push_back(token);
        temp.erase(0, pos + delim.length());
    }
    if (!temp.empty())
        tokens.push_back(temp);
    return tokens;
}

Client makeClient(const vector<string>& data)
{
    Client c;
    c.account = data[0];
    c.pin = data[1];
    c.name = data[2];
    c.phone = data[3];
    c.balance = stod(data[4]);
    return c;
}

vector<Client> loadClients(const vector<string>& lines)
{
    vector<Client> clients;
    for (const string& line : lines)
    {
        clients.push_back(makeClient(splitLine(line, "#//#")));
    }
    return clients;
}

void printClient(const Client& c)
{
    cout << "Client Details:\n";
    cout << "Account : " << c.account << "\n";
    cout << "Pin     : " << c.pin << "\n";
    cout << "Name    : " << c.name << "\n";
    cout << "Phone   : " << c.phone << "\n";
    cout << "Balance : " << c.balance << "\n";
}

Client findClient(const vector<Client>& clients, const string& account)
{
    Client emptyClient;
    for (const Client& c : clients)
        if (c.account == account)
            return c;
    return emptyClient;
}

int main()
{
    vector<string> lines = readFileLines(FileName);
    vector<Client> clients = loadClients(lines);

    string account = inputString("Enter Account Number: ");
    Client c = findClient(clients, account);

    if (!c.name.empty())
        printClient(c);
    else
        cout << "\nClient with Account Number (" << account << ") not found!\n";

    system("pause>0");
}
