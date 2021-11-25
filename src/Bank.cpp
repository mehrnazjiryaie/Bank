#include <iostream>
#include <ctype.h>
#include <exception>
#include <random>
#include "Bank.h"

using namespace std;

// MyException::MyException(const char *err) {}

customer::customer(string UN, string IP) // constructor with two parameter
    : username(UN), ip(IP)
{
    
    // if (!(is_Empty))
    // {
    //     for (size_t i = 0; i < usernames.size(); i++)
    //     {
    //         if (UN == usernames[i])
    //         {
    //             throw("Repeated username!! - try another username.\n");
    //         }
    //     }
    // }
    // is_Empty = false;

    if (!(isalpha(UN[0])))
    {
        throw 505; // an error
    }
    char c;
    for (size_t i = 1; i < UN.size(); i++) // i = 0 was checked recently so i starts from 1
    {

        if (!((UN[i] >= 48 && UN[i] <= 57) ||
              (isalpha(UN[i]))))
        {
            throw(c); // an error
        }
    }
    size_t i = 0;

    char* IP1, IP2, IP3, IP4;

    while (IP[i])
    {
        if (IP[i] == '.')
        {
            i++;
        }
        IP1 = IP[i];
        
    }

    default_random_engine eng(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> myrand(1000, 9999);
    card_number = myrand(eng);
    cout << card_number << endl;

    balance = 0;
}

customer::~customer()
{
}

string customer::get_username()
{
    return username;
}
