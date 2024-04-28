#pragma once
#include "Accounts.hpp"


class Bank : public Accounts
{
protected:
    int _liquidity;
    Accounts *account;
public:
    Bank(int liquidity);
    
    bool CreateAccount(std::string name, int id);
    bool DeleteAccount(int id);
    bool ModifyAccount( int id, std::string newName, int newId);
    int GrantingLoans(int loan, int id);
    bool DepositMoney(long long unsigned int value, long long unsigned int id);
    bool WithdrawMoney(int value, int id);
    int getLiqudity()const;
    int getCustomerValue(int id)const;
    


    ~Bank();
};
