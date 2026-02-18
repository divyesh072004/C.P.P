#include <stdio.h>

// Function prototypes
void displayMenu();
void deposit();
void withdraw();
void checkBalance();

float balance = 0.0;

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                deposit();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                checkBalance();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}

void displayMenu() {
    printf("\n*** Banking System Menu ***\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Exit\n");
}

void deposit() {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    balance += amount;
    printf("Deposited: $%.2f\n", amount);
}

void withdraw() {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > balance) {
        printf("Insufficient balance!\n");
    } else {
        balance -= amount;
        printf("Withdrew: $%.2f\n", amount);
    }
}

void checkBalance() {
    printf("Current balance: $%.2f\n", balance);
}