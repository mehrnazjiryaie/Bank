#ifndef BANK_H
#define BANK_H
#include <iostream>
#include <vector>

class customer
{
private:
    std::string username;         // account username
    int card_number;              // a four digit number
    long int oppening_date;       // not sure about its type
    long int expiration_date;     // not sure about its type
    unsigned long int balance;    // account balance
    struct transaction;           // account transaction
    std::string ip;               // first account ip
    std::vector<std::string> ips; // account ips
public:
    customer(std::string, std::string);
    ~customer();
    std::string get_username();

};

#endif
