#include <string>
#include "Depositer.h"

using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account
{
    private:
        Depositer dep;
        int acct_num;
        string type;
        double balance;

    public:
        Account();
        Account(Depositer, int, string, double);

        Depositer getDepositer();
        int getAccountNumber();
        string getAccountType();
        double getBalance();
        void add_to_balance(double);
        void subtract_from_balance(double);

};

#endif // ACCOUNT_H
