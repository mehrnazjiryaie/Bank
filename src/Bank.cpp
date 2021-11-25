#include <iostream>
#include <ctype.h>
#include <exception>
#include <random>
#include "Bank.h"

using namespace std;

// MyException::MyException(const char * err) {}
int convert(string str)
{
    int number;
    number = stoi(str);
    return number;
}

int convert(char ch)
{
    int number;
    number = ch - 48;
    return number;
}

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

    string IP1;
    string IP2;
    string IP3;
    string IP4;

    while (IP[i])
    {
        while (IP[i] != '.')
        {
            IP1 += IP[i];
            i++;
        }
        i++;

        while (IP[i] != '.')
        {
            IP2 += IP[i];
            i++;
        }
        i++;

        while (IP[i] != '.')
        {
            IP3 += IP[i];
            i++;
        }
        i++;

        while (IP[i])
        {
            IP4 += IP[i];
            i++;
        }
    }

    cout << IP << "\t" << IP1 << "\t" << IP2 << "\t" << IP3 << "\t" << IP4 << endl;
    int part1 = convert(IP1);
    int part2 = convert(IP2);
    int part3 = convert(IP3);
    int part4 = convert(IP4);

    float b;
    if (!(part1 >= 0 && part1 <= 255) || !(part2 >= 0 && part2 <= 255) || !(part3 >= 0 && part3 <= 255) || !(part4 >= 0 && part4 <= 255))
    {
        throw (b);
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
