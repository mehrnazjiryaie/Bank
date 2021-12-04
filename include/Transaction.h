#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include "Bank.h"

class transaction
{
private:
    customer beginning;
    customer destination;
    unsigned int payment;
    int date;

public:
    transaction(customer, customer, unsigned int);
    ~transaction();
};
#endif
