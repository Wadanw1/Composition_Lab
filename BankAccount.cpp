#include "BankAccount.h"
#include <iomanip>

using namespace std;

BankAccount::BankAccount() {
    accountNumber = "0000";
    accountHolderName = "None";
    balance = 0.0;
}

BankAccount::BankAccount(string num, string name, double bal) {
    accountNumber = num;
    accountHolderName = name;
    balance = (bal < 0) ? 0 : bal;
}

BankAccount::~BankAccount() {}

void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance = balance - amount;
        // logic for history
        transactionHistory.push_back({"Withdrawal", amount, "Feb 23"});
    } else {
        cout << "Insufficient funds!!" << endl;
    }
}

BankAccount& BankAccount::operator+=(double amount) {
    if (amount > 0) {
        balance = balance + amount;
        // logic for history
        transactionHistory.push_back({"Deposit", amount, "Feb 23"});
    }
    return *this;
}

void BankAccount::printHistory() {
    cout << "\n--- History for " << accountNumber << " ---" << endl;
    if(transactionHistory.empty()) cout << "No history found." << endl;
    
    for (int i = 0; i < transactionHistory.size(); i++) {
        cout << transactionHistory[i].timestamp << " | " 
             << transactionHistory[i].type << ": $" 
             << transactionHistory[i].amount << endl;
    }
}

void BankAccount::printAccount(const BankAccount& acc) {
    cout << fixed << setprecision(2);
    cout << "Acc: " << acc.accountNumber << " | Balance: $" << acc.balance << endl;
}

string BankAccount::getID() {
    return accountNumber;
}