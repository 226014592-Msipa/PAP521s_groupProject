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

void employeeMenu()
{
    printf("\n--- EMPLOYEE MENU ---\n");
    printf("1. Add Employee\n");
    printf("2. Display Employees\n");
    printf("3. Search Employee\n");
    printf("4. Calculate Salary\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

void addEmployee()
{
    if(employeeCount >= 100)
    {
        printf("100 employees full\n");
        return;
    }

    getchar();

    printf("Enter Employee ID: ");
    fgets(employeeID[employeeCount], 20, stdin);
    employeeID[employeeCount][strcspn(employeeID[employeeCount], "\n")] = '\0';

    printf("Enter Employee Name: ");
    fgets(employeeName[employeeCount], 50, stdin);
    employeeName[employeeCount][strcspn(employeeName[employeeCount], "\n")] = '\0';

    printf("Enter Department: ");
    fgets(department[employeeCount], 50, stdin);
    department[employeeCount][strcspn(department[employeeCount], "\n")] = '\0';

    printf("Enter Basic Salary: ");
    scanf("%f", &basicSalary[employeeCount]);

    printf("Enter Housing Allowance: ");
    scanf("%f", &housing[employeeCount]);

    printf("Enter Transport Allowance: ");
    scanf("%f", &transport[employeeCount]);

    printf("Enter Tax: ");
    scanf("%f", &tax[employeeCount]);

    /* Calculate Gross Salary */
    grossSalary[employeeCount] =
        basicSalary[employeeCount] +
        housing[employeeCount] +
        transport[employeeCount];

    /* Calculate Net Salary */
    netSalary[employeeCount] =
        grossSalary[employeeCount] -
        tax[employeeCount];

    employeeCount++;

    printf("\nEmployee added successfully!\n");
}

void displayEmployees()
{
    if(employeeCount == 0)
    {
        printf("No employees\n");
        return;
    }

    for(int i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("Employee ID: %s\n", employeeID[i]);
        printf("Employee Name: %s\n", employeeName[i]);
        printf("Department: %s\n", department[i]);
        printf("Basic Salary: %.2f\n", basicSalary[i]);
        printf("Housing Allowance: %.2f\n", housing[i]);
        printf("Transport Allowance: %.2f\n", transport[i]);
        printf("Tax: %.2f\n", tax[i]);
        printf("Gross Salary: %.2f\n", grossSalary[i]);
        printf("Net Salary: %.2f\n", netSalary[i]);
    }
}

void searchEmployee()
{
    char search[20];

    printf("Enter Employee ID to search: ");
    scanf("%s", search);

    for(int i = 0; i < employeeCount; i++)
    {
        if(strcmp(employeeID[i], search) == 0)
        {
            printf("\nEmployee Found!\n");
            printf("Employee ID: %s\n", employeeID[i]);
            printf("Employee Name: %s\n", employeeName[i]);
            printf("Department: %s\n", department[i]);
            printf("Gross Salary: %.2f\n", grossSalary[i]);
            printf("Net Salary: %.2f\n", netSalary[i]);

            return;
        }
    }

    printf("Employee not found\n");
}

void calculateEmployeeSalary()
{
    float totalGross = 0;
    float totalNet = 0;

    if(employeeCount == 0)
    {
        printf("No payroll\n");
        return;
    }

    for(int i = 0; i < employeeCount; i++)
    {
        totalGross = totalGross + grossSalary[i];
        totalNet = totalNet + netSalary[i];
    }

    printf("\n--- SALARY CALCULATION ---\n");
    printf("Total Gross Salary: %.2f\n", totalGross);
    printf("Total Net Salary: %.2f\n", totalNet);
}

int main()
{
    int choice;

    while(1)
    {
        employeeMenu();

        scanf("%d", &choice);

        if(choice == 1)
        {
            addEmployee();
        }
        else if(choice == 2)
        {
            displayEmployees();
        }
        else if(choice == 3)
        {
            searchEmployee();
        }
        else if(choice == 4)
        {
            calculateEmployeeSalary();
        }
        else if(choice == 5)
        {
            break;
        }
        else
        {
            printf("Wrong choice\n");
        }
    }

    return 0;
}
