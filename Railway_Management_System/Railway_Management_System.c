/*Name of the Project-Railway Management System
 *Created By-Sagar Singh */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addtrain();
void availabletrain();
void search();
void bookticket();
void cancelticket();
void detail();

struct train_resevation
{
    char train_name[30];
    int train_no;
    char timing[10];
};

struct passenger
{
    char name[50];
    int age;
    char gen[5];
    int seat_no;
};
//*************************************************************************************************************
//Menu for Passenger
struct train_resevation train[50];
struct passenger pas[50];
int count,flag=0;
int main()
{
    int n;
    printf("***********\n");
    printf("* 1.ADMIN *\n");
    printf("* 2.USER  *\n");
    printf("***********\n\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &n);
    if (n == 1)
        addtrain();
    else
    {
        do
        {
            printf("\n\n*****************RAILWAY RESERVATION SYSTEM**************************\n\n");
            printf("1.CHECK AVAILABLE TRAIN\n");
            printf("2.SEARCH TRAIN\n");
            printf("3.BOOK TICKET\n");
            printf("4.CANCEL TICKET\n");
            printf("5.PASSENGER DETAILS\n");
            printf("6.EXIT\n");
            printf("\n\n***********************************************************************\n\n");
            int choice;
            printf("ENTER YOUR CHOICE\n");
            scanf("%d", &choice);
            getchar();
            switch (choice)
            {
            case 1:
                availabletrain();
                break;
            case 2:
                search();
                break;
            case 3:
                bookticket();
                break;
            case 4:
                cancelticket();
                break;
            case 5:
                detail();
                break;
            case 6:
                exit(0);
            default:
                printf("INVALID INPUT\n");
            }

        } while (1);
    }
}
//*******************************************************************************************************
void addtrain()
{
    printf("PLEASE ADD TRAIN DETAILS\n");
    printf("HOW MANY TRAINS YOU WANT TO ENTER: ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        printf("\nENTER DETAILS OF TRAIN %d.\n ", i + 1);
        printf("ENTER TRAIN NAME: ");
        scanf("%s", train[i].train_name);
        printf("ENTER TRAIN NUMBER: ");
        scanf("%d", &train[i].train_no);
        printf("ENTER TRAIN TIMING(HH:MM): ");
        scanf("%s", train[i].timing);
    }
    main();
}
//***************************************************************************************************
void availabletrain()
{
    printf("%-15s%-10s%-6s\n", "TRAIN NAME", "TRAIN NO", "TRAIN TIMING");
    for (int i = 0; i < count; i++)
    {
        printf("%-15s%-10d%-6s\n", train[i].train_name, train[i].train_no, train[i].timing);
    }
}
//****************************************************************************************************
void search()
{
    char temp[20];
    printf("ENTER TRAIN NAME TO SEARCH: ");
    scanf("%s", temp);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(train[i].train_name, temp) == 0)
        {
            printf("TRAIN NAME: %s\n", temp);
            printf("TRAIN NO: %d\n", train[i].train_no);
            printf("TRAIN TIMING: %s\n", train[i].timing);
            break;
        }
        printf("TRAIN NOT FOUND\n");
    }
}
//******************************************************************************************************
void bookticket()
{
    char temp[20];
    printf("ENTER TRAIN NAME TO BOOK TICKET: ");
    scanf("%s", temp);
    for (int i = 0; i < count; i++)
    {
        if (strstr(train[i].train_name, temp))
        {
            int choice;
            printf("1.AC TIER\n");
            printf("2.SLEEPER\n");
            printf("3.GENERAL\n");
            printf("ENTER YOUR CHOICE: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\nADD DETAILS OF PASSENGER\n");
                printf("ENTER PASSENGER NAME: ");
                scanf("%s", pas[flag].name);
                printf("ENTER AGE: ");
                scanf("%d", &pas[flag].age);
                printf("ENTER GENDER(M/F): ");
                scanf("%s",pas[flag].gen);
                pas[flag].seat_no=flag+1;
                printf("YOUR TICKET NO.:%d\n",pas[flag].seat_no);
                flag++;
                printf("TOTAL BILL: Rs2000\n");
                printf("YOUR TICKET HAS BEEN BOOKED SUCESSFULLY;\n");
                break;
            case 2:
                printf("ENTER PASSENGER NAME: ");
                scanf("%s", pas[flag].name);
                printf("ENTER AGE: ");
                scanf("%d", &pas[flag].age);
                printf("ENTER GENDER(M/F): ");
                scanf("%s",pas[flag].gen);
                pas[flag].seat_no=flag+1;
                printf("YOUR TICKET NO.:%d\n",pas[flag].seat_no);
                flag++;
                printf("TOTAL BILL: Rs800\n");
                printf("YOUR TICKET HAS BEEN BOOKED SUCESSFULLY;\n");
                break;
            case 3:
                printf("\nADD DETAILS OF PASSENGER\n");
                printf("ENTER PASSENGER NAME: ");
                scanf("%s", pas[flag].name);
                printf("ENTER AGE: ");
                scanf("%d", &pas[flag].age);
                printf("ENTER GENDER(M/F): ");
                scanf("%s",pas[flag].gen);
                pas[flag].seat_no=flag+1;
                printf("YOUR TICKET NO.:%d\n",pas[flag].seat_no);
                flag++;
                printf("TOTAL BILL: Rs350\n");
                printf("YOUR TICKET HAS BEEN BOOKED SUCESSFULLY;\n");
                break;
            default:
                printf("INVALID INPUT");
            }
        }
    }
}
//******************************************************************************************************
void cancelticket()
{
    int i, j, check = 0;
    int temp;
    printf("ENTER SEAT NUMBER TO CANCLE YOUR TICKET: ");
    scanf("%d", &temp);
    for (int i = 0; i < flag; i++)
    {
        if (pas[i].seat_no == temp)
        {
            for (int j = i; j < flag-1; j++)
            {
                pas[j] = pas[j+1];
                i++;
            }
            flag--;
            break;
        }
    }
    if (flag == 0)
    {
        printf("No Seat Number Found! Please Enter Seat Number First.\n");
    }
    else if (flag > 0)
    {
        printf("New Record:\n");
        printf("%-10s%-10s%-10s%-10s\n", "NAME", "AGE", "GENDER", "SEAT NO");
        for (int i = 0; i < flag; i++)
        {
            printf("%-10s%-10d%-10s%-10d\n", pas[i].name, pas[i].age, pas[i].gen, pas[i].seat_no);
        }
    }
}
//******************************************************************************************************************************
void detail()

{
    if (flag > 0)
    {
        printf("Passenger Detail:\n");
        printf("%-10s%-10s%-10s%-10s\n", "NAME", "AGE", "GENDER", "SEAT NO");
        for (int i = 0; i < flag; i++)

        {
            printf("%-10s%-10d%-10s%-10d\n", pas[i].name, pas[i].age, pas[i].gen, pas[i].seat_no);
        }
    }
    else{
        printf("Detail is empty.\n");
    }
}
