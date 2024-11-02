/*Name of the Project-Stock Management System
 *Created By-Sagar Singh */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
struct Product {
    char name[50];
    int quantity;
};

// Function to add a new product to the stock
void addProduct(struct Product stock[], int *count) {
    if (*count < 100) {
        printf("Enter product name: ");
        scanf("%s", stock[*count].name);

        printf("Enter quantity: ");
        scanf("%d", &stock[*count].quantity);

        (*count)++;
        printf("Product added successfully!\n");
    } else {
        printf("Stock is full. Cannot add more products.\n");
    }
}

// Function to update the stock of an existing product
void updateStock(struct Product stock[], int count) {
    char searchName[50];
    int found = 0;

    printf("Enter the product name to update stock: ");
    scanf("%s", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(stock[i].name, searchName) == 0) {
            printf("Enter the new quantity: ");
            scanf("%d", &stock[i].quantity);
            found = 1;
            printf("Stock updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product not found in the stock.\n");
    }
}

// Function to display the current stock
void displayStock(struct Product stock[], int count) {
    printf("\nCurrent Stock:\n");
    printf("%-20s %-10s\n", "Product Name", "Quantity");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d\n", stock[i].name, stock[i].quantity);
    }
    printf("\n");
}

int main() {
    struct Product stock[100];
    int count = 0;
    int choice;

    do {
        printf("Stock Management System\n");
        printf("1. Add Product\n");
        printf("2. Update Stock\n");
        printf("3. Display Stock\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(stock, &count);
                break;
            case 2:
                updateStock(stock, count);
                break;
            case 3:
                displayStock(stock, count);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
