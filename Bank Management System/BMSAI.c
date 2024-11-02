#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a bank account
struct account {
    int accNo;
    char name[50];
    float balance;
    struct account *next;
};

// Global pointer to the head of the linked list
struct account *head = NULL;

// Function to add a new account
void addAccount(int accNo, char name[], float balance) {
    struct account *newAccount = (struct account *)malloc(sizeof(struct account));
    if (newAccount == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newAccount->accNo = accNo;
    strcpy(newAccount->name, name);
    newAccount->balance = balance;
    newAccount->next = NULL;

    if (head == NULL) {
        head = newAccount;
    } else {
        struct account *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newAccount;
    }
    printf("Account added successfully\n");
}

// Function to deposit money into an account
void deposit(int accNo, float amount) {
    struct account *temp = head;
    while (temp != NULL) {
        if (temp->accNo == accNo) {
            temp->balance += amount;
            printf("Amount deposited successfully\n");
            return;
        }
        temp = temp->next;
    }
    printf("Account not found\n");
}

// Function to withdraw money from an account
void withdraw(int accNo, float amount) {
    struct account *temp = head;
    while (temp != NULL) {
        if (temp->accNo == accNo) {
            if (temp->balance >= amount) {
                temp->balance -= amount;
                printf("Amount withdrawn successfully\n");
            } else {
                printf("Insufficient balance\n");
            }
            return;
        }
        temp = temp->next;
    }
    printf("Account not found\n");
}

// Function to display account details
void display(int accNo) {
    struct account *temp = head;
    while (temp != NULL) {
        if (temp->accNo == accNo) {
            printf("Account Number: %d\n", temp->accNo);
            printf("Name: %s\n", temp->name);
            printf("Balance: %.2f\n", temp->balance);
            return;
        }
        temp = temp->next;
    }
    printf("Account not found\n");
}

// Function to delete an account
void deleteAccount(int accNo) {
    struct account *temp = head;
    struct account *prev = NULL;

    while (temp != NULL) {
        if (temp->accNo == accNo) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Account deleted successfully\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Account not found\n");
}

int main() {
    int choice;
    do {
        printf("\nBank Management System Menu\n");
        printf("1. Add Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account Details\n");
        printf("5. Delete Account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int accNo;
                char name[50];
                float balance;
                printf("Enter Account Number: ");
                scanf("%d", &accNo);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Initial Balance: ");
                scanf("%f", &balance);
                addAccount(accNo, name, balance);
                break;
            }
            case 2: {
                int accNo;
                float amount;
                printf("Enter Account Number: ");
                scanf("%d", &accNo);
                printf("Enter Amount to Deposit: ");
                scanf("%f", &amount);
                deposit(accNo, amount);
                break;
            }
            case 3: {
                int accNo;
                float amount;
                printf("Enter Account Number: ");
                scanf("%d", &accNo);
                printf("Enter Amount to Withdraw: ");
                scanf("%f", &amount);
                withdraw(accNo, amount);
                break;
            }
            case 4: {
                int accNo;
                printf("Enter Account Number: ");
                scanf("%d", &accNo);
                display(accNo);
                break;
            }
            case 5: {
                int accNo;
                printf("Enter Account Number to Delete: ");
                scanf("%d", &accNo);
                deleteAccount(accNo);
                break;
            }
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
