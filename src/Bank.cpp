#include <iostream>
#include <ctype.h>
#include "Bank.h"
using namespace std;

customer::customer(string UN, string IP) // conUNuctor with two parameter
    : username(UN), ip(IP)
{
    if (!(isalpha(UN[0])))
    {
        throw 505; // an error
    }

    for (size_t i = 1; i < UN.size(); i++) // i = 0 was checked recently so i starts from 1
    {

        if (!((UN[i] >= 48 && UN[i] <= 57) ||
              (isalpha(UN[i]))))
        {
            throw "nothing";
        }
    }
}

customer::~customer()
{
}

string customer::get_username()
{
    return username;
}
