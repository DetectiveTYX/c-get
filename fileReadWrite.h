#include "struct.h"
#ifndef FILEREADWRITE
#define FILEREADWRITE
int writeFileADM(ADM adm[], int num);//����adm�ļ�д��
int writeFilePKG(PKG pkg[], int num);//����pkg�ļ�д��
int writeFileUSER(USER user[], int num);//д��user�ļ�
int readFileADM(ADM adm[]);//����adm�ļ�
int readFilePKG(PKG pkg[]);//����pkg�ļ�
int readFileUSER(USER user[]);//����user�ļ�
//int numADM(ADM adm[]);//�ж�ADM���ж��ٷ�0��
//int numPKG(PKG pkg[]);//�ж�PKG���ж��ٷ�0��
//int numUSER(USER user[]);//�ж�USER���ж��ٷ�0��
#endif
