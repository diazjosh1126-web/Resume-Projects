/*
 * Bank Account System
 * -------------------
 * Features:
 * - Base class: BankAccount
 * - Derived class: CheckingAccount
 * - Deposit, withdraw, display
 *
 * Concepts:
 * - OOP (Encapsulation, Inheritance)
 * - Constructors
 * - Virtual functions
 */

#include <iostream>
using namespace std;

// Base class
class BankAccount {
protected:
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(int accNum, double bal) {
        accountNumber = accNum;
        balance = bal;
    }

    // Deposit money
    void deposit(double amount) {
        balance += amount;
    }

    // Withdraw money
    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds.\n";
        }
    }

    // Display account info
    virtual void display() {
        cout << "Account #: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

// Derived class
class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNum, double bal, double limit)
        : BankAccount(accNum, bal) {
        overdraftLimit = limit;
    }

    // Override withdraw
    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
        } else {
            cout << "Exceeded overdraft limit.\n";
        }
    }

    void display() override {
        BankAccount::display();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};

int main() {
    CheckingAccount acc(12345, 500.0, 200.0);

    acc.display();

    cout << "\nDepositing $200...\n";
    acc.deposit(200);

    cout << "Withdrawing $800...\n";
    acc.withdraw(800);

    acc.display();

    return 0;
}
