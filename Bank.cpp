#include <iostream>
#include <map>
#include <fstream>
#include "Account.cpp"
using namespace std;
class Bank
{
private:
    map<long, Account> accounts;

public:
    Bank();
    Account OpenAccount(string fn, string ln, string cn, string add, float balance);
    Account BalanceEnquiry(long accountNumber);
    Account Deposit(long accountNumber, float amount);
    Account Withdraw(long accountNumber, float amount);
    void CloseAccount(long accountNumber);
    void ShowAllAccounts();
    ~Bank();
};
int main()
{
    Bank bank;
    Account acc;
    string fname, lname, contact, add;
    long accountNumber;
    float balance, amount;
    int choise;
    cout << "****Banking System*****" << endl;
    do
    {
        cout << "\n\tSelect one option from below";
        cout << "\n\t1. Open New Account";
        cout << "\n\t2. Balance Enquiry";
        cout << "\n\t3. Deposit Balance";
        cout << "\n\t4. Withdraw Balance";
        cout << "\n\t5. Close Account";
        cout << "\n\t6. Show All Accounts";
        cout << "\n\t7. Quit";
        cout << "\n\nEnter your choise : ";
        cin >> choise;
        cout << endl;
        switch (choise)
        {
        case 1:
            cout << "Enter Your First Name : ";
            cin >> fname;
            cout << "Enter Your Last Name : ";
            cin >> lname;
            cout << "Enter Your Contact Number : ";
            cin >> contact;
            cout << "Enter Your Address : ";
            cin >> add;
            cout << "Enter Initial Balance : ";
            cin >> balance;
            acc = bank.OpenAccount(fname, lname, contact, add, balance);
            cout << endl
                 << "Congrats Your Account is Succesfully Created" << endl;
            cout << acc;
            break;
        case 2:
            cout << "Enter Account Number:";
            cin >> accountNumber;
            acc = bank.BalanceEnquiry(accountNumber);
            cout << endl
                 << "Your Account Details" << endl;
            cout << acc;
            break;
        case 3:
            cout << "Enter Account Number:";
            cin >> accountNumber;
            cout << "Enter Balance:";
            cin >> amount;
            acc = bank.Deposit(accountNumber, amount);
            cout << endl
                 << "Amount is Deposited" << endl;
            cout << acc;
            break;
        case 4:
            cout << "Enter Account Number:";
            cin >> accountNumber;
            cout << "Enter Balance:";
            cin >> amount;
            acc = bank.Withdraw(accountNumber, amount);
            cout << endl
                 << "Amount Withdrawn" << endl;
            cout << acc;
            break;
        case 5:
            cout << "Enter Account Number:";
            cin >> accountNumber;
            bank.CloseAccount(accountNumber);
            cout << endl
                 << "Account is Closed" << endl;
            cout << acc;
        case 6:
            bank.ShowAllAccounts();
            break;
        case 7:
            break;

        default:
            cout << "\nWrong Option! PLEASE TRY AGAIN" << endl;
        }
    } while (choise != 7);
    return 0;
}

Bank::Bank()
{
    Account account;
    ifstream ipfile;

    ipfile.open("Bank.data");
    if (!ipfile)
    {
        cout << "Error in Opening! File Not Found!!" << endl;
        return;
    }
    while (!ipfile.eof())
    {
        ipfile >> account;
        accounts.insert(pair<long, Account>(account.getAccountNumber(), account));
    }
    Account::setLastAccountNumber(account.getAccountNumber());
    ipfile.close();
}
Account Bank::OpenAccount(string fn, string ln, string cn, string add, float balance)
{
    ofstream opfile;
    Account account(fn, ln, cn, add, balance);
    accounts.insert(pair<long, Account>(account.getAccountNumber(), account));
    opfile.open("Bank.data", ios::trunc);
    map<long, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        opfile << itr->second;
    }
    opfile.close();
    return account;
}
Account Bank::BalanceEnquiry(long accountNumber)
{
    map<long, Account>::iterator itr = accounts.find(accountNumber);
    return itr->second;
}
Account Bank::Deposit(long accountNumber, float amount)
{
    map<long, Account>::iterator itr = accounts.find(accountNumber);
    itr->second.Deposit(amount);
    return itr->second;
}
Account Bank::Withdraw(long accountNumber, float amount)
{
    map<long, Account>::iterator itr = accounts.find(accountNumber);
    itr->second.Withdraw(amount);
    return itr->second;
}
void Bank::CloseAccount(long accountNumber)
{
    map<long, Account>::iterator itr = accounts.find(accountNumber);
    cout << "Account Deleted" << itr->second;
    accounts.erase(accountNumber);
}
void Bank::ShowAllAccounts()
{
    map<long, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        cout << "Account " << itr->first << endl
             << itr->second << endl;
    }
}
Bank::~Bank()
{
    ofstream opfile;
    opfile.open("Bank.data", ios::trunc);
    map<long, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        opfile << itr->second;
    }
    opfile.close();
}
