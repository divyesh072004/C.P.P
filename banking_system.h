# Banking System Header File

#ifndef BANKING_SYSTEM_H
#define BANKING_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>

// Structure definitions

typedef struct {
    int account_number;
    char account_holder_name[100];
    float balance;
} BankAccount;

typedef struct {
    int transaction_id;
    int account_number;
    float amount;
    char date[20];
} Transaction;

// Function declarations

void create_account(BankAccount *account);
void deposit(BankAccount *account, float amount);
void withdraw(BankAccount *account, float amount);
void display_account_info(BankAccount account);
void record_transaction(Transaction *transaction, BankAccount account, float amount);

#endif // BANKING_SYSTEM_H