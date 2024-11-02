/*Name of the Project-Student Record System
 *Created By-Sagar Singh */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enterdetails();
void displayrecords();
void searchbyfirstname();
void searchbyregno();
void updatedetail();
void deletedetail();
void createdby();

struct student
{
    char name[30];
    long int reg_no;
    float marks;
    char grade;
};
struct student s[20];
int count = 0, i = 0;

int main()
{
    int Option, n = 1;

    while (n)
    {
        printf("\t\t\t\t----------------------------------\n");
        printf("\t\t\t\t|   CV RAMAN GLOBAL UNIVERSITY   |\n");
        printf("\t\t\t\t|     STUDENT RECORD SYSTEM      |\n");
        printf("\t\t\t\t----------------------------------\n\n\n");
        printf("\t\t\t\t1.Enter New Records\n");
        printf("\t\t\t\t2.Display all Records\n");
        printf("\t\t\t\t3.Search By First Name\n");
        printf("\t\t\t\t4.Search By Registration Number\n");
        printf("\t\t\t\t5.Update a Detail\n");
        printf("\t\t\t\t6.Delete a detail\n");
        printf("\t\t\t\t7.Created By\n");
        printf("\t\t\t\t8.Exit\n");
        printf("\t\t\t\tChoose options:[1/2/3/4/5/6/7/8]:");
        scanf("%d", &Option);
        getchar();
        printf("---------------------------------------------------------------------------------\n");

        switch (Option)
        {
        case 1:
            count++;
            enterdetails();
            break;
        case 2:
            displayrecords();
            break;
        case 3:
            searchbyfirstname();
            break;
        case 4:
            searchbyregno();
            break;
        case 5:
            updatedetail();
            break;

        case 6:
            deletedetail();
            break;

        case 7:
            createdby();
            break;
        case 8:
            printf("Exiting...");
            n = 0;
            exit(1);
        default:
            n = 0;
            printf("Hi! Enter a Valid Number.");
            exit(1);
        }
    }

    return 0;
}

void enterdetails()
{
    int score, x;
    char *temp;

    printf("Enter Full Name of the Student:");
    fgets(s[i].name, 30, stdin);
    printf("Enter Registration Number:");
    scanf("%lu", &s[i].reg_no);
    printf("Enter Marks out of 100:");
    scanf("%f", &s[i].marks);
    printf("---------------------------------------------------------------------------------\n");
    score = s[i].marks;
    x = (score / 10);
    switch (x)
    {
    case 10:
        s[i].grade = 'O';
        break;
    case 9:
        s[i].grade = 'O';
        break;
    case 8:
        s[i].grade = 'A';
        break;
    case 7:
        s[i].grade = 'B';
        break;
    case 6:
        s[i].grade = 'C';
        break;
    case 5:
        s[i].grade = 'D';
        break;
    case 4:
        s[i].grade = 'E';
        break;
    case 3:
        s[i].grade = 'F';
        break;
    case 2:
        s[i].grade = 'F';
        break;
    case 1:
        s[i].grade = 'F';
        break;
    }
    temp = (strchr(s[i].name, '\n')); // pointer variable stores the address where char \n is found.
    *temp = '\0';                     // we replace that \n with \0 in the string using *(value at address of temp).
    i++;
}

void displayrecords()
{
    int j;
    if (count == 0)
    {
        printf("No Record Found! Please Enter Record First.\n");
        printf("---------------------------------------------------------------------------------\n");
    }
    else if (count > 0)
    {
        printf("S.No.\tName\t\t\tRegistration Number\tMarks\tGrade\n");
        for (j = 1; j <= count; j++)
        {
            printf("%d\t%s\t\t%lu\t\t%.1f\t%c\n", j, s[j - 1].name, s[j - 1].reg_no, s[j - 1].marks, s[j - 1].grade);
        }
        printf("\nTotal number of records=%d", count);
        printf("\n---------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("Please Store Some Value!");
        printf("---------------------------------------------------------------------------------\n");
    }
}

void searchbyfirstname()
{
    int j, check = 0;
    char temp[30];
    printf("Enter first name of the Student:");
    scanf("%29s", &temp);
    printf("---------------------------------------------------------------------------------\n");
    for (j = 0; j < count; j++)
    {
        if (strstr(s[j].name, temp))
        {
            check++;
            printf("Searched detail is:--\n");
            printf("%s\t\t%lu\t\t%.1f\t%c\n", s[j].name, s[j].reg_no, s[j].marks, s[j].grade);
            printf("---------------------------------------------------------------------------------\n");
            break;
        }
    }
    if (check == 0)
    {
        printf("Name Not Found.\n");
        printf("---------------------------------------------------------------------------------\n");
    }
}

void searchbyregno()
{
    int j, check = 0;
    long int regno;
    printf("Enter registration Number:");
    scanf("%lu", &regno);
    printf("---------------------------------------------------------------------------------\n");
    for (j = 0; j < count; j++)
    {
        if (s[j].reg_no == regno)
        {
            check++;
            printf("Searched detail is:--\n");
            printf("%s\t\t%lu\t\t%.1f\t%c\n", s[j].name, s[j].reg_no, s[j].marks, s[j].grade);
            printf("---------------------------------------------------------------------------------\n");
            break;
        }
    }
    if (check == 0)
    {
        printf("Registration Number Not Found!\n");
        printf("---------------------------------------------------------------------------------\n");
    }
}

void updatedetail()
{
    int j, check = 0,score,x;
    long int regno;
    printf("Enter registration Number whose marks is to be updated:");
    scanf("%lu", &regno);
    for (j = 0; j < count; j++)
    {
        if (s[j].reg_no == regno)
        {
            check++;
            printf("Enter Updated Marks:");
            scanf("%f", &s[j].marks);
            score = s[j].marks;
            x = (score / 10);
            switch (x)
            {
            case 10:
                s[j].grade = 'O';
                break;
            case 9:
                s[j].grade = 'O';
                break;
            case 8:
                s[j].grade = 'A';
                break;
            case 7:
                s[j].grade = 'B';
                break;
            case 6:
                s[j].grade = 'C';
                break;
            case 5:
                s[j].grade = 'D';
                break;
            case 4:
                s[j].grade = 'E';
                break;
            case 3:
                s[j].grade = 'F';
                break;
            case 2:
                s[j].grade = 'F';
                break;
            case 1:
                s[j].grade = 'F';
                break;
            }
            printf("---------------------------------------------------------------------------------\n");
            printf("Updated details are:\n");
            printf("%s\t\t%lu\t\t%.1f\t%c\n", s[j].name, s[j].reg_no, s[j].marks, s[j].grade);
            printf("---------------------------------------------------------------------------------\n");
            break;
        }
    }
    if (check == 0)
    {
        printf("Registration Number Not Found!\n");
        printf("---------------------------------------------------------------------------------\n");
    }
}

void deletedetail()
{
    int j, m, temp, check = 0;
    long int regno;
    printf("Enter registration Number to be deleted:");
    scanf("%lu", &regno);
    printf("---------------------------------------------------------------------------------\n");
    for (j = 0; j < count; j++)
    {
        if (s[j].reg_no == regno)
        {
            check++;
            for (m = j + 1; m <= count; m++)
            {
                s[j] = s[m];
                j++;
            }
            count--;
            break;
        }
    }
    if (check == 0)
    {
        printf("Registration Number Not Found!\n");
        printf("---------------------------------------------------------------------------------\n");
    }
    if (count == 0)
    {
        printf("No Record Found! Please Enter Record First.\n");
        printf("---------------------------------------------------------------------------------\n");
    }
    else if (count > 0)
    {
        printf("New Records:--\n");
        printf("S.No.\tName\t\t\tRegistration Number\tMarks\tGrade\n");
        for (j = 1; j <= count; j++)
        {
            printf("%d\t%s\t\t%lu\t\t%.1f\t%c\n", j, s[j - 1].name, s[j - 1].reg_no, s[j - 1].marks, s[j - 1].grade);
        }
        printf("\nTotal number of records=%d\n", count);
        printf("---------------------------------------------------------------------------------\n");
    }
}

void createdby()
{
    printf("\t\t\t\tSagar Singh\n");
   
    printf("---------------------------------------------------------------------------------\n");
}