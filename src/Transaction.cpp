#include <iostream>
#include "Transaction.h"
using namespace std;

transaction::transaction(customer begin_acc, customer destin_acc, unsigned int transfer_money)
    : beginning(begin_acc), destination(destin_acc), payment(transfer_money)
{
     
    begin_acc.set_balance(begin_acc.get_balance() - transfer_money);
    destin_acc.set_balance(destin_acc.get_balance() + transfer_money);
    cout << begin_acc.get_balance() << endl;
    cout << destin_acc.get_balance() << endl;
}

transaction::~transaction()
{
}
