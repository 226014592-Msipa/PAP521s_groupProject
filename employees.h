#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define MAX_EMPLOYEES 100

extern char employeeID[MAX_EMPLOYEES][20];
extern char employeeName[MAX_EMPLOYEES][50];
extern char department[MAX_EMPLOYEES][50];
extern float basicSalary[MAX_EMPLOYEES];
extern float housing[MAX_EMPLOYEES];
extern float transport[MAX_EMPLOYEES];
extern float tax[MAX_EMPLOYEES];
extern float grossSalary[MAX_EMPLOYEES];
extern float netSalary[MAX_EMPLOYEES];
extern int employeeCount;
void employeeMenu();
void addEmployee();
void displayEmployees();
void searchEmployee();
void calculateEmployeeSalary();
#endif
