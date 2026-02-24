cmake_minimum_required(VERSION 3.26)
project(Composition_Lab)

set(CMAKE_CXX_STANDARD 17)


add_executable(Composition_Lab
        main.cpp
        BankAccount.cpp
        BankAccount.h
        CheckingAccount.h
        SavingsAccount.h
        Transaction.h)