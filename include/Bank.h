#ifndef BANK_H
#define BANK_H
#include <iostream>
#include <vector>

class customer
{
private:
    string username;           // account username
    int card_number;           // a four digit number
    long int oppening_date;    // not sure about its type
    long int expiration_date;  // not sure about its type
    unsigned long int balance; // account balance
    struct transaction;        // account transaction
    string ip;                 // first account ip
    vector<string> ips;         // account ips
public:
    customer(string, string);
    ~customer();
};

#endif
