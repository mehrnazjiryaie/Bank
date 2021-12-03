#include <iostream>
#include "Bank.h"

class transaction
{
private:
    customer beginning;            // the account that transfers money
    customer destination;          // the account that receives money
    unsigned long int payment = 0; // the payment that is going to transfer
    int date;                      // just year

public:
    transaction();
    ~transaction();
};