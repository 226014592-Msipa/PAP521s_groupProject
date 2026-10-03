#include <stdio.h>
#include <string.h>
#include "employees.h"

Employee calculateSalary(Employee emp) {
    emp.grossSalary = emp.basicSalary + emp.housingAllowance + emp.transportAllowance;
    if (emp.grossSalary >= emp.pensionDeduction) {
        emp.netSalary = emp.grossSalary - emp.pensionDeduction;
    } else {
        emp.netSalary = 0.0;
    }
    return emp;
}

int addEmployee(Employee employees[], int count) {
    if (count >= MAX_EMPLOYEES) {
        printf("\n[ERROR] System full. Cannot store more records.\n");
        return count;
    }

    Employee newEmp;
    char firstName[NAME_LEN / 2];
    char lastName[NAME_LEN / 2];

    printf("\n=== ADD NEW MUNICIPAL EMPLOYEE ===\n");

    while (1) {
        printf("Enter Employee ID: ");
        if (scanf("%d", &newEmp.id) == 1 && newEmp.id > 0) {
            while (getchar() != '\n'); 
            break;
        } else {
            printf("[INVALID] Please enter a valid positive integer ID.\n");
            while (getchar() != '\n');
        }
    }

    do {
        printf("Enter First Name: ");
        fgets(firstName, sizeof(firstName), stdin);
        firstName[strcspn(firstName, "\n")] = '\0';

        printf("Enter Last Name: ");
        fgets(lastName, sizeof(lastName), stdin);
        lastName[strcspn(lastName, "\n")] = '\0';

        if (strlen(firstName) == 0 || strlen(lastName) == 0) {
            printf("[ERROR] First and last names cannot be empty.\n");
        }
    } while (strlen(firstName) == 0 || strlen(lastName) == 0);

    strcpy(newEmp.name, firstName);
    strcat(newEmp.name, " ");
    strcat(newEmp.name, lastName);

    printf("Enter Department: ");
    fgets(newEmp.department, DEPT_LEN, stdin);
    newEmp.department[strcspn(newEmp.department, "\n")] = '\0';

    printf("Enter Employment Status (Permanent/Contract): ");
    fgets(newEmp.employmentStatus, STATUS_LEN, stdin);
    newEmp.employmentStatus[strcspn(newEmp.employmentStatus, "\n")] = '\0';

    do {
        printf("Enter Basic Salary (N$): ");
        if (scanf("%lf", &newEmp.basicSalary) != 1 || newEmp.basicSalary < 0) {
            printf("[INVALID] Salary must be non-negative.\n");
            while (getchar() != '\n');
            newEmp.basicSalary = -1;
        } else {
            while (getchar() != '\n');
        }
    } while (newEmp.basicSalary < 0);

    do {
        printf("Enter Housing Allowance (N$): ");
        if (scanf("%lf", &newEmp.housingAllowance) != 1 || newEmp.housingAllowance < 0) {
            printf("[INVALID] Allowance must be non-negative.\n");
            while (getchar() != '\n');
            newEmp.housingAllowance = -1;
        } else {
            while (getchar() != '\n');
        }
    } while (newEmp.housingAllowance < 0);

    do {
        printf("Enter Transport Allowance (N$): ");
        if (scanf("%lf", &newEmp.transportAllowance) != 1 || newEmp.transportAllowance < 0) {
            printf("[INVALID] Allowance must be non-negative.\n");
            while (getchar() != '\n');
            newEmp.transportAllowance = -1;
        } else {
            while (getchar() != '\n');
        }
    } while (newEmp.transportAllowance < 0);

    do {
        printf("Enter Pension Deduction (N$): ");
        if (scanf("%lf", &newEmp.pensionDeduction) != 1 || newEmp.pensionDeduction < 0) {
            printf("[INVALID] Deduction must be non-negative.\n");
            while (getchar() != '\n');
            newEmp.pensionDeduction = -1;
        } else {
            while (getchar() != '\n');
        }
    } while (newEmp.pensionDeduction < 0);

    newEmp = calculateSalary(newEmp);

    employees[count] = newEmp;
    count++;

    printf("\n[SUCCESS] Employee '%s' recorded successfully!\n", newEmp.name);
    return count;
}

void displayEmployees(const Employee employees[], int count) {
    if (count == 0) {
        printf("\n[INFO] No employee records found.\n");
        return;
    }

    printf("\n================================================= MUNICIPAL EMPLOYEE RECORDS =================================================\n");
    printf("%-5s | %-18s | %-12s | %-10s | %-10s | %-10s | %-10s | %-10s\n", 
           "ID", "Name", "Department", "Status", "Basic (N$)", "Gross (N$)", "Pension", "Net (N$)");
    printf("----------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d | %-18s | %-12s | %-10s | %-10.2f | %-10.2f | %-10.2f | %-10.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].employmentStatus,
               employees[i].basicSalary,
               employees[i].grossSalary,
               employees[i].pensionDeduction,
               employees[i].netSalary);
    }
    printf("============================================================================================================================\n");
}

void searchEmployee(const Employee employees[], int count) {
    if (count == 0) {
        printf("\n[INFO] No records available to search.\n");
        return;
    }

    int choice;
    printf("\n--- SEARCH EMPLOYEE ---\n");
    printf("1. Search by Employee ID\n");
    printf("2. Search by Full Name (Exact Match)\n");
    printf("3. Search by Name (Partial Match)\n");
    printf("Enter choice: ");
    
    if (scanf("%d", &choice) != 1) {
        printf("[ERROR] Invalid choice.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    if (choice == 1) {
        int searchId;
        printf("Enter Employee ID: ");
        scanf("%d", &searchId);
        while (getchar() != '\n');

        for (int i = 0; i < count; i++) {
            if (employees[i].id == searchId) {
                printf("\n--- Match Found ---\n");
                printf("ID: %d | Name: %s | Dept: %s | Status: %s | Net Salary: N$%.2f\n",
                       employees[i].id, employees[i].name, employees[i].department, 
                       employees[i].employmentStatus, employees[i].netSalary);
                return;
            }
        }
        printf("[INFO] No employee found with ID %d.\n", searchId);

    } else if (choice == 2) {
        char searchName[NAME_LEN];
        printf("Enter Full Name (e.g. John Doe): ");
        fgets(searchName, NAME_LEN, stdin);
        searchName[strcspn(searchName, "\n")] = '\0';

        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(employees[i].name, searchName) == 0) {
                printf("\n--- Exact Match Found ---\n");
                printf("ID: %d | Name: %s | Dept: %s | Status: %s | Net Salary: N$%.2f\n",
                       employees[i].id, employees[i].name, employees[i].department, 
                       employees[i].employmentStatus, employees[i].netSalary);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("[INFO] No exact match for '%s'.\n", searchName);
        }

    } else if (choice == 3) {
        char searchName[NAME_LEN];
        printf("Enter partial name: ");
        fgets(searchName, NAME_LEN, stdin);
        searchName[strcspn(searchName, "\n")] = '\0';

        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strstr(employees[i].name, searchName) != NULL) {
                printf("\n--- Match Found ---\n");
                printf("ID: %d | Name: %s | Dept: %s | Status: %s | Net Salary: N$%.2f\n",
                       employees[i].id, employees[i].name, employees[i].department, 
                       employees[i].employmentStatus, employees[i].netSalary);
                found = 1;
            }
        }
        if (!found) {
            printf("[INFO] No employee matching '%s' found.\n", searchName);
        }
    } else {
        printf("[ERROR] Invalid option.\n");
    }
}

int employeeMenu(Employee employees[], int count) {
    int choice;
    do {
        printf("\n--- EMPLOYEE MANAGEMENT MODULE ---\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Return to Main Menu\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("[ERROR] Please enter a valid option.\n");
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                count = addEmployee(employees, count);
                break;
            case 2:
                displayEmployees(employees, count);
                break;
            case 3:
                searchEmployee(employees, count);
                break;
            case 4:
                printf("Returning to Main Menu...\n");
                break;
            default:
                            printf("[ERROR] Invalid choice, try again.\n");
        }
  } while (choice != 4);

    return count;
}