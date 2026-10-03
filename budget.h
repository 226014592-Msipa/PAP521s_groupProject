#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS 20
#define MAX_DEPT_NAME 20

extern char budgetNames[20][20];
extern double budgetAllocated[20];
extern double budgetSpent[20];
extern int budgetCount;

double calculateRemainingBudget(double allocated, double spent);
int isWithinBudget(double allocated, double spent);

void enterDepartmentBudget(void);
void enterExpenditure(void);
void displayBudgetInfo(void);
void searchDepartmentBudget(void);
void displayExceededDepartments(void);

int getDepartmentCount(void);
double getTotalAllocated(void);
double getTotalExpenditure(void);
double getTotalRemaining(void);
int countExceededDepartments(void);
void displayBudgetReport(void);

void budgetMenu(void);

#endif
