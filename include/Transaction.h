#include <iostream>

class transaction
{
private:
    std::string beginning;
    std::string destination;
    unsigned long int payment;
    int date;
public:
    transaction(std::string, std::string, unsigned long int);
    ~transaction();
};

