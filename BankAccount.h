#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include "Transaction.h"

class BankAccount {
protected:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;
    // Composition: BankAccount "has-a" history
    std::vector<Transaction> transactionHistory; 

public:
    BankAccount();
    BankAccount(std::string num, std::string name, double bal);
    virtual ~BankAccount(); 

    virtual void withdraw(double amount);
    BankAccount& operator+=(double amount); 
    
    void printHistory();
    static void printAccount(const BankAccount& acc);
    std::string getID();
};

#endif