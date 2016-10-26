
#include <iostream>
#include "Account.h"

using namespace std;

Account::Account()
{
    dep = Depositer();
    acct_num = 0;
    balance = 0;
    type = "";
}

Account::Account(Depositer d, int acct_n, string t, double b)
{
    dep = d;
    acct_num = acct_n;
    type = t;
    balance = b;
}

Depositer Account::getDepositer() { return dep; }
int Account::getAccountNumber() { return acct_num; }
string Account::getAccountType() { return type; }
double Account::getBalance() { return balance; }

void Account::add_to_balance(double b) { balance += b; }
void Account::subtract_from_balance(double w) { balance -= w; }


