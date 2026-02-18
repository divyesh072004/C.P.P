#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
public:
    string accountHolder;
    string password;
    double balance;
    vector<string> transactionHistory;

    Account(string holder, string pass) {
        accountHolder = holder;
        password = pass;
        balance = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
        transactionHistory.push_back("Deposited: $" + to_string(amount));
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            transactionHistory.push_back("Withdrew: $" + to_string(amount));
            return true;
        } else {
            cout << "Insufficient funds!" << endl;
            return false;
        }
    }

    double getBalance() {
        return balance;
    }

    void displayTransactionHistory() {
        cout << "Transaction History for " << accountHolder << ":\n";
        for (const string &record : transactionHistory) {
            cout << record << endl;
        }
    }
};

class ATM {
private:
    vector<Account> accounts;
    Account* currentAccount;

public:
    ATM() : currentAccount(nullptr) { }

    void createAccount(string holder, string pass) {
        accounts.emplace_back(holder, pass);
        cout << "Account created for " << holder << endl;
    }

    bool login(string holder, string pass) {
        for (auto &account : accounts) {
            if (account.accountHolder == holder && account.password == pass) {
                currentAccount = &account;
                return true;
            }
        }
        return false;
    }

    void deposit() {
        if (currentAccount) {
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            currentAccount->deposit(amount);
            cout << "Deposit successful!" << endl;
        }
    }

    void withdraw() {
        if (currentAccount) {
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            if (currentAccount->withdraw(amount)) {
                cout << "Withdrawal successful!" << endl;
            }
        }
    }

    void checkBalance() {
        if (currentAccount) {
            cout << "Current balance: $" << currentAccount->getBalance() << endl;
        }
    }

    void viewTransactionHistory() {
        if (currentAccount) {
            currentAccount->displayTransactionHistory();
        }
    }
};

int main() {
    ATM atm;
    int choice;

    while (true) {
        cout << "1. Create Account\n2. Login\n3. Deposit\n4. Withdraw\n5. Check Balance\n6. View Transaction History\n7. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string holder, pass;
                cout << "Enter account holder name: ";
                cin >> holder;
                cout << "Enter password: ";
                cin >> pass;
                atm.createAccount(holder, pass);
                break;
            }
            case 2: {
                string holder, pass;
                cout << "Enter account holder name: ";
                cin >> holder;
                cout << "Enter password: ";
                cin >> pass;
                if (atm.login(holder, pass)) {
                    cout << "Login successful!" << endl;
                } else {
                    cout << "Login failed!" << endl;
                }
                break;
            }
            case 3:
                atm.deposit();
                break;
            case 4:
                atm.withdraw();
                break;
            case 5:
                atm.checkBalance();
                break;
            case 6:
                atm.viewTransactionHistory();
                break;
            case 7:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
