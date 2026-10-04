#ifndef REPORTS_H
#define REPORTS_H

/* Reports module (Student 5)
   Reads the data stored by the Employee, Budget, Supplier and Asset
   modules and prints summary reports. It does not store any data. */

void employeeReport(void);
void supplierReport(void);
void assetReport(void);

/* Reports sub-menu: call this from main.c when the user picks option 5.
   The Budget Report is printed by displayBudgetReport() in budget.c */
void displayReports(void);

#endif
