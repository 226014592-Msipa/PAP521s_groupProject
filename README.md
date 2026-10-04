# Municipal Financial Management System (MFMS)

## Project Information
- **Course:** PAP521S - Programming & Algorithms | NUST


## Group Members & Responsibilities
1. **[Utjiua Kahoro] (226141314):**  Employee Module (`employees.h`, `employees.c`)
2. **[Albertina Ndjimba] (226072290):** Budget & Expenditure Module
3. **[Aloisia Itamalo] (225131943):** Supplier & Procurement Module
4. **[Amanda Msipa] (226014592):** Asset Management Module
5. **[Tulipamue Ndjadila] (226058751):** Reports & Analytics Module (`reports.h`, `reports.c`)
6. **[Junior S Mulozi] (226004155):** Main Integration & Master Menu (`main.c`)
7. **[Elvis Muyandulwa] (225095467):** (Testing, Documentation, Git Coordination) 

## System Description
The Municipal Financial Management System (MFMS) is a c system designed to automate and manage the financial operations of a municipality like handling salary calculations,rates and financial reports.

## System Features

### 1. Employee Management (`employees.c`)
- **Data Collection:** The module has a function to register employee ID, full name, department, basic salary, housing, transport, and tax deductions.
- **Salary Processing:** In this part it automatically calculates gross salary and net salary upon record entry.
- **Search & Display:** Allows exact ID matching using `strcmp()` and formatted payroll viewing[cite: 6].

### 2. Budget & Expenditure Tracking (`budget.c`)
- **Allocation & Tracking:** Records fixed departmental budgets with strict duplicate checks and zero/negative amount validation[cite: 4].
- **Over-Budget Warnings:** Evaluates spending against allocations, flagging departments that exceed their budget limit[cite: 4].
- **Stream Safety:** Implements dedicated input flushing routines (`budgetFlushLine()`) to prevent loop crashes on invalid numeric inputs[cite: 4].

### 3. Asset Management (`assets.c`)
- **Asset Registration:** Records asset IDs, names, categories (Vehicle, Device, Furniture, Equipment, Building), purchase values, departments, and operational conditions (Good, Fair, Damaged)[cite: 2].
- **Field Validation:** Enforces a minimum length of 5 characters for asset IDs[cite: 2].
- **ID Search:** Searches the asset registry by ID using standard string comparisons[cite: 2].

### 4. Cross-Module Reports & Analytics (`reports.c`)
- **Executive Analytics:** Reads global data structures from all sub-systems to output cross-functional analytics[cite: 8].
- **Metrics Computed:** Displays average employee salaries, total asset portfolio valuation, asset condition distributions (Good/Fair/Damaged), and departmental budget overruns. 

### 5.Main.c  
- ** main.c as the Main System Driver / Integration entry point.


## Compilation Instructions
To compile all modules together into the consolidated binary using GCC, run the following command in your terminal:

```bash
gcc main.c employees.c budget.c assets.c reports.c Supplier.c -o MFMS_System