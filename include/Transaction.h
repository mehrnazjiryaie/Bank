#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include "Bank.h"

class transaction
{
private:
    std::string beginning;
    std::string destination;
    unsigned int payment;
    int date;
public:
    transaction(customer &, customer &, unsigned int);
   ~transaction();
};
#endif
