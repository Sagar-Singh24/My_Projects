#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertMedicine();
void displayMedicine();
void searchMedicine();
void updateMedicine();
void deleteMedicine();
float BillMedicine();

struct Medicine
{
    char name[50];
    char name_;
    int quantity;
    char manufacturing_date[20];
    char expiry_date[20];
    float price;
};

//*************************************************************************************************************
// Menu in Medicine System
struct Medicine item[20];
int count = 0, i = 0;
int main()
{
    int choice, n = 1;

    while (n)
    {
        printf("\n");
        printf("\t\t\t\t|   MEDICAL STORE SYSTEM   |\n");
        printf("\nMenu:\n");
        printf("1. Insert Medicine\n");
        printf("2. Display All Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Bill Medicine\n");
        printf("0. Exit\n");

        printf("\n\n\n\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            count++;
            insertMedicine();
            break;
        case 2:
            displayMedicine();
            break;
        case 3:
            searchMedicine();
            break;
        case 4:
            updateMedicine();
            break;
        case 5:
            deleteMedicine();
            break;
        case 6:
            BillMedicine();
            break;
        case 0:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}

//*********************************************************************************************************************
// Inserting Medicine in Input
void insertMedicine()
{
    if (i < 100)
    {
        printf("The name of the medicine: ");
        scanf("%s", item[i].name);
        printf("The quantity: ");
        scanf("%d", &item[i].quantity);
        printf("The price: ");
        scanf("%f", &item[i].price);
        printf("Enter manufacturing date (MM/YYYY): ");
        scanf("%s", item[i].manufacturing_date);
        printf("Enter expiry date (MM/YYYY): ");
        scanf("%s", item[i].expiry_date);

        i++;
        printf("Medicine added successfully!\n");
    }
    else
    {
        printf("item is full \n");
    }
}

//*********************************************************************************************************************
// Displaying Medicine on Screen
void displayMedicine()
{

    if (count > 0)
    {
        printf("\nMedicine item:\n");
        printf("%-10s%-12s%-15s%-19s%-24s\n", "Name", "Quantity", "Price", "Manufacturing", "Expiry");
        for (int i = 0; i < count; i++)
        {
            printf("%-10s  %-12d  %-15f  %-19s  %-24s\n", item[i].name, item[i].quantity, item[i].price,
                   item[i].manufacturing_date, item[i].expiry_date);
        }
    }
    else
    {
        printf("item is empty.\n");
    }
}

//********************************************************************************************************************
// Search for Medicine
void searchMedicine()
{
    int i, check = 0;
    char temp[30];
    printf("Enter the name of Medicine:");
    scanf("%s", &temp);
    for (i = 0; i < count; i++)
    {
        if (strstr(item[i].name, temp))
        {
            check++;
            printf("Medicine found\n");
            printf("%-10s %-12s %-15s %-19s %-24s\n", "Name", "Quantity", "Price", "Manufacturing", "Expiry");
            printf("%-10s  %-12d  %-15f  %-19s  %-24s\n", item[i].name, item[i].quantity, item[i].price,
                   item[i].manufacturing_date, item[i].expiry_date);
            break;
        }
    }
    if (check == 0)
    {
        printf("Medicine Not Found.\n");
    }
}

//********************************************************************************************************************
// Update Medicine item
void updateMedicine()
{
    int j, check = 0;
    char temp[30];
    printf("Enter Medicine Name is to be updated:");
    scanf("%s", &temp);
    for (j = 0; j < count; j++)
    {
        if (strstr(item[j].name, temp))
        {
            check++;
            // Display the details of the medicine to update
            printf("Medicine details that need to be updated :\n");
            printf("%-10s %-12s %-15s %-19s %-24s\n", "Name", "Quantity", "Price", "Manufacturing", "Expiry");
            printf("%-10s  %-12d  %-15f  %-19s  %-24s\n", item[j].name, item[j].quantity, item[j].price,
                   item[j].manufacturing_date, item[j].expiry_date);

            // Prompt the user to update data
            printf("Enter new details for the medicine:\n");

            printf("Name: ");
            scanf("%s", item[j].name);

            printf("Quantity: ");
            scanf("%d", &item[j].quantity);

            printf("Price: ");
            scanf("%f", &item[j].price);

            printf("Manufacturing Date: ");
            scanf("%s", item[j].manufacturing_date);

            printf("Expiry Date: ");
            scanf("%s", item[j].expiry_date);

            printf("\n \nMedicine details have been updated successfully.\n");

            break;
        }
    }

    if (check == 0)
    {
        printf("Medicine name Not Found!\n");
    }
}

//***************************************************************************************************************
// Delete Medicine item
void deleteMedicine()
{
    int j, m, check = 0;
    char name;
    char temp[30];
    printf("Enter Medicine Name is to be Deleted: ");
    scanf("%s", &temp);
    for (j = 0; j < count; j++)
    {
        if (strstr(item[j].name, temp))
        {
            check++;
            for (m = j + 1; m <= count; m++)
            {
                item[j] = item[m];
                j++;
            }
            count--;
            break;
        }
    }
    if (check == 0)
    {
        printf("Medicine Name Not Found!\n");
    }
    if (count == 0)
    {
        printf("No Medicine Found! Please Enter Medicine First.\n");
    }
    else if (count > 0)
    {
        printf("New Records:--\n");
        printf("%-10s %-12s %-15s %-19s %-24s\n", "Name", "Quantity", "Price", "Manufacturing", "Expiry");
        for (j = 1; j <= count; j++)
        {
            printf("%-10s  %-12d  %-15f  %-19s  %-24s\n", item[j - 1].name, item[j - 1].quantity, item[j - 1].price,
                   item[j - 1].manufacturing_date, item[j - 1].expiry_date);
        }
        printf("\nTotal number of records=%d\n", count);
    }
}

//*************************************************************************************************************************
// For making Medicine Bill
float BillMedicine()
{
    float Bill = 0.0;

    for (int i = 0; i < count; i++)
    {
        Bill += item[i].price * item[i].quantity;
    }

    // Display the bill
    printf("\nMedicine item:\n");
    printf("%-10s%-12s%-15s%-19s%-24s\n", "Name", "Quantity", "Price", "Manufacturing", "Expiry");
    for (int i = 0; i < count; i++)
    {
        printf("%-10s  %-12d  %-15f  %-19s  %-24s\n", item[i].name, item[i].quantity, item[i].price,
               item[i].manufacturing_date, item[i].expiry_date);
    }

    // Calculate and display the Bill
    printf("\n\nTotal Bill for Medicine: %.2f\n", Bill);

    return 0;
}
