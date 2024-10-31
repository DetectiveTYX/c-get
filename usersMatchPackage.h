#include "struct.h"
#ifndef USERSMATCHPACKAGE
#define USERSMATCHPACKAGE
int matchPackage(USER user[], PKG pkg[], int* userNumPointer);//用户匹配套餐入口函数
int getPKG(PKG* needPKG, int mustGet[]);//获取用户的意向套餐
void getMust(int mustGet[], int num); //获取用户此项需求是否必须
int comparePackage(PKG pkg[], PKG needPKG, int mustGet[], float pkgCompare[]);
void sort(float* a, int length, int* b);
int withoutZeroNum(float pkgCompare[]);
int putSuggest(USER user[], PKG pkg[], PKG needPKG, int mustGet[], float pkgCompare[], int* userNumPointer);

#endif 