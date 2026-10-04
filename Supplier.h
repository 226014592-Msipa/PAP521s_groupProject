#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100
#define MAX_STRING 100


typedef struct {
char supplierID[20];
char supplierName[70];
char Email[50];
char supplierPhone[15];
char Town[50];
} Supplier;

//FUNCTIONS
void addSupplier(void);
void displaySupplier(void);
void searchSupplier(void);
void compareSupplier(void);
void supplierMenu(void);

#endif 