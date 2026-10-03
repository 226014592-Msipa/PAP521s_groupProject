#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <stdio.h>
#include <string.h>
char employeeID[100][20];
char employeeName[100][50];
char department[100][50];
float basicSalary[100];
float housing[100];
float transport[100];
float tax[100];
float grossSalary[100];
float netSalary[100];
int employeeCount = 0;
void employeeMenu();
void addEmployee();
void displayEmployees();
void searchEmployee();
void calculateEmployeeSalary();
#endif
