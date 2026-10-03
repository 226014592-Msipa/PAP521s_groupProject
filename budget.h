#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS   20
#define MAX_DEPT_NAME     20

void budgetMenu(void);

void enterDepartmentBudget(void);
void enterExpenditure(void);
void displayBudgetInfo(void);
void searchDepartmentBudget(void);
void displayExceededDepartments(void);

double calculateRemainingBudget(double allocated, double expenditure);
int    isWithinBudget(double allocated, double expenditure);

int    getDepartmentCount(void);
double getTotalAllocated(void);
double getTotalExpenditure(void);
double getTotalRemaining(void);
int    countExceededDepartments(void);
void   displayBudgetReport(void);

#endif 
