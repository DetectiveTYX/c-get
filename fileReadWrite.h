#include "struct.h"
#ifndef FILEREADWRITE
#define FILEREADWRITE
int writeFileADM(ADM adm[], int num);//进行adm文件写入
int writeFilePKG(PKG pkg[], int num);//进行pkg文件写入
int writeFileUSER(USER user[], int num);//写入user文件
int readFileADM(ADM adm[]);//读出adm文件
int readFilePKG(PKG pkg[]);//读出pkg文件
int readFileUSER(USER user[]);//读出user文件
//int numADM(ADM adm[]);//判断ADM中有多少非0数
//int numPKG(PKG pkg[]);//判断PKG中有多少非0数
//int numUSER(USER user[]);//判断USER中有多少非0数
#endif
