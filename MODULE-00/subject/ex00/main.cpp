#include "Accounts.hpp"
#include "Bank.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib> 

std::string getCustomerId()
{
    char id[10000];
    bzero(id,10000);

    std::cout << "Please enter customer id : \n";
    std::cin >> id;
    if (std::strlen(id) > 10)
    {
        std::cout << "This id too long, Process canceled\n";
        return "Process canceled";
    }

    int count = 0;
    for (size_t i = 0; i < std::strlen(id); ++i)
    {
        if (!std::isdigit(id[i]))
        {
            count++;
            if (count > 3)
            {
                std::cout << "Process canceled\n";
                return "Process canceled";
            }

            std::cout << "Please enter integer value : \n";
            std::cin >> id;
            i = -1;
        }
    }
    return id;
}

std::string getCustomerValue()
{
    char value[10000];
    bzero(value,10000);
    std::cout << "Please enter value : \n";
    std::cin >> value;

    if (std::strlen(value) > 10)
    {
        std::cout << "This value too long, Process canceled\n";
        return "Process canceled";
    }
    int count = 0;
    for (size_t i = 0; i < std::strlen(value); ++i)
    {
        if (!std::isdigit(value[i]))
        {
            count++;
            if (count > 3)
            {
                std::cout << "Process canceled\n";
                return "Process canceled";
            }

            std::cout << "Please enter integer value : \n";
            std::cin >> value;
            i = -1;
        }
    }
    return value;
}

std::string getCustomerName()
{
    std::string name;
    std::cout << "Please enter your Name : \n";
    std::cin >> name;
    if (name.size() > 50)
    {
        std::cout << "This name too long, Process canceled\n";
        return "Process canceled";
    }
    return name;
}

int main(int argc, const char **argv)
{

    std::string customerResponse;
    std::string id;
    std::string value;
    if (argc != 2)
    {
        std::cerr << "Please enter liqudity!!!\n";
        return 1;
    }

    for (const char *c = argv[1]; *c != '\0'; c++)
    {

        if (!std::isdigit(static_cast<char>(*c)))
        {
            std::cerr << "Please enter integer value!!!\n";
           return 1;
        }
    }

    if (std::strlen(argv[1]) >= 2)
    {
        if (std::atoi(std::string(1, *argv[1]).c_str()) == 0)
        {
            std::cout << "Please enter valid value!!!\n";
            return 1;
        }
    }

    Bank *bank = new Bank(std::atoi(argv[1]));

    while (1)
    {
        std::cout << "Hello Dear, \n"
                    << "Do you member in our bank,\n"
                    << "Plese enter \"Yes\" or \"No\" : \n\n";
        std::cin >> customerResponse;

        if (customerResponse == "Yes")
        {
            std::cout << "Please enter the action you wish to take => \"DepositMoney\" or \"WithdrawMoney\" or \"AccountTransactions\" or \"TakeALoan\" : \n ";
            std::cin >> customerResponse;
            
            if (customerResponse == "DepositMoney")
            {
                std::string id = getCustomerId();
                std::string value = getCustomerValue();

                if (id == "Process canceled" || value == "Process canceled")
                {
                    std::cout << "Have a nice day.\n\n";
                    continue;
                }
                
                std::cout << strtoull(value.c_str(), NULL, 10) << "   " << id << "\n";
                if (strtoull(value.c_str(), NULL, 10) > 2147483647)
                {
                    std::cout << "You can enter max 2147483647 as values.\n";
                    std::cout << "Your transaction canceled.\n\n";
                    continue;
                }
                
                bool response = bank->DepositMoney(strtoull(value.c_str(), NULL, 10), strtoull(id.c_str(), NULL, 10));
                if (response == true)
                {
                    std::cout << "Your transaction completed successfully.\n";
                    std::cout << "Your updated value is : " << bank->getCustomerValue(strtoull(id.c_str(), NULL, 10)) << ".\n\n";
                }
                else
                {
                    std::cout << "This account was not found.\n\n";
                }
            }
            else if (customerResponse == "WithdrawMoney")
            {
                std::string id = getCustomerId();
                std::string value = getCustomerValue();
                if (id == "Process canceled" || value == "Process canceled")
                {
                    std::cout << "Have a nice day.\n\n";
                    continue;
                }
                std::cout << "Values : " << value << " , id :  " << id << "\n";
                if (strtoull(value.c_str(), NULL, 10) > 2147483647)
                {
                    std::cout << "You can enter max 2147483647 as values.\n";
                    std::cout << "Your transaction canceled.\n\n";
                    continue;
                }
                unsigned long long customerValue = bank->getCustomerValue(strtoull(id.c_str(), NULL, 10));
                if (customerValue < strtoull(value.c_str(), NULL, 10))
                {
                    std::cout << "Your value is : " << customerValue << ".\n";
                    std::cout << "Your transaction canceled.\n\n";
                    continue;
                }
                
                bool response = bank->WithdrawMoney(strtoull(value.c_str(), NULL, 10), strtoull(id.c_str(), NULL, 10));
                if (response == true)
                {
                    std::cout << "Your transaction completed successfully.\n";
                    std::cout << "Your updated value is : " << bank->getCustomerValue(strtoull(id.c_str(), NULL, 10)) << ".\n\n";
                }
                else
                {
                    std::cout << "This account was not found.\n";
                    std::cout << "Your transaction canceled.\n\n";
                    
                }
            }
            else if (customerResponse == "TakeALoan")
            {
                std::string id = getCustomerId();
                for (int it = 0; it < 3; ++it)
                {
                    std::string value = getCustomerValue();
                    if (id == "Process canceled" || value == "Process canceled")
                    {
                        std::cout << "Have a nice day.\n";
                        std::cout << "Your transaction canceled.\n\n";
                        continue;
                    }
                    if (strtoull(value.c_str(), NULL, 10) > 2147483647)
                    {
                        std::cout << "You can enter max 2147483647 as values.\n";
                        std::cout << "Your transaction canceled.\n\n";
                        break;
                    }
                    int response = bank->GrantingLoans(strtoull(value.c_str(), NULL, 10), strtoull(id.c_str(), NULL, 10));
                    if (response == 1)
                    {
                        std::cout << "Your transaction completed successfully, and money deposited your account.\n";
                        std::cout << "Your updated value is : " << bank->getCustomerValue(strtoull(id.c_str(), NULL, 10)) << ".\n\n";
                        break;
                    }
                    else if (response == 2)
                    {
                        std::cout << "This account was not found.\n";
                        std::cout << "Your transaction canceled.\n\n";
                        break;
                    }
                    else if (response == 3)
                    {
                        std::cout << "You can't get that much credit." << bank->getLiqudity() << " US dollars you can get a loan.\n\n";
                        if (it == 2)
                        {
                            std::cout << "Process canceled.\n\n";
                            // break;
                        }
                    }
                }
                
            }
            else if (customerResponse == "AccountTransactions")
            {
                std::cout << "Please enter the action you wish to take => \"ModifyAccount\" or \"DeleteAccount\" : \n\n ";
                std::cin >> customerResponse;
                if (customerResponse == "ModifyAccount")
                {
                    std::string id = getCustomerId();
                    if (id == "Process canceled")
                    {
                        std::cout << "Have a nice day.\n\n";
                        continue;
                    }
                    
                    std::cout << "You must enter new name.\n";
                    std::string customerNewName = getCustomerName();
                    std::cout << "You must enter new id.\n";
                    std::string newId = getCustomerId();
                    if (newId == "Process canceled")
                    {
                        std::cout << "Have a nice day.\n\n";
                        continue;
                    }
                    bool response = bank->ModifyAccount( strtoull(id.c_str(), NULL, 10), customerNewName, strtoull(newId.c_str(), NULL, 10));
                    if (response == true)
                    {
                        std::cout << "Your transaction completed successfully.\n\n";
                    }
                    else
                    {
                        std::cout << "This account was not found.\n";
                        std::cout << "Your transaction canceled.\n\n";
                    }
                }
                else if (customerResponse == "DeleteAccount")
                {
                    std::string id = getCustomerId();
                    if (id == "Process canceled")
                    {
                        std::cout << "Have a nice day.\n\n";
                        continue;
                    }
                    bool response = bank->DeleteAccount(strtoull(id.c_str(), NULL, 10));
                    if (response == true)
                    {
                        std::cout << "Your transaction completed successfully.\n\n";
                    }
                    else
                    {
                        std::cout << "This account was not found.\n";
                        std::cout << "Your transaction canceled.\n\n";
                    }
                }
                else
                {
                    std::cout << "Undefined action.\n";
                    std::cout << "Your transaction canceled.\n\n";
                }
            }
            else
            {
                std::cout << "Undefined action.\n";
                std::cout << "Your transaction canceled.\n\n";
            }
        }
        else if (customerResponse == "No")
        {
            std::cout << "Do you want to create account? Please enter \"Yes\" or \"No\" : \n";
            std::cin >> customerResponse;
            if (customerResponse == "Yes")
            {
                std::string id = getCustomerId();
                if (id == "Process canceled")
                {
                    std::cout << "Have a nice day.\n\n";
                    continue;
                }
                std::string name = getCustomerName();
                bool response = bank->CreateAccount(name, strtoull(id.c_str(), NULL, 10));
                if (response == true)
                {
                    std::cout << "Your transaction completed successfully.\n\n";
                }
                else
                {
                    std::cout << "This account already exists.\n";
                    std::cout << "Your transaction canceled.\n\n";
                }
            }
            else
            {
                std::cout << "We are waiting again. \n";
                std::cout << "Your transaction canceled.\n\n";
            }
        }
        
        
        
        
    }
    
/**
 * @todo Check entered value, if value grater than int value , print error;
 * @todo Handle getCustomerName error.
*/





    return 0;
}