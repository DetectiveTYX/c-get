#include "struct.h"
#ifndef USERSMATCHPACKAGE
#define USERSMATCHPACKAGE
void matchPackage(USER user[], PKG pkg[]);//�û�ƥ���ײ���ں���
int getPKG(PKG* needPKG, int mustGet[]);//��ȡ�û��������ײ�
void getMust(int mustGet[], int num); //��ȡ�û����������Ƿ����
int comparePackage(PKG pkg[], PKG needPKG, int mustGet[], float pkgCompare[]);
void sort(int* a, int length, int* b);
int withoutZeroNum(float pkgCompare[]);
int putSuggest(PKG pkg[], PKG needPKG, int mustGet[], float pkgCompare[]);
#endif 