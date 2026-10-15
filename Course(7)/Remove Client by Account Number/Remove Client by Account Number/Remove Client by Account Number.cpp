#include <iostream>
#include "ClientsManager.h" 

using namespace std;

int main() {

    vector<stClient> vClients = LoadClientsDataFromFile();

    string AccountNumber = ReadAccountNumber();

    DeleteClientByAccountNumber(AccountNumber, vClients);

    system("pause>0");
    return 0;
}