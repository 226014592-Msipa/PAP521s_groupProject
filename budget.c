#include <stdio.h>
#include <string.h>
#include "budget.h"



void budgetMenu(Department departments[], int *departmentCount)
{
    int choice;

    do
    {
        printf("\n");
        printf("================================\n");
        printf("        BUDGET MANAGEMENT\n");
        printf("================================\n");
        printf("\n");
        printf("1. Add Department Budget\n");
        printf("2. Enter Expenditure\n");
        printf("3. Display Budgets\n");
        printf("4. Check Budget Status\n");
        printf("5. Back to Main Menu\n");
        printf("\nEnter choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addDepartmentBudget(departments, departmentCount);
                break;

            case 2:
                enterExpenditure(departments, *departmentCount);
                break;

            case 3:
                displayBudgets(departments, *departmentCount);
                break;

            case 4:
                checkBudgetStatus(departments, *departmentCount);
                break;

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice! Please enter a number from 1 to 5.\n");
        }

    } while(choice != 5);
}



void addDepartmentBudget(Department departments[], int *departmentCount)
{
    if (*departmentCount >= MAX_DEPARTMENTS)
    {
        printf("\nMaximum number of departments reached.\n");
        return;
    }

    printf("\n");
    printf("================================\n");
    printf("    ADD DEPARTMENT BUDGET\n");
    printf("================================\n");

    printf("Enter department name: ");
    scanf(" %[^\n]", departments[*departmentCount].name);

    printf("Enter department budget: N$ ");
    scanf("%f", &departments[*departmentCount].budget);

    // New department starts with zero expenditure
    departments[*departmentCount].expenditure = 0;

    (*departmentCount)++;

    printf("\nDepartment budget added successfully!\n");
}



void enterExpenditure(Department departments[], int departmentCount)
{
    char departmentName[50];
    float amount;
    int found = 0;
    int i;

    if (departmentCount == 0)
    {
        printf("\nNo departments have been added yet.\n");
        return;
    }

    printf("\n");
    printf("================================\n");
    printf("       ENTER EXPENDITURE\n");
    printf("================================\n");

    printf("Enter department name: ");
    scanf(" %[^\n]", departmentName);

    for (i = 0; i < departmentCount; i++)
    {
        if (strcmp(departments[i].name, departmentName) == 0)
        {
            printf("Enter expenditure amount: N$ ");
            scanf("%f", &amount);

            departments[i].expenditure =
                departments[i].expenditure + amount;

            printf("\nExpenditure recorded successfully!\n");
            printf("Department: %s\n", departments[i].name);
            printf("Total expenditure: N$ %.2f\n",
                   departments[i].expenditure);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nDepartment not found!\n");
    }
}



void displayBudgets(Department departments[], int departmentCount)
{
    int i;
    float remaining;

    if (departmentCount == 0)
    {
        printf("\nNo department budgets have been added yet.\n");
        return;
    }

    printf("\n");
    printf("==============================================================\n");
    printf("                    BUDGET INFORMATION\n");
    printf("==============================================================\n");

    printf("%-20s %-15s %-15s %-15s\n",
           "Department",
           "Budget",
           "Expenditure",
           "Remaining");

    printf("--------------------------------------------------------------\n");

    for (i = 0; i < departmentCount; i++)
    {
        // Calculate remaining budget
        remaining = departments[i].budget -
                    departments[i].expenditure;

        printf("%-20s N$ %-12.2f N$ %-12.2f N$ %-12.2f\n",
               departments[i].name,
               departments[i].budget,
               departments[i].expenditure,
               remaining);
    }

    printf("==============================================================\n");
}



void checkBudgetStatus(Department departments[], int departmentCount)
{
    int i;
    float remaining;
    int exceeded = 0;

    if (departmentCount == 0)
    {
        printf("\nNo department budgets have been added yet.\n");
        return;
    }

    printf("\n");
    printf("============================================\n");
    printf("             BUDGET STATUS\n");
    printf("============================================\n");

    for (i = 0; i < departmentCount; i++)
    {
        remaining = departments[i].budget -
                    departments[i].expenditure;

        printf("\nDepartment: %s\n",
               departments[i].name);

        printf("Budget: N$ %.2f\n",
               departments[i].budget);

        printf("Expenditure: N$ %.2f\n",
               departments[i].expenditure);

        if (departments[i].expenditure <=
            departments[i].budget)
        {
            printf("Status: WITHIN BUDGET\n");
            printf("Remaining: N$ %.2f\n",
                   remaining);
        }
        else
        {
            printf("Status: OVER BUDGET\n");

            printf("Amount exceeded: N$ %.2f\n",
                   departments[i].expenditure -
                   departments[i].budget);

            exceeded = 1;
        }
    }

    printf("\n============================================\n");

    // Identify departments that exceeded their budget
    if (exceeded == 1)
    {
        printf("\nDepartments that exceeded their budget:\n");

        for (i = 0; i < departmentCount; i++)
        {
            if (departments[i].expenditure >
                departments[i].budget)
            {
                printf("- %s\n",
                       departments[i].name);
            }
        }
    }
    else
    {
        printf("\nNo departments have exceeded their budget.\n");
    }
}
