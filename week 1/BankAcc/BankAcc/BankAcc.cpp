// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

class BankAccount {
protected:
    int accountNumber;         // Unique account number
    string accountHolder;       // Name of the account holder
    double balance;             // Account balance

public:
    // Constructor
    BankAccount(int accNum, string holder, double initialBalance)
        : accountNumber(accNum), accountHolder(holder), balance(initialBalance) {
        cout << "BankAccount created for " << accountHolder << " with initial balance $" << balance << endl;
    }

    // Method to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << ". New balance: $" << balance << endl;
        }
        else {
            cout << "Deposit amount must be positive!" << endl;
        }
    }

    // Method to withdraw money from the account
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds. Withdrawal of $" << amount << " failed." << endl;
        }
        else if (amount <= 0) {
            cout << "Withdrawal amount must be positive!" << endl;
        }
        else {
            balance -= amount;
            cout << "Withdrew: $" << amount << ". New balance: $" << balance << endl;
        }
    }

    // Method to display account information
    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }

    int getAccountNumber()const
    {
        return accountNumber;
    }

    // Virtual destructor
    /*virtual ~BankAccount() {
        cout << "BankAccount for " << accountHolder << " is being closed." << endl;
    }*/
};

// Derived class: SavingsAccount
/*class SavingsAccount : public BankAccount {
private:
    double interestRate; // Interest rate for the savings account

public:
    // Constructor
    SavingsAccount(int accNum, string holder, double initialBalance, double rate)
        : BankAccount(accNum, holder, initialBalance), interestRate(rate) {
        cout << "SavingsAccount created for " << accountHolder << " with interest rate " << interestRate << "%" << endl;
    }

    // Method to add interest to the balance
    void addInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest added: $" << interest << ". New balance: $" << balance << endl;
    }

    // Override display method to include interest rate
    void display() const override {
        BankAccount::display(); // Call base class display
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }

    // Destructor
    ~SavingsAccount() override {
        cout << "SavingsAccount for " << accountHolder << " is being closed." << endl;
    }
};*/

class BankBranch
{
private:
    string branchName;
    string branchAddress;
    vector<BankAccount> accounts;

public:
    BankBranch(const string name, string address) :
        branchName(name), branchAddress(address) {}

    void addAccount(int accountNum, const string& accountName, double balance)
    {
        BankAccount newAcc(accountNum, accountName, balance);
        accounts.push_back(newAcc);
        cout << "Account created for " << accountName << " with account number: " << accountNum;
    }

    //Find an account number 
    BankAccount* findAccount(int accountNum)
    {
        for (auto& account : accounts)
        {
            if (account.getAccountNumber() == accountNum)
            {
                return &account;
            }
        }
        cout << "Account number: " << accountNum << endl;
        return nullptr;
    }

    //Display all accounts
    void displayAllAccs() const
    {
        cout << "All bank accounts: " << endl;
        for (const auto& account : accounts)
        {
            account.display();
        }
    }

    string getBranch()const
    {
        return branchName;
    }
};

class BankSystem
{
private:
    vector<BankBranch> branches;

    vector<vector<BankAccount>> allBankAcc;

public:

    void addBranches(int num) {
        allBankAcc.resize(num);
    }

    void addAccToBranch(int index, BankAccount obj) {

        if (index >= 0 || index < allBankAcc.size()) {
            allBankAcc[index].push_back(obj);
        }
        else {
            cout << "Bank Branch Id is Not present in Bank System" << endl;
        }
    }

    void displayAllAcc() {
        for (int i = 0; i < allBankAcc.size(); i++) {
            for (auto branch : allBankAcc[i]) {
                cout << "Branch Id is : " << i <<endl;
                branch.display();
            }
        }
    }

    void depositeToAcc(int index, int accNo, double amount) {
        if (index < 0 || index >= allBankAcc.size()) {
            cout << "Bank Id is not Found" << endl;
            return;
        }

        for (auto& branch : allBankAcc[index]) {
            if (accNo == branch.getAccountNumber()) {
                branch.deposit(amount);
                break;
            }
        }
    }

    void withdrawAmount(int index, int accNo, double amount) {
        if (index < 0 || index >= allBankAcc.size()) {
            cout << "Bank Id is not Found" << endl;
            return;
        }

        for (auto& branch : allBankAcc[index]) {
            if (accNo == branch.getAccountNumber()) {
                branch.withdraw(amount);
                break;
            }
        }
    }

    //Add new branch to the system
    void addBranch(const string& branchName, const string& branchAddress)
    {
        branches.emplace_back(branchName, branchAddress);
        cout << "Branch created: " << branchName;
    }

    BankBranch* findBranch(const string& name)
    {
        for (auto& branch : branches)
        {
            if (branch.getBranch() == name)
            {
                return &branch;
            }
        }
        cout << "Branch: " << name << endl;
        return nullptr;
    }

    //Display all branches
    void displayAllBranches() const
    {
        cout << "Bank Branches: " << endl;
        for (const auto& branch : branches)
        {
            cout << "Branch Name: " << branch.getBranch() << endl;
            branch.displayAllAccs();
            cout << endl;
        }
    }
};

int main() {
    BankSystem bank;
    bank.addBranch("HitechCity", "Opposite HitechCity");
    bank.addBranch("Jubilee Hills", "Road No 45");

    BankBranch* branch1 = bank.findBranch("Jubilee Hills");
    if (branch1)
    {
        branch1->addAccount(123456, "ABC", 10000);
        branch1->addAccount(87684364, "User3", 300);
        branch1->addAccount(7647343, "user4", 90000);
    }
    bank.displayAllBranches();
    if (branch1)
    {
        BankAccount* account = branch1->findAccount(123456);
        if (account)
        {
            account->deposit(3000);
            account->display();
            account->withdraw(6000.00);
        }
    }

    cout << endl << endl;


    BankSystem bs;
    bs.addBranches(3);
    bs.addAccToBranch(0, BankAccount(01, "Shreenu", 100));
    bs.addAccToBranch(1, BankAccount(101, "Ali", 1045));
    bs.addAccToBranch(2, BankAccount(201, "Rohit", 4637));
    bs.addAccToBranch(0, BankAccount(2, "Ram", 94725));

    bs.displayAllAcc();
    cout << endl << endl;
    bs.withdrawAmount(2, 201, 4000);
    bs.displayAllAcc();

    return 0;
}