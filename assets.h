#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100 //maximum number of assets that we can store overall

//global variables used so that all functions can see the updated values of the asset arrays,
//eg assetcount increase after an asset has been added
extern char assetIDs[MAX_ASSETS][20];//size of array, and lenght of data allowd
extern char assetNames[MAX_ASSETS][50];
extern char assetTypes[MAX_ASSETS][30];
extern double assetValues[MAX_ASSETS];
extern char assetDepartments[MAX_ASSETS][30];
extern char assetCondition[MAX_ASSETS][20];
extern int assetCount;//tores the number of assets curently saved

//functions used in asset.c
void assetMenu(void);
void addAsset(void);
void displayAssets(void);
void searchAsset(void);

#endif