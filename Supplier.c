#include <stdio.h>
#include <string.h>
#include "Supplier.h"
 
char supplierID[20];
char supplierName[70];
char Email[50];
char supplierPhone[15];
char Town[50];
char searchName[70];

Supplier suppliers[MAX_SUPPLIERS]; 
int supplierCount = 0;

void addSupplier(void){  

    if (supplierCount >= MAX_SUPPLIERS) { 
        printf("No more suppliers can be added.\n"); 
        return; 
    } 
        
        printf("Enter Supplier ID: "); 
        fgets(suppliers[supplierCount].supplierID, 
        sizeof(suppliers[supplierCount].supplierID), stdin); 
        suppliers[supplierCount].supplierID[ 
        strcspn(suppliers[supplierCount].supplierID, "\n") ] = '\0'; 
                
        printf("Enter Supplier Name: "); 
        fgets(suppliers[supplierCount].supplierName, 
        sizeof(suppliers[supplierCount].supplierName), stdin); 
        suppliers[supplierCount].supplierName[ 
        strcspn(suppliers[supplierCount].supplierName, "\n") ] = '\0'; 
                
        printf("Enter Supplier Email: "); 
        fgets(suppliers[supplierCount].Email, 
        sizeof(suppliers[supplierCount].Email), stdin); 
        suppliers[supplierCount].Email[ 
        strcspn(suppliers[supplierCount].Email, "\n") ] = '\0'; 
       
        printf("Enter Supplier Phone: "); 
        fgets(suppliers[supplierCount].supplierPhone, 
        sizeof(suppliers[supplierCount].supplierPhone), stdin); 
        suppliers[supplierCount].supplierPhone[ 
        strcspn(suppliers[supplierCount].supplierPhone, "\n") ] = '\0'; 
        
        printf("Enter Town: "); 
        fgets(suppliers[supplierCount].Town, 
        sizeof(suppliers[supplierCount].Town), stdin); 
        suppliers[supplierCount].Town[ 
        strcspn(suppliers[supplierCount].Town, "\n") ] = '\0'; 
                
        supplierCount++; 
    
    printf("\nSupplier added successfully.\n"); }

void displaySupplier(void){

    if (supplierCount == 0)
    {
        printf("\nNo suppliers have been added.\n");
        return;
    }

    printf("\n==== Supplier Information ====\n");

    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("   ID     : %s\n", suppliers[i].supplierID);
        printf("   Name   : %s\n", suppliers[i].supplierName);
        printf("   Email  : %s\n", suppliers[i].Email);
        printf("   Phone  : %s\n", suppliers[i].supplierPhone);
        printf("   Town   : %s\n", suppliers[i].Town);
    }
}

void searchSupplier(void){ 

 char searchName[70]; 
 int found = 0; 
 
 printf("\nEnter Supplier name or ID to search: "); 
 fgets(searchName, sizeof(searchName), stdin); 
 searchName[strcspn(searchName, "\n")] = '\0'; 
 
 for (int i = 0; i < supplierCount; i++) { 
    if (strcmp(suppliers[i].supplierName, searchName) == 0 || strcmp(suppliers[i].supplierID, searchName) == 0) { 
        
        printf("\n==== Supplier Found ====\n"); 
        printf("ID : %s\n", suppliers[i].supplierID); 
        printf("Name : %s\n", suppliers[i].supplierName); 
        printf("Email : %s\n", suppliers[i].Email); 
        printf("Phone : %s\n", suppliers[i].supplierPhone); 
        printf("Town : %s\n", suppliers[i].Town); 
        
        found = 1; 
        break; } 
    } 
        
        if (found == 0) { 
            printf("Supplier not found.\n"); 
        } 
        
        }

void compareSupplier(void){// dont comfuse this with searchSupplier, this is for comparing two suppliers
    
int first, second;
 if (supplierCount < 2){ 
    printf("\nAt least two suppliers are needed to compare.\n"); 
    return; 
} 
printf("\n===== Suppliers =====\n");
 for (int i = 0; i < supplierCount; i++) { 
     printf("%d. %s - %s\n", i + 1,
     suppliers[i].supplierID, suppliers[i].supplierName);
 } 
 printf("\nEnter number of first supplier: ");
 scanf("%d", &first); 
 printf("Enter number of second supplier: "); 
 scanf("%d", &second); getchar(); 
 
 if (first < 1 || first > supplierCount || second < 1 || second > supplierCount) { 
    printf("Invalid supplier number.\n"); 
    return; 
    }

    first--; 
    second--; 
    
    printf("\n===== Supplier Comparison =====\n"); 
    
    printf("\nSupplier 1\n"); 
    printf("ID : %s\n", suppliers[first].supplierID); 
    printf("Name : %s\n", suppliers[first].supplierName); 
    printf("Email : %s\n", suppliers[first].Email); 
    printf("Phone : %s\n", suppliers[first].supplierPhone); 
    printf("Town : %s\n", suppliers[first].Town); 
    
    printf("\nSupplier 2\n"); 
    printf("ID : %s\n", suppliers[second].supplierID); 
    printf("Name : %s\n", suppliers[second].supplierName); 
    printf("Email : %s\n", suppliers[second].Email); 
    printf("Phone : %s\n", suppliers[second].supplierPhone); 
    printf("Town : %s\n", suppliers[second].Town); 

}

 