
#include <stdio.h>
#include <string.h>
#include "assets.h"

//global variables 
int assetCount = 0; 
char assetIDs[MAX_ASSETS][20];
char assetNames[MAX_ASSETS][50];
char assetTypes[MAX_ASSETS][30];
char assetDepartments[MAX_ASSETS][30];
char assetCondition[MAX_ASSETS][20];
double assetValues[MAX_ASSETS];


void addAsset(void) {
    if (assetCount >= MAX_ASSETS) {
        printf("Asset register is full. Cannot add more.\n");
        return;
    }
    else {

    int i = assetCount;

printf("Enter Asset ID  ");
    scanf("%s", assetIDs[i]);
    if (strlen(assetIDs[i]) < 5) {
        printf("asset ID must be at least 5 characters.\n");
        return;
    }
printf("Enter Asset Name: ");
    scanf(" %49[^\n]", assetNames[i]);
printf("Enter Asset Type (Vehicle , device ,furniture, Equipment, building): ");
    scanf(" %39[^\n]", assetTypes[i]);
printf("Enter Purchase Value (N$): ");
    scanf("%lf", &assetValues[i]);
    if (assetValues[i] < 0) {
    printf(" value cannot be negative.\n");
} else {
printf("Enter Department: ");
    scanf(" %29[^\n]", assetDepartments[i]);
printf("Enter Condition (Good Fair or Damaged): ");
    scanf("%s", assetCondition[i]);

assetCount++;
    printf("Asset added \n");
    }


        }
}

void displayAssets(void) {
    if (assetCount == 0) {
        printf("No assets found\n");
        return;
    }
    else {
        char heading[80] = "Municipal Asset Register";
    char ending[] = " All Records";
    strcat(heading, ending);
    printf("\n %s \n", heading);
    int i;
    for (i = 0; i < assetCount; i++) {
        printf("Asset ID:    %s\n", assetIDs[i]);
        printf("Name:        %s\n", assetNames[i]);
        printf("Type:        %s\n", assetTypes[i]);
        printf("Value:     N$%.2f\n", assetValues[i]);
        printf("Department:  %s\n", assetDepartments[i]);
        printf("Condition:   %s\n", assetCondition[i]);
        printf(".'.'.'.'.'.'\n");
    }

    printf("total number of assets: %d\n", assetCount);
        }
    }

void searchAsset(void) {
    if (assetCount == 0) {
        printf("No assets registered.\n");
    } else{
    char searchID[20];
    int found = 0;
    int i;
    printf("Enter Asset id you wish to find  ");
    scanf("%s", searchID);
for (i = 0; i < assetCount; i++) {
        if (strcmp(assetIDs[i], searchID) == 0) {
            printf("\n Asset Found !\n");
            printf("ID:          %s\n", assetIDs[i]);
            printf("Name:        %s\n", assetNames[i]);
            printf("Type:        %s\n", assetTypes[i]);
            printf("Value:       N$%.2f\n", assetValues[i]);
            printf("Department:  %s\n", assetDepartments[i]);
            printf("Condition:   %s\n", assetCondition[i]);
            found = 1;
        break;
        }

}
    if (found ==0) {
    printf("asset not found,check your id and try again.");
    }
    }
}

void assetMenu(void) {
    char choice;
    do {
        printf("\n welcome to asset management! \n");
        printf("1. Add Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search Asset by assetID\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice(1-4) ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': addAsset();     
             break;
            case '2': displayAssets(); 
            break;
            case '3': searchAsset();   
            break;
            case '4': printf("going back to the main menu \n"); 
            break;

            default:
             printf("Invalid choice. Enter between 1-4.\n");
        }
    } while (choice != '4');
}

