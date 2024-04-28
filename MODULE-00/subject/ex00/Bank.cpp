#include "Bank.hpp"

// Accounts *account = new Accounts();

Bank::Bank(int liquidity) : _liquidity(liquidity), account(new Accounts()) {}

bool Bank::CreateAccount(std::string name, int id)
{
    ////Accounts account;
    return account->CreateAccount(name, id);
    // const auto &searchId = account.customerDetails.find(id);
    // if (searchId == account.customerDetails.end())
    // {
    //     account.customerDetails[id] = name;
    //     return true;
    // }
    // else
    //     return false;
}

bool Bank::DeleteAccount( int id)
{

    //Accounts account;
    return account->DeleteAccount( id);
    // const auto &searchId = account.customerDetails.find(id);
    // if (searchId != account.customerDetails.end())
    // {
    //     if (searchId->first == id && searchId->second == name)
    //     {
    //         account.customerDetails.erase(searchId);
    //         return true;
    //     }
    //     else
    //         return false;
    // }
    // else
    //     return false;
}

bool Bank::ModifyAccount( int id, std::string newName, int newId)
{

    //Accounts account;
    return account->ModifyAccount( id, newName, newId);
    // const auto &searchId = account.customerDetails.find(id);
    // if (searchId != account.customerDetails.end())
    // {
    //     if (searchId->first == id && searchId->second == name)
    //     {
    //         account.customerDetails.erase(searchId);
    //         account.customerDetails[newId] = newName;
    //         return true;
    //     }
    //     else
    //         return false;
    // }
    // else
    //     return false;
}
int Bank::GrantingLoans(int loan, int id)
{
    return account->GrantingLoans(loan, id, _liquidity);
    //Accounts account;
    // const auto &searchId = account->customerValues.find(id);
    // auto maxLoanValue = 20*_liquidity/100; 
    // if (loan < maxLoanValue)
    // {
    //     if (searchId != account->customerValues.end())
    //     {
    //         // auto totalValue = searchId->second + loan;
    //         _liquidity -= loan;
    //         loan += 0.05*loan;
    //         return account->DepositMoney(loan, id);
    //     }
    //     else
    //         return 2;
    // }
    // return 3;
}
bool Bank::DepositMoney(long long unsigned int value,long long unsigned int id)
{
    //Accounts account;
    return account->DepositMoney(value, id);
    // const auto &searchId = account.customerValues.find(id);
    // if (searchId != account.customerValues.end())
    // {
    //     searchId->second += value;
    //     return true;
    // }
    // else
    //     return false;
}
bool Bank::WithdrawMoney(int value, int id) {
    //Accounts account;
    return account->WithdrawMoney(value, id);
    // const auto &searchId = account.customerValues.find(id);
    // if (searchId != account.customerValues.end())
    // {
    //     searchId->second -= value;
    //     return true;
    // }
    // else
    //     return false;
}

int Bank::getLiqudity()const
{
    return _liquidity*20/100;
}

int Bank::getCustomerValue(int id)const
{
    return account->getCustomerValue(id);
}

Bank::~Bank() {
    delete account;
}
