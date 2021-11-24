#include <iostream>
#include "Bank.h"
using namespace std;

customer::customer(string UN, string IP) // constructor with two parameter
    : username(UN), ip(IP)
{
    try
    {
        if (!('a' <= username[0] <= 'z') || !('A' <= username[0] <= 'Z'))
        {
            throw 505;
        }

        for (size_t i = 1; i < username.size(); i++) // i = 0 was checked recently
        {
            if (!(0 <= username[i] <= 9) || !('a' <= username[i] <= 'z') || !('A' <= username[i] <= 'Z'))
            {
                throw "Invalid username!! - username must include upper or lower case or integer numbers";
            }
        }
    }

    catch (int num)
    {
        cerr << "Invalid username!! - username must start with an letter." << '\n';
    }

    catch (string msg)
    {
        cout << msg << endl;
    }
}

customer::~customer()
{
}
