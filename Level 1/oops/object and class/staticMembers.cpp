#include <iostream>
using namespace std;

class BankAccount {
private:
    static double interestRate; // Static data member

public:
    int accountNumber;
    double balance;

    BankAccount(int accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    // Static member function
    static void setInterestRate(double rate) {
        interestRate = rate;
    }

    // Member function using the static data member
    void applyInterest() {
        balance += balance * interestRate;
    }

    // Static member function to get the interest rate
    static double getInterestRate() {
        return interestRate;
    }
};

// Initialization of static data member
double BankAccount::interestRate = 0.03;

int main() {
    BankAccount account1(1001, 5000.0);
    BankAccount account2(1002, 8000.0);

    cout << "Initial balances:" << endl;
    cout << "Account 1: $" << account1.balance << endl;
    cout << "Account 2: $" << account2.balance << endl;

    // Accessing static data member and using static member function
    BankAccount::setInterestRate(0.05);

    // Applying interest using non-static member function
    account1.applyInterest();
    account2.applyInterest();

    cout << "\nBalances after applying interest:" << endl;
    cout << "Account 1: $" << account1.balance << endl;
    cout << "Account 2: $" << account2.balance << endl;

    // Accessing static member function to get the interest rate
    cout << "\nCurrent Interest Rate: " << BankAccount::getInterestRate() << endl;

    return 0;
}
