#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100
#define NAME_LEN 50
#define DEPT_LEN 50
#define STATUS_LEN 20

typedef struct {
    int id;
    char name[NAME_LEN];
    char department[DEPT_LEN];
    char employmentStatus[STATUS_LEN];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
    double pensionDeduction;
    double grossSalary;
    double netSalary;
} Employee;

Employee calculateSalary(Employee emp);
int addEmployee(Employee employees[], int count);
void displayEmployees(const Employee employees[], int count);
void searchEmployee(const Employee employees[], int count);
int employeeMenu(Employee employees[], int count);

#endif