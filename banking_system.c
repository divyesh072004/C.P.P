#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int account_number;
    char name[100];
    float balance;
    char transaction_history[1000];
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Maximum accounts reached.\n");
        return;
    }
    Account new_account;
    new_account.account_number = account_count + 1; // Simple account number assignment
    printf("Enter account holder's name: ");
    scanf("%s", new_account.name);
    new_account.balance = 0.0;
    strcpy(new_account.transaction_history, "");
    accounts[account_count] = new_account;
    account_count++;
    printf("Account created successfully. Account Number: %d\n", new_account.account_number);
}

void deposit() {
    int acc_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &acc_number);
    if (acc_number > account_count || acc_number <= 0) {
        printf("Invalid account number.\n");
        return;
    }
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    accounts[acc_number - 1].balance += amount;
    strcat(accounts[acc_number - 1].transaction_history, "Deposited: ");
    char amount_str[50];
    sprintf(amount_str, "%.2f; ", amount);
    strcat(accounts[acc_number - 1].transaction_history, amount_str);
    printf("Deposited %.2f to account number %d.\n", amount, acc_number);
}

void withdraw() {
    int acc_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &acc_number);
    if (acc_number > account_count || acc_number <= 0) {
        printf("Invalid account number.\n");
        return;
    }
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (accounts[acc_number - 1].balance < amount) {
        printf("Insufficient funds.\n");
        return;
    }
    accounts[acc_number - 1].balance -= amount;
    strcat(accounts[acc_number - 1].transaction_history, "Withdrew: ");
    char amount_str[50];
    sprintf(amount_str, "%.2f; ", amount);
    strcat(accounts[acc_number - 1].transaction_history, amount_str);
    printf("Withdrew %.2f from account number %d.\n", amount, acc_number);
}

void balance_inquiry() {
    int acc_number;
    printf("Enter account number: ");
    scanf("%d", &acc_number);
    if (acc_number > account_count || acc_number <= 0) {
        printf("Invalid account number.\n");
        return;
    }
    printf("Balance for account number %d is %.2f\n", acc_number, accounts[acc_number - 1].balance);
}

void transaction_history() {
    int acc_number;
    printf("Enter account number: ");
    scanf("%d", &acc_number);
    if (acc_number > account_count || acc_number <= 0) {
        printf("Invalid account number.\n");
        return;
    }
    printf("Transaction history for account number %d:\n%s\n", acc_number, accounts[acc_number - 1].transaction_history);
}

int main() {
    int choice;
    do {
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Balance Inquiry\n");
        printf("5. Transaction History\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create_account(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: balance_inquiry(); break;
            case 5: transaction_history(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);
    return 0;
}