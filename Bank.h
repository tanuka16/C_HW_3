#include "Account.h"

#ifndef BANK_H
#define BANK_H


class Bank
{
    private:
        const int MAX_ACCTS = 50; // max capacity of array

        Account acct_arr[50];
        int num_accts; // number of active account in the array

    public:
        Bank();

        void create_account(Account);
        void print_accounts();
        void print_account(int);
        int getNum_accts();
        int find_acct(int);
        int find_acct_ssn(double);
        Account& getAccount(int);
        void delete_account(int);

};

#endif // BANK_H
