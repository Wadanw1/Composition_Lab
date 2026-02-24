#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "BankAccount.h"

class SavingsAccount : public BankAccount {
private:
    double interestRate;
public:
    SavingsAccount(std::string num, std::string name, double bal, double rate) 
        : BankAccount(num, name, bal) {
        interestRate = rate;
    }

    void calculateInterest() {
        double interest = balance * interestRate;
        balance = balance + interest;
        transactionHistory.push_back({"Interest", interest, "Feb 23"});
    }
};

#endif