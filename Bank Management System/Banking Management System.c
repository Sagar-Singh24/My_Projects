/*Name of the Project-Bank Management System
 *Created By-Sagar Singh */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct account {
    int acc_no;
    char name[50];
    float balance;
    struct account *next;
} account;

account *head = NULL;
//****************************************************************************************************************************
void create_account() {
    account *new_account, *temp;
    int acc_no;
    char name[50];
    float balance;

    printf("Enter account number: ");
    scanf("%d", &acc_no);

    printf("Enter account holder's name: ");
    scanf("%s", name);

    printf("Enter account balance: ");
    scanf("%f", &balance);

    new_account = (account *)malloc(sizeof(account));
    new_account->acc_no = acc_no;
    strcpy(new_account->name, name);
    new_account->balance = balance;
    new_account->next = NULL;

    if (head == NULL) {
        head = new_account;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_account;
    }
}
//************************************************************************************************************************
void display_accounts() {
    int acc_no;
    account *temp = head;

     printf("Enter account number: ");
    scanf("%d", &acc_no);

    while (temp != NULL) {
          if (temp->acc_no == acc_no) {
        printf("Account number: %d\n", temp->acc_no);
        printf("Account holder's name: %s\n", temp->name);
        printf("Account balance: %.2f\n", temp->balance);
        printf("--------------------\n");
        return;
          }
        temp = temp->next;
    }
    printf("Account not found.\n");
}
//************************************************************************************************************************
void deposit_amount() {
    int acc_no;
    float amount;
    account *temp = head;

    printf("Enter account number: ");
    scanf("%d", &acc_no);

    while (temp != NULL) {
        if (temp->acc_no == acc_no) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            temp->balance += amount;
            printf("Deposit successful. Current balance: %.2f\n", temp->balance);
            return;
        }
        temp = temp->next;
    }

    printf("Account not found.\n");
}
//*****************************************************************************************************************************
void withdraw_amount() {
    int acc_no;
    float amount;
    account *temp = head;

    printf("Enter account number: ");
    scanf("%d", &acc_no);

    while (temp != NULL) {
        if (temp->acc_no == acc_no) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (temp->balance >= amount) {
                temp->balance -= amount;
                printf("Withdrawal successful. Current balance: %.2f\n", temp->balance);
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
        temp = temp->next;
    }

    printf("Account not found.\n");
}
//********************************************************************************************************************************
void search_account() {
    int acc_no;
    account *temp = head;

    printf("Enter account number: ");
    scanf("%d", &acc_no);

    while (temp != NULL) {
        if (temp->acc_no == acc_no) {
            printf("Account found.\n");
            printf("Account holder's name: %s\n", temp->name);
            printf("Account balance: %.2f\n", temp->balance);
            return;
        }
        temp = temp->next;
    }

    printf("Account not found.\n");
}
//*********************************************************************************************************************************
void delete_account() {
    int acc_no;
    account *temp1 = head, *temp2 = NULL;

    printf("Enter account number: ");
    scanf("%d", &acc_no);

    if (temp1 != NULL && temp1->acc_no == acc_no) {
        head = temp1->next;
        free(temp1);
        return;
    }

    while (temp1 != NULL) {
        if (temp1->acc_no == acc_no) {
            temp2->next = temp1->next;
            free(temp1);
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }

    printf("Account not found.\n");
}
//*********************************************************************************************************************************
int main() {
    int choice;

    while (1) {
        printf("\n");
        printf("\t\t\t\t|   BANKING MANAGEMENT SYSTEM   |\n");
        printf("\nMenu:\n");
        printf("1. Create account\n");
        printf("2. Display account detail\n");
        printf("3. Deposit amount\n");
        printf("4. Withdraw amount\n");
        printf("5. Search account\n");
        printf("6. Delete account\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                display_accounts();
                break;
            case 3:
                deposit_amount();
                break;
            case 4:
                withdraw_amount();
                break;
            case 5:
                search_account();
                break;
            case 6:
                delete_account();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
