#include <iostream>
#include <vector>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

using namespace std;

int main() {
    vector<BankAccount*> accounts;

    accounts.push_back(new CheckingAccount("Wes-Check", "Wes", 300.0, 2.0));
    accounts.push_back(new SavingsAccount("Wes-Save", "Wes", 1000.0, 0.04));

    // Do transactions
    accounts[0]->withdraw(50.0);
    *accounts[0] += 200.0;

    accounts[1]->withdraw(100.0);
    SavingsAccount* s = dynamic_cast<SavingsAccount*>(accounts[1]);
    if(s) s->calculateInterest();

    // Print histories
    for (auto acc : accounts) {
        acc->printHistory();
    }

    for (auto acc : accounts) delete acc;
    return 0;
}