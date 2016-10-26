#include <iostream>
#include <iomanip>
#include "Bank.h"

using namespace std;

Bank::Bank()
{
    num_accts = 0;
}

int Bank::getNum_accts() { return num_accts; }

void Bank::create_account(Account account)
{
    acct_arr[num_accts] = account; // fill in index num_accts of acc_arr with 'account'
    num_accts++; // increment num_accts since we just added a new account to the array
}

int Bank::find_acct(int target_acct)
{
    for(int i = 0; i < num_accts; i++)
        if(acct_arr[i].getAccountNumber() == target_acct) return i;

    return -1;
}

int Bank::find_acct_ssn(double ssn)
{
    for(int i = 0; i < num_accts; i++)
        if(acct_arr[i].getDepositer().getSSN() == ssn) return i;

    return -1;
}

void Bank::delete_account(int index)
{
    for(int i = index; i < num_accts - 1; i++)
        acct_arr[i] = acct_arr[i+1];

    num_accts--;
}

// This returns an Account (i.e. a single element of the Account array which holds maximum 50 Accounts)
// We return by reference so the balance in the Account can be modified from main
Account& Bank::getAccount(int index) { return acct_arr[index]; }

void Bank::print_account(int i)
{
    cout << "Name: " << acct_arr[i].getDepositer().getName().getFullName() << endl;
    cout << "SSN: " << fixed << setprecision(0) << acct_arr[i].getDepositer().getSSN() << endl;
    cout << "Account Type: " << acct_arr[i].getAccountType() << endl;
    cout << "Account #: " << acct_arr[i].getAccountNumber() << endl;
    cout << "Balance: $" << setprecision(2) << acct_arr[i].getBalance() << endl;
}
void Bank::print_accounts()
{
    for(int i = 0; i < num_accts; i++)
    {
        cout << "Name: " << acct_arr[i].getDepositer().getName().getFullName() << endl;
        cout << "SSN: " << fixed << setprecision(0) << acct_arr[i].getDepositer().getSSN() << endl;
        cout << "Account Type: " << acct_arr[i].getAccountType() << endl;
        cout << "Account #: " << acct_arr[i].getAccountNumber() << endl;
        cout << "Balance: $" << setprecision(2) << acct_arr[i].getBalance() << endl;

        cout << "\n";
    }
}
