#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS 20
#define MAX_DEPT_NAME 50

extern char budgetNames[MAX_DEPARTMENTS][MAX_DEPT_NAME];
extern double budgetAllocated[MAX_DEPARTMENTS];
extern double budgetSpent[MAX_DEPARTMENTS];
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
