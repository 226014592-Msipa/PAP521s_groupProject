#include"stdio.h"
#include "employees.h"
#include "budget.h"
#include "Supplier.h"
#include "assets.h"
#include "reports.h"

int main()
{
	int choice = 0;

while (choice !=6)
{

printf("\n==================================\n");
printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
printf("====================================\n");
printf("1. Employee Management\n");
printf("2. Budget Management\n");
printf("3. Supplier Management\n");
printf("4. Asset Management\n");
printf("5. Reports\n");
printf("6. Exit\n");
printf("Enter your choice\n");

if (scanf("%d", &choice) !=1)
{
	printf("Invalid input. Please enter a number from 1 to 6.\n");

	while (getchar() != '\n');
	continue;
}

switch (choice)
{
	case 1:
	    employeeMenu();
		break;

	case 2:
	    budgetMenu();
		break;

	case 3:
	   supplierMenu();
		break;

	case 4:
	   assetMenu();
		break;

	case 5:
	   displayReports();
		break;

	default:
	       printf("Invalid choice. Please enter a number from 1 to 6.\n");
		break;
}

}

return 0;
}
