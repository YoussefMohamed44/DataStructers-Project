// BankSystem.h
#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include <iostream>
#include <string>

//CLASS CREATION
class Bank_System {
    struct account {
        int account_ID;
        std::string customer_Name;
        int password;
        double Balance = 0;
        account* next;
    };
    account* head;
    int count;

public:
    Bank_System();
    bool IsEmpty(double Balance);
    bool SearcAccount(int Acc_ID);
    void Create_Account();
    void check_balance();
    void withdrawing();
    void Depositing();
    void Delete_Account();
    void Count_Accounts();
};

//DISPLAY MENU FUNCTION CREATION
void displayMenu();

#endif // BANKSYSTEM_H
