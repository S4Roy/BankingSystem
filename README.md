# BankingSystem
Banking Management System by using C++
****
**Account Class**
****
***Data Members***
1. Account Number (auto increment)
2. First Name
3. Last Name
4. Contact Number
5. Address
6. Account Balance

***Methods***

Constructor
1. Account

Accessor
1. getAccountNumber()
2. getFirstName()
3. getLastName()
4. getContactNumber()
5. getAddress()
6. getBalance()
7. getLastAccountNumber() #Static

Facilitator
1. Deposit()
2. Withdraw()
3. setLastAccountNumber() #Static

Operator Overloading function #Friend

1. ofstream
2. ifstream
3. ostream
****
**Bank Class**
****
***Data Members***

1. Map (key->Account Number, value->Account Object)

***Methods***

Constructor
1. Bank

Facilitator
1. OpenAccount()
2. BalanceEnquiry()
3. Deposit()
4. Withdraw()
5. CloseAccount()
6. ShowAllAccounts()

Destructor
1. Bank
****
**ALL DATA SAVING IN A FILE, USING SERIALISATION**

****
**Step 1 : CLONE**
 
    git clone https://github.com/S4Roy/BankingSystem.git

 **Step 2 : COMPILE**

    g++ Bank.cpp -o BankingSystem

 **Step 3 : RUN**

    ./BankingSystem

 **Step 4 : CHOOSE OPTION**

        1. Open New Account
        2. Balance Enquiry
        3. Deposit Balance
        4. Withdraw Balance
        5. Close Account
        6. Show All Accounts
        7. Quit
 **CHOOSE OPTION  #1 FOR OPEN NEW ACCOUNT**

        1. Enter Your First Name 
        2. Enter Your Last Name 
        3. Enter Your Contact Number
        4. Enter Your Address
        5. Enter Initial Deposit Amount


 **CHOOSE OPTION #2 FOR BALANCE ENQUIRY**

        1. Enter Account Number

 **CHOOSE OPTION #3 FOR DEPOSIT AMOUNT**

        1. Enter Account Number
        2. Enter Deposit Amount

 **HOOSE OPTION #4 FOR WIRHDRAW AMOUNT**

        1. Enter Account Number
        2. Enter Deposit Amount


 **CHOOSE OPTION #5 FOR CLOSE ACCOUNT**

        1. Enter Account Number


**CHOOSE OPTION #6 FOR SHOW ALL ACCOUNTS**

**CHOOSE OPTION #7 FOR QUIT**
***


         


