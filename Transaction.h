#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

// This is the struct we are "composing" into BankAccount
struct Transaction {
    std::string type;
    double amount;
    std::string timestamp; 
};

#endif