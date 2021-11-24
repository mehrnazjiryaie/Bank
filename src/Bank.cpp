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

    // if (!(isalpha(UN[0])))
    // {
    //     throw 505; // an error
    // }

    for (size_t i = 1; i < UN.size(); i++) // i = 0 was checked recently so i starts from 1
    {
        // if (!(UN[i] >= 48 && UN[i] <= 57))
        // {
        //     throw "Invalid username!! - username must include upper case or lower case or unsigned integer numbers";
        // }

        // if (!(isalpha(UN[i])))
        // {
        //     throw "ksjflk\n";
        // }

        // if (!(isalpha(UN[i])))
        // {
        //     throw "kk\n";
        // }

        // if (!((UN[i] <= 48 && UN[i] >= 57) ||
        //     (UN[i] <= 65 && UN[i] >= 90) ||
        //     (UN[i] <= 97 && UN[i] >= 122)))
        //     {
        //         throw "Invalid username!! - username must include upper case or lower case or unsigned integer numbers";
        //     }

        if (!((UN[i] >= 48 && UN[i] <= 57) ||
              (isalpha(UN[i]))))
        {
            throw "nothing";
        }
    }
}

customer::~customer()
{
    // try
    // {
    //     if (!('a' <= username[0] <= 'z') || !('A' <= username[0] <= 'Z'))
    //     {
    //         throw 505; // an error
    //     }

    //     for (size_t i = 1; i < username.size(); i++) // i = 0 was checked recently
    //     {
    //         if (!(0 <= username[i] <= 9) || !('a' <= username[i] <= 'z') || !('A' <= username[i] <= 'Z'))
    //         {
    //             throw "Invalid username!! - username must include upper or lower case or integer numbers";
    //         }
    //     }
    // }
    // catch (int num)
    // {
    //     cerr << "Invalid username!! - username must start with an letter." << '\n';
    // }

    // catch (UNing msg)
    // {
    //     cout << msg << endl;
    // }
}

string customer::get_username()
{
    return username;
}
