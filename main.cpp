#include <iostream>
#include <iomanip>
#include "Bank.h"
#include "Account.h"
#include "Depositer.h"
#include "Name.h"

using namespace std;

void menu();
void read_accts(Bank&);
void balance(Bank&);
void deposit(Bank&);
void withdrawal(Bank&);
void new_acct(Bank&);
void delete_acct(Bank&);
void account_info(Bank&);

int main()
{
    Bank bank;
    // ONE bank object,
    // Within it is room for 50 Accounts
    // Each Account has a number, balance, type and Depositer
    // Each Depositer has a Name and ssn
    // Each Name has a 'first' and 'last' field

    read_accts(bank); // reads in initial accounts info from user
    cout << "INITIAL DATABASE:\n";
    bank.print_accounts(); // call the 'print_account' function for this object (called 'bank')

    char c;

    do {
        menu();
        cin >> c;
        switch(c)
        {
            case 'q':
            case 'Q':
                cout << "\nFINAL DATABASE:\n";
                bank.print_accounts();
                return 0;
            case 'b':
            case 'B':
                balance(bank);
                break;
            case 'd':
            case 'D':
                deposit(bank);
                break;
            case 'w':
            case 'W':
                withdrawal(bank);
                break;
            case 'n':
            case 'N':
                new_acct(bank);
                break;
            case 'x':
            case 'X':
                delete_acct(bank);
                break;
            case 'i':
            case 'I':
                account_info(bank);
                break;
            default:
                cout << endl << "Error: '" << c << "' is an invalid selection" << endl << endl;
                break;
        }
    } while (true);

    return 0;
}

void menu()
{
    cout << "Select one:" << endl;
    cout << "\t****************************" << endl;
    cout << "\t       Choices         " << endl;
    cout << "\t****************************" << endl;
    cout << "\t     W  : Withdrawal" << endl;
    cout << "\t     D  : Deposit" << endl;
    cout << "\t     N  : New Account" << endl;
    cout << "\t     B  : Balance Inquiry" << endl;
    cout << "\t     X  : Delete Account" << endl;
    cout << "\t     I  : Account Info"  << endl;
    cout << "\t     Q  : Quit" << endl;
    cout << "\n\tEnter your selection: ";
}

void read_accts(Bank& bank)
{
    int active_accts;
    cout << "How many accounts would you like to start with? ";
    cin >> active_accts;
    cout << "\n";

    string first, last, acct_type;
    double ssn, acct_balance;
    int acct_number;

    for(int i = 0; i < active_accts; i++)
    {
        cout << "Information needed for account " << i + 1 << "\n";
        cout << "----------------------------------\n";
        cout << "Enter first and last name: ";
        cin >> first >> last;
        Name name(first, last); // make Name object called 'name'

        cout << "Enter social security #: ";
        cin >> ssn;
        Depositer d(name, ssn); // make Depositer object called 'd'

        cout << "Enter account type (checkings or savings): ";
        cin >> acct_type;
        cout << "Enter account #: ";
        cin >> acct_number;
        cout << "Enter initial balance in account #" << acct_number << ": $";
        cin >> acct_balance;
        Account a(d, acct_number, acct_type, acct_balance); // Account object 'a'

        bank.create_account(a); // call 'create_account' function for 'bank'

        cout << "\n";

    }
}

void balance(Bank& bank)
{
    int acct;
    int index;

    cout << "Enter the account number: ";
    cin >> acct;

    index = bank.find_acct(acct);
    if(index == -1)
        cout << "Error: Account number " << acct << " does not exist" << endl;
    else
    {
        cout << "Account #: " << acct << endl;
        cout << "Current Balance: $" << setprecision(2) << bank.getAccount(index).getBalance() << endl;
    }
}

void deposit(Bank& bank)
{
    int acct;
    int index;
    double deposit;

    cout << "Enter the account number: ";
    cin >> acct;

    index = bank.find_acct(acct);
    if (index == -1)
    	cout << "Error: Account number " << acct << " does not exist" << endl;
    else                                                    //valid account
    {
        cout << "Enter amount to deposit: $";                //prompt for amount to deposit
        cin >> deposit;

        if (deposit <= 0)                      //invalid amount to deposit
            cout << "Error: $" << setprecision(2) << deposit << " is an invalid amount" << endl;
        else
        {
            // Get the proper index of Account (0-49), and add to the balance of that Account
            bank.getAccount(index).add_to_balance(deposit);
            cout << "Transaction complete: added $" << setprecision(2) << deposit << " to account #" << acct << endl;
        }
    }

}

void withdrawal(Bank& bank)
{
    int acct;
    int index;
    double withdrawal;

    cout << "Enter the account number: ";
    cin >> acct;

    index = bank.find_acct(acct);
    if (index == -1)
        cout<<"Error: Account #" << acct << " does not exist"<< endl;
    else
    {
        cout << "Enter amount to withdraw: $";
        cin >> withdrawal;

        if (withdrawal <= 0)
            cout<<"Error: $" << setprecision(2) << withdrawal << " is an invalid withdrawal amount"<<endl;

        else if(withdrawal > bank.getAccount(index).getBalance() )
            cout << "Error: Insufficient Funds!" << endl;

        else
        {
            bank.getAccount(index).subtract_from_balance(withdrawal);
            cout << "Transaction complete: withdrew $" << withdrawal << " from account #" << acct << endl;
        }
    }
}

void new_acct(Bank& bank)
{
    string first, last, acct_type;
    double ssn, acct_balance;
    int acct_number;
    int index;

    cout << "Enter the account number: ";           //prompt for account number
    cin >> acct_number;

    index = bank.find_acct(acct_number);
    if (index == -1)                                        //invalid account
    {
        cout << "Enter first and last name: ";
        cin >> first >> last;
        Name name(first, last);

        cout << "Enter social security #: ";
        cin >> ssn;
        Depositer d(name, ssn);

        cout << "Enter account type (checkings or savings): ";
        cin >> acct_type;
        cout << "Enter initial balance in account #" << acct_number << ": $";
        cin >> acct_balance;
        Account a(d, acct_number, acct_type, acct_balance);

        bank.create_account(a);
    }

    else cout << "ERROR: Account already exists!" << endl;
}

void delete_acct(Bank& bank)
{
    int acct;
    int index;

    cout << "Enter the account number: ";
    cin >> acct;

    index = bank.find_acct(acct);
    if (index == -1)                                        //invalid account
        cout << "Error: Account #" << acct << " does not exist" << endl;

    else if (index != -1 && bank.getAccount(index).getBalance() > 0)
    	cout << "Error! Cannot delete account with a balance" << endl;

    else if (index != -1 && bank.getAccount(index).getBalance() == 0)
    {
        bank.delete_account(index);
        cout << "Account #" << acct << " deleted" << endl;
    }
}

void account_info(Bank& bank)
{
    int ssn;
    cout << "Enter the accounts social security number: ";
    cin >> ssn;

    int index = bank.find_acct_ssn(ssn);
    if(index == -1)
        cout << "Error: Account with ssn #" << ssn << " not found" << endl;
    else
    {
        cout << "\nACCOUNT INQUIRY:\n";
        bank.print_account(index);
    }
}





