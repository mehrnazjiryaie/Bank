#include <iostream>
#include <ctype.h>
#include <exception>
#include <random>
#include "Bank.h"
#include "Transaction.h"
using namespace std;

// MyException::MyException(const char * err) {}
unsigned int convert(string &str)
{
    int number;
    number = stoi(str);
    return number;
}

unsigned int convert(char &ch)
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
    for (size_t i = 1; i < UN.size(); i++) // i = 0 was checked recently so it starts from 1
    {

        if (!((UN[i] >= 48 && UN[i] <= 57) ||
              (isalpha(UN[i]))))
        {
            throw(c); // an error
        }
    }

    ip_validation(IP);

    ips.push_back(IP);

    default_random_engine eng(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> myrand(1000, 9999);
    card_number = myrand(eng);
    std::cout << "Your card number is : " << card_number << endl;

    balance = 25000;
}

customer::~customer()
{
}

string customer::get_username()
{
    return username;
}

void customer::set_ip(string IP)
{
    ips.push_back(IP);
    for (size_t i = 0; i < ips.size(); i++)
    {
        std::cout << ips[i] << "\t";
    }
}

void customer::set_opening_date(int open_date)
{
    opening_date = open_date;
}

void customer::set_expiration_date(int exp)
{
    expiration_date = exp;
}

int customer::get_expiration_date()
{
    return expiration_date;
}

int customer::get_opening_date()
{
    return opening_date;
}

void customer::check_expiration_date_for_renewal()
{
    // std::cout << expiration_date - opening_date << endl;
    // std::cout << get_expiration_date() - get_opening_date() << endl;
    if ((get_expiration_date() - get_opening_date()) <= 2 && (get_expiration_date() - get_opening_date()) >= 0)
    {
        throw runtime_error("Your account has not expired yet!!\n");
    }
}

void customer::check_expiration_date_for_transaction()
{
    if (!((get_expiration_date() - get_opening_date()) > 2))
    {
        throw runtime_error("Your account has not expired!!\n");
    }
}

unsigned long int customer::get_balance()
{
    return balance;
}

void customer::set_balance(unsigned long int blnc)
{
    balance = blnc;
}

void customer::ip_validation(string IP)
{
    size_t i = 0;

    string IP1;
    string IP2;
    string IP3;
    string IP4;

    int dot = 0; // counts the number of dots in ip

    while (IP[i] != '.' && IP[i])
    {
        IP1 += IP[i];
        i++;
    }
    if (IP[i] == '.')
    {
        dot++;
    }
    i++;

    while (IP[i] != '.' && IP[i])
    {
        IP2 += IP[i];
        i++;
    }
    if (IP[i] == '.')
    {
        dot++;
    }
    i++;

    while (IP[i] != '.' && IP[i])
    {
        IP3 += IP[i];
        i++;
    }
    if (IP[i] == '.')
    {
        dot++;
    }
    i++;

    while (IP[i] && IP[i])
    {
        if (IP[i] == '.')
        {
            dot++;
        }
        IP4 += IP[i];
        i++;
    }

    double d;
    if (!(dot == 3))
    {
        throw(d);
    }

    int part1 = convert(IP1);
    int part2 = convert(IP2);
    int part3 = convert(IP3);
    int part4 = convert(IP4);

    float b;
    if (!(part1 >= 0 && part1 <= 255) || !(part2 >= 0 && part2 <= 255) || !(part3 >= 0 && part3 <= 255) || !(part4 >= 0 && part4 <= 255))
    {
        throw(b);
    }
}

void add_ip(string username, vector<customer> &moshtari, string ip)
{
    for (size_t i = 0; i < moshtari.size(); i++)
    {
        if (username == moshtari[i].get_username())
        {
            try
            {
                moshtari[i].ip_validation(ip);
                moshtari[i].set_ip(ip);
            }

            catch (float f)
            {
                std::cout << "Invalid ip - each part of ip must be between 0 and 255.\n";
            }

            catch (double d)
            {
                std::cout << "Invalid ip - ip must include for parts and exactly 3 dots.\n";
            }
        }
    }
}

bool customer::get_ips(string ip) // this function checks if an ip belong to an account or not
{
    for (size_t i = 0; i < ips.size(); i++)
    {
        if (ip == ips[i])
        {
            std::cout << "true\n";
            return true;
        }
    }
}

void renewal(vector<customer> &moshtari, size_t &i)
{
    char ch;
    std::cout << "Your expiration time of your account has been finished!! Do you wanna renewal your account? (For renewal you have to pay 5000 Toman.) (type y as 'yse' or n as 'no')\n";
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        // here does a validation for when balance is zero and have to get loan
        moshtari[i].set_balance(moshtari[i].get_balance() - 5000);              // here decrease the renewal cost from account balance
        moshtari[i].set_expiration_date(moshtari[i].get_expiration_date() + 2); // change // this updates the expiration account
        std::cout << moshtari[i].get_expiration_date() << endl;
        std::cout << "congrats" << endl;
    }
    else if (ch == 'n' || ch == 'N')
    {
        return;
    }
}

customer check_existance_account(vector<customer> &moshtari, string s)
{
    for (size_t i = 0; i < moshtari.size(); i++)
    {
        if (moshtari[i].get_username() == s)
        {
            return moshtari[i];
            //throw invalid_argument("The destination account does not exist with these username or ip!\n");
        }
        else
        {
            cout <<"fuch\n";
            return moshtari[i];
        }
    }
}