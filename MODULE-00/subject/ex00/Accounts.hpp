#pragma once

#include <iostream>
#include <map>



class Accounts
{
protected:
    int _id;
    int _value;
    std::string _customerName;
    std::map<int ,std::string> customerDetails;
    std::map<int ,int> customerValues;
public:
    // Accounts(int id, std::string _customerName, int value);
    Accounts();
    ~Accounts();

    std::string getNameAccount(const int id);
    int getCustomerValue(const int id );
    int GrantingLoans(int loan, int id, int &liqudity);
    // std::string getNameAccount(const std::string _customerName)const;
    void setCustomerDetails(std::string name, int id);
    void setCustomerAssets(int id, int value);

    bool CreateAccount(std::string name, int id);
    bool DeleteAccount( int id);
    bool ModifyAccount(int id, std::string newName, int newId);
    int GrantingLoans(int loan, int id);
    bool DepositMoney(float value, int id);
    bool WithdrawMoney(int value, int id);
    // void setNameAccount(const std::string _customerName);
    // void setIdAccount(const int id);

};
