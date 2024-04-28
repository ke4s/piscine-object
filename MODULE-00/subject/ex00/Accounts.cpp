#include "Accounts.hpp"


// Accounts::Accounts(int id, std::string customerName, int value): _value(value),_id(id), _customerName(customerName) {} 

Accounts::Accounts() {}

std::string Accounts::getNameAccount(const int id) {
    
    return customerDetails[id]; 
}

int Accounts::getCustomerValue(const int id ){
    return customerValues[id];
}

// std::string Accounts::getNameAccount(const std::string name)const{
//     return name;
// }

void Accounts::setCustomerDetails(std::string name, int id){
   
    customerDetails[id] = name;
}

void Accounts::setCustomerAssets(int id, int value) {
    customerValues[id] = value;
}


bool Accounts::CreateAccount(std::string name, int id)
{
    const std::map<int, std::string>::iterator &searchId = customerDetails.find(id);
    if (searchId == customerDetails.end())
    {
        customerDetails[id] = name;
        customerValues[id] = 0;
        return true;
    }
    
    return false;
}

bool Accounts::DeleteAccount(int id)
{

    
    const std::map<int, std::string>::iterator &searchId = customerDetails.find(id);
    if (searchId != customerDetails.end())
    {
        // if (searchId->first == id && searchId->second == name)
        // {
            customerDetails.erase(searchId);
            const std::map<int, int>::iterator &searchId = customerValues.find(id);
            customerValues.erase(searchId);
            return true;
        // }
        // else
        //     return false;
    }
    
        return false;
}

bool Accounts::ModifyAccount(int id, std::string newName, int newId)
{

    
    const std::map<int, std::string>::iterator &searchId = customerDetails.find(id);
    if (searchId != customerDetails.end())
    {
        // if (searchId->first == id && searchId->second == name)
        // {
        customerDetails.erase(searchId);
        customerDetails[newId] = newName;
        const std::map<int, int>::iterator &searchId = customerValues.find(id);
        int value = searchId->second;
        customerValues.erase(searchId);
        customerValues[newId] = value;

        return true;
        // }
        // else
        //     return false;
    }
    
        return false;
}

int Accounts::GrantingLoans(int loan, int id, int &liqudity)
{
    const std::map<int, int>::iterator &searchId = customerValues.find(id);
    int maxLoanValue = 20*liqudity/100; 
    if (loan <= maxLoanValue)
    {
        if (searchId != customerValues.end())
        {
            // auto totalValue = searchId->second + loan;
            float newLoan;
            liqudity -= loan;
            newLoan -= 0.1*loan;
            return DepositMoney(newLoan, id);
        }
        else
            return 2;
    }
    return 3;
}


bool Accounts::DepositMoney(float value, int id)
{
    
    const std::map<int, int>::iterator &searchId = Accounts::customerValues.find(id);
    float newValue;
    if (searchId != customerValues.end())
    {
        newValue -= value*0.05;
        searchId->second += newValue;
        return true;
    }
  
        return false;
}
bool Accounts::WithdrawMoney(int value, int id) {
    
    const std::map<int, int>::iterator &searchId = customerValues.find(id);
    if (searchId != customerValues.end())
    {
        searchId->second -= value;
        return true;
    }
   
        return false;
}

Accounts::~Accounts(){
    customerDetails.clear();
    customerValues.clear();
}