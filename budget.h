#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS 20

typedef struct
{
    char name[50];
    float budget;
    float expenditure;
} Department;

void budgetMenu(Department departments[], int *departmentCount);
void addDepartmentBudget(Department departments[], int *departmentCount);
void enterExpenditure(Department departments[], int departmentCount);
void displayBudgets(Department departments[], int departmentCount);
void checkBudgetStatus(Department departments[], int departmentCount);

#endif
