#include <stdio.h>
#include <string.h>
#include "reports.h"
#include "budget.h"
#include "assets.h"
#include "Supplier.h"

/* Employee data is defined in employees.c (Student 1). */
extern char  employeeName[100][50];
extern float grossSalary[100];
extern float netSalary[100];
extern int   employeeCount;

/* Supplier data is defined in Supplier.c (Student 3). */
extern Supplier suppliers[MAX_SUPPLIERS];
extern int      supplierCount;

/* Throw away anything left on the input line */
static void reportsFlushLine(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Read the menu choice safely. Returns -1 for invalid input
   and 5 (Back) if the input has closed. */
static int reportsReadChoice(void)
{
    int choice;
    int result;

    printf("Enter your choice: ");
    result = scanf("%d", &choice);

    if (result == EOF)
    {
        return 5;
    }
    reportsFlushLine();

    if (result != 1)
    {
        return -1;
    }
    return choice;
}

void employeeReport(void)
{
    int i;
    int highest = 0;
    int lowest = 0;
    float totalGross = 0.0f;
    float totalNet = 0.0f;

    printf("\n========================================\n");
    printf(" EMPLOYEE REPORT\n");
    printf("========================================\n");

    if (employeeCount == 0)
    {
        printf("No employees registered yet.\n");
        return;
    }

    for (i = 0; i < employeeCount; i++)
    {
        totalGross = totalGross + grossSalary[i];
        totalNet = totalNet + netSalary[i];

        if (grossSalary[i] > grossSalary[highest])
        {
            highest = i;
        }
        if (grossSalary[i] < grossSalary[lowest])
        {
            lowest = i;
        }
    }

    printf("Total Employees      : %d\n", employeeCount);
    printf("Average Gross Salary : N$%.2f\n", totalGross / employeeCount);
    printf("Average Net Salary   : N$%.2f\n", totalNet / employeeCount);
    printf("Highest Gross Salary : N$%.2f (%s)\n",
           grossSalary[highest], employeeName[highest]);
    printf("Lowest Gross Salary  : N$%.2f (%s)\n",
           grossSalary[lowest], employeeName[lowest]);
}

void supplierReport(void)
{
    int i;

    printf("\n========================================\n");
    printf(" SUPPLIER REPORT\n");
    printf("========================================\n");

    if (supplierCount == 0)
    {
        printf("No suppliers registered yet.\n");
        return;
    }

    printf("%-10s %-22s %-26s %-14s %-14s\n",
           "ID", "Name", "Email", "Phone", "Town");
    printf("-------------------------------------------------------"
           "-----------------------------------\n");

    for (i = 0; i < supplierCount; i++)
    {
        printf("%-10s %-22s %-26s %-14s %-14s\n",
               suppliers[i].supplierID, suppliers[i].supplierName,
               suppliers[i].Email, suppliers[i].supplierPhone,
               suppliers[i].Town);
    }

    printf("\nTotal Suppliers: %d\n", supplierCount);
}

void assetReport(void)
{
    int i;
    int good = 0;
    int fair = 0;
    int damaged = 0;
    int other = 0;
    double totalValue = 0.0;

    printf("\n========================================\n");
    printf(" ASSET REPORT\n");
    printf("========================================\n");

    if (assetCount == 0)
    {
        printf("No assets registered yet.\n");
        return;
    }

    printf("%-12s %-18s %-12s %12s %-14s %-9s\n",
           "ID", "Name", "Type", "Value (N$)", "Department", "Condition");
    printf("-------------------------------------------------------"
           "-------------------------\n");

    for (i = 0; i < assetCount; i++)
    {
        printf("%-12s %-18s %-12s %12.2f %-14s %-9s\n",
               assetIDs[i], assetNames[i], assetTypes[i],
               assetValues[i], assetDepartments[i], assetCondition[i]);

        totalValue = totalValue + assetValues[i];

        if (strcmp(assetCondition[i], "Good") == 0)
        {
            good++;
        }
        else if (strcmp(assetCondition[i], "Fair") == 0)
        {
            fair++;
        }
        else if (strcmp(assetCondition[i], "Damaged") == 0)
        {
            damaged++;
        }
        else
        {
            other++;
        }
    }

    printf("\nTotal Assets      : %d\n", assetCount);
    printf("Total Asset Value : N$%.2f\n", totalValue);
    printf("Good: %d | Fair: %d | Damaged: %d | Other: %d\n",
           good, fair, damaged, other);
}

void displayReports(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf(" REPORTS\n");
        printf("========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");

        choice = reportsReadChoice();

        switch (choice)
        {
            case 1:
                employeeReport();
                break;
            case 2:
                displayBudgetReport();
                break;
            case 3:
                supplierReport();
                break;
            case 4:
                assetReport();
                break;
            case 5:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 5.\n");
        }
    } while (choice != 5);
}
