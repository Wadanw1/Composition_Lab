#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "BankAccount.h"

class CheckingAccount : public BankAccount {
private:
    double transactionFee;
public:
    CheckingAccount(std::string num, std::string name, double bal, double fee) 
        : BankAccount(num, name, bal) {
        transactionFee = fee;
    }

    void withdraw(double amount) override {
        // applying fee
        BankAccount::withdraw(amount + transactionFee);
    }
};

#endif