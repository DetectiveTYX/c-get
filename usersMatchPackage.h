#include "struct.h"
#ifndef USERSMATCHPACKAGE
#define USERSMATCHPACKAGE
int matchPackage(USER user[], PKG pkg[], int* userNumPointer);//�û�ƥ���ײ���ں���
int getPKG(PKG* needPKG, int mustGet[]);//��ȡ�û��������ײ�
void getMust(int mustGet[], int num); //��ȡ�û����������Ƿ����
int comparePackage(PKG pkg[], PKG needPKG, int mustGet[], float pkgCompare[]);
void sort(float* a, int length, int* b);
int withoutZeroNum(float pkgCompare[]);
int putSuggest(USER user[], PKG pkg[], PKG needPKG, int mustGet[], float pkgCompare[], int* userNumPointer);

#endif 