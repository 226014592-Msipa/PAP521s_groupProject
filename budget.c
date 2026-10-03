#include <stdio.h>
#include <string.h>
#include "budget.h"

char budgetNames[20][20];
double budgetAllocated[20];
double budgetSpent[20];
int budgetCount = 0;

void budgetFlushLine(void);
int budgetReadName(char name[], int size);
double budgetReadAmount(char prompt[], int allowZero);
int budgetReadChoice(void);
int budgetFindDepartment(char name[]);
void budgetPrintHeader(void);
void budgetPrintRow(int index);

void budgetFlushLine(void)
{
    int c;
    while ((c = getchar())!= '\n' && c!= EOF);
}

int budgetReadName(char name[], int size)
{
    char line[200];
    int length;
    int i;
    int hasText = 0;

    printf("Department name: ");
    if (fgets(line, sizeof(line), stdin) == NULL)
    {
        return -1;
    }

    length = strcspn(line, "\n");
    if (line[length] == '\0')
    {
        budgetFlushLine();
    }
    line[length] = '\0';

    for (i = 0; i < length; i++)
    {
        if (line[i]!= ' ' && line[i]!= '\t')
        {
            hasText = 1;
        }
    }

    if (hasText == 0)
    {
        printf("Error: department name cannot be empty.\n");
        return 0;
    }
    if (strlen(line) >= (size_t)size)
    {
        printf("Error: department name must be shorter than %d characters.\n",
               size);
        return 0;
    }

    strcpy(name, line);
    return 1;
}

double budgetReadAmount(char prompt[], int allowZero)
{
    double amount;
    int result;

    while (1)
    {
        printf("%s", prompt);
        result = scanf("%lf", &amount);

        if (result == EOF)
        {
            printf("\nInput closed.\n");
            return -1.0;
        }
        budgetFlushLine();

        if (result!= 1)
        {
            printf(" Error: please enter a valid number.\n");
        }
        else if (amount < 0)
        {
            printf(" Error: amount cannot be negative.\n");
        }
        else if (amount == 0 && allowZero == 0)
        {
            printf(" Error: amount must be greater than zero.\n");
        }
        else
        {
            return amount;
        }
    }
}

int budgetReadChoice(void)
{
    int choice;
    int result;

    printf("Enter your choice: ");
    result = scanf("%d", &choice);

    if (result == EOF)
    {
        printf("\nInput closed. Returning to main menu...\n");
        return 6;
    }
    budgetFlushLine();

    if (result!= 1)
    {
        return -1;
    }
    return choice;
}

int budgetFindDepartment(char name[])
{
    int i;

    for (i = 0; i < budgetCount; i++)
    {
        if (strcmp(budgetNames[i], name) == 0)
        {
            return i;
        }
    }
    return -1;
}

void budgetPrintHeader(void)
{
    printf("\n%-20s %15s %15s %15s %s\n",
           "Department", "Allocated (N$)", "Spent (N$)",
           "Remaining (N$)", "Status");
    printf("-----------------------------------------------------------"
           "------------------\n");
}

void budgetPrintRow(int index)
{
    double remaining;

    remaining = calculateRemainingBudget(budgetAllocated[index],
                                         budgetSpent[index]);
    printf("%-20s %15.2f %15.2f %15.2f ",
           budgetNames[index], budgetAllocated[index],
           budgetSpent[index], remaining);

    if (isWithinBudget(budgetAllocated[index], budgetSpent[index]))
    {
        printf("WITHIN BUDGET\n");
    }
    else
    {
        printf("OVER BUDGET\n");
    }
}

/* ---------- Calculations ---------- */

double calculateRemainingBudget(double allocated, double spent)
{
    return allocated - spent;
}

int isWithinBudget(double allocated, double spent)
{
    if (spent <= allocated)
    {
        return 1;
    }
    return 0;
}


void enterDepartmentBudget(void)
{
    char name[MAX_DEPT_NAME];
    double amount;
    int result;

    printf("\n--- Enter Departmental Budget ---\n");

    if (budgetCount >= MAX_DEPARTMENTS)
    {
        printf("Error: maximum of %d departments reached.\n", MAX_DEPARTMENTS);
        return;
    }

    result = budgetReadName(name, MAX_DEPT_NAME);
    if (result!= 1)
    {
        return;
    }

    if (budgetFindDepartment(name)!= -1)
    {
        printf("Error: department '%s' already exists.\n", name);
        return;
    }

    amount = budgetReadAmount("Allocated budget (N$): ", 0);
    if (amount < 0)
    {
        return;
    }

    strcpy(budgetNames[budgetCount], name);
    budgetAllocated[budgetCount] = amount;
    budgetSpent[budgetCount] = 0.0;
    budgetCount++;

    printf("Budget of N$%.2f saved for %s.\n", amount, name);
}

void enterExpenditure(void)
{
    char name[MAX_DEPT_NAME];
    double amount;
    double remaining;
    int index;
    int result;

    printf("\n--- Enter Expenditure ---\n");

    if (budgetCount == 0)
    {
        printf("No departments registered yet. Add a budget first.\n");
        return;
    }

    result = budgetReadName(name, MAX_DEPT_NAME);
    if (result!= 1)
    {
        return;
    }

    index = budgetFindDepartment(name);
    if (index == -1)
    {
        printf("Error: department '%s' not found.\n", name);
        return;
    }

    amount = budgetReadAmount("Expenditure amount (N$): ", 1);
    if (amount < 0)
    {
        return;
    }

    budgetSpent[index] = budgetSpent[index] + amount;
    remaining = calculateRemainingBudget(budgetAllocated[index],
                                         budgetSpent[index]);

    printf("Total expenditure for %s: N$%.2f\n", name, budgetSpent[index]);
    printf("Remaining budget: N$%.2f\n", remaining);

    if (isWithinBudget(budgetAllocated[index], budgetSpent[index]) == 0)
    {
        printf("WARNING: %s has exceeded its budget by N$%.2f!\n",
               name, -remaining);
    }
}

void displayBudgetInfo(void)
{
    int i;

    printf("\n--- Budget Information ---\n");

    if (budgetCount == 0)
    {
        printf("No budget information available.\n");
        return;
    }

    budgetPrintHeader();
    for (i = 0; i < budgetCount; i++)
    {
        budgetPrintRow(i);
    }
}

void searchDepartmentBudget(void)
{
    char name[MAX_DEPT_NAME];
    double remaining;
    int index;
    int result;

    printf("\n--- Search Department Budget ---\n");

    if (budgetCount == 0)
    {
        printf("No departments registered yet.\n");
        return;
    }

    result = budgetReadName(name, MAX_DEPT_NAME);
    if (result!= 1)
    {
        return;
    }

    index = budgetFindDepartment(name);
    if (index == -1)
    {
        printf("Department '%s' not found.\n", name);
        return;
    }

    remaining = calculateRemainingBudget(budgetAllocated[index],
                                         budgetSpent[index]);
    printf("\nDepartment: %s\n", budgetNames[index]);
    printf("Allocated Budget: N$%.2f\n", budgetAllocated[index]);
    printf("Expenditure: N$%.2f\n", budgetSpent[index]);
    printf("Remaining Budget: N$%.2f\n", remaining);

    if (isWithinBudget(budgetAllocated[index], budgetSpent[index]))
    {
        printf("Status: WITHIN BUDGET\n");
    }
    else
    {
        printf("Status: OVER BUDGET\n");
    }
}

void displayExceededDepartments(void)
{
    int i;
    int found = 0;

    printf("\n--- Departments Exceeding Budget ---\n");

    for (i = 0; i < budgetCount; i++)
    {
        if (isWithinBudget(budgetAllocated[i], budgetSpent[i]) == 0)
        {
            if (found == 0)
            {
                budgetPrintHeader();
                found = 1;
            }
            budgetPrintRow(i);
        }
    }

    if (found == 0)
    {
        printf("No department has exceeded its budget.\n");
    }
}

int getDepartmentCount(void)
{
    return budgetCount;
}

double getTotalAllocated(void)
{
    double total = 0.0;
    int i;

    for (i = 0; i < budgetCount; i++)
    {
        total = total + budgetAllocated[i];
    }
    return total;
}

double getTotalExpenditure(void)
{
    double total = 0.0;
    int i;

    for (i = 0; i < budgetCount; i++)
    {
        total = total + budgetSpent[i];
    }
    return total;
}

double getTotalRemaining(void)
{
    return calculateRemainingBudget(getTotalAllocated(), getTotalExpenditure());
}

int countExceededDepartments(void)
{
    int count = 0;
    int i;

    for (i = 0; i < budgetCount; i++)
    {
        if (isWithinBudget(budgetAllocated[i], budgetSpent[i]) == 0)
        {
            count++;
        }
    }
    return count;
}

void displayBudgetReport(void)
{
    int i;
    int found = 0;

    printf("\n========================================\n");
    printf(" BUDGET REPORT\n");
    printf("========================================\n");

    if (budgetCount == 0)
    {
        printf("No budget data available.\n");
        return;
    }

    printf("Total Departments: %d\n", budgetCount);
    printf("Total Allocated Budget: N$%.2f\n", getTotalAllocated());
    printf("Total Expenditure: N$%.2f\n", getTotalExpenditure());
    printf("Total Remaining Budget: N$%.2f\n", getTotalRemaining());

    printf("\nDepartments exceeding budget: %d\n", countExceededDepartments());
    for (i = 0; i < budgetCount; i++)
    {
        if (isWithinBudget(budgetAllocated[i], budgetSpent[i]) == 0)
        {
            printf(" - %s (over by N$%.2f)\n", budgetNames[i],
                   budgetSpent[i] - budgetAllocated[i]);
            found = 1;
        }
    }
    if (found == 0)
    {
        printf(" None\n");
    }
}


void budgetMenu(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf(" BUDGET MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Enter Departmental Budget\n");
        printf("2. Enter Expenditure\n");
        printf("3. Display Budget Information\n");
        printf("4. Search Department\n");
        printf("5. Show Departments Exceeding Budget\n");
        printf("6. Back to Main Menu\n");

        choice = budgetReadChoice();

        switch (choice)
        {
            case 1:
                enterDepartmentBudget();
                break;
            case 2:
                enterExpenditure();
                break;
            case 3:
                displayBudgetInfo();
                break;
            case 4:
                searchDepartmentBudget();
                break;
            case 5:
                displayExceededDepartments();
                break;
            case 6:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 6.\n");
        }
    } while (choice!= 6);
}
