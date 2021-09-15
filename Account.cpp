#include <iostream>
#include<fstream>
using namespace std;
class Account
{
private:
    long accountNumber;
    string firstName;
    string lastName;
    string contactNumber;
    string address;
    float balance;
    static long NextAccountNumber;
    
public:
    Account(){}
    Account(string fn,string ln, string cn, string add, float balance);
    long getAccountNumber(){return accountNumber;}
    string getFirstName(){return firstName;}
    string getLastName(){return lastName;}
    string getContactNumber(){return contactNumber;}
    string getAddress(){return address;}
    float getBalance(){return balance;}

    void Deposit(float amount);
    void Withdraw(float amount);

    static void setLastAccountNumber(long accountNumber);
    static long getLastAccountNumber();

    friend ofstream &operator<<(ofstream &ofs, Account &ac);
    friend ifstream &operator>>(ifstream &ifs, Account &ac);
    friend ostream &operator<<(ostream &os, Account &ac);
};

long Account::NextAccountNumber=100;

Account::Account(string fn,string ln, string cn, string add, float balance)
{
    NextAccountNumber++;
    this->accountNumber = NextAccountNumber;
    this->firstName = fn;
    this->lastName = ln;
    this->contactNumber = cn;
    this->address = add;
    this->balance = balance;
}
void Account::Deposit(float amount){
    this->balance += amount;
}
void Account::Withdraw(float amount){
    this->balance -= amount;
}
void Account::setLastAccountNumber(long accountNumber){
    NextAccountNumber = accountNumber;
}
long Account::getLastAccountNumber(){
    return NextAccountNumber;
}
ofstream &operator<<(ofstream &ofs, Account &ac){
    ofs<<ac.accountNumber<<endl;
    ofs<<ac.firstName<<endl;
    ofs<<ac.lastName<<endl;
    ofs<<ac.contactNumber<<endl;
    ofs<<ac.address<<endl;
    ofs<<ac.balance<<endl;
    return ofs;
}
ifstream &operator>>(ifstream &ifs, Account &ac){
    ifs>>ac.accountNumber;
    ifs>>ac.firstName;
    ifs>>ac.lastName;
    ifs>>ac.contactNumber;
    ifs>>ac.address;
    ifs>>ac.balance;
    return ifs;
}
ostream &operator<<(ostream &os, Account &ac){
    os<<"Account Number : "<<ac.getAccountNumber()<<endl;
    os<<"Full Name : "<<ac.getFirstName()<<" "<<ac.getLastName()<<endl;
    os<<"Contact Number : "<<ac.getContactNumber()<<endl;
    os<<"Address : "<<ac.getAddress()<<endl;
    os<<"Balance : "<<ac.getBalance()<<endl;
    return os;
}
