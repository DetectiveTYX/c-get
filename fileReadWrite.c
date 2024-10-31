#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
/*�������ܣ�����adm�ļ�д��
* ������ڲ�����������ṹ������adm����д������num
* ��������ֵ��intֵ��0Ϊʧ�ܣ�1Ϊ�ɹ�
*/
int writeFileADM(ADM adm[], int num)//д��adm�ļ�
{
	FILE* fp;
	fp = fopen("C:\\Users\\18357\\Desktop\\����ʵ��\\new\\Project1\\ADM.txt", "w+");
	for (int i = 0; i < num; i++)
	{
		fprintf(fp, "%d %s\n", adm[i].ID, adm[i].code);
	}
	printf("\t\t\t\t����Ա�����Ѹ��ǡ�\n");
	fclose(fp);
	return 1;
}
/*�������ܣ�����pkg�ļ�д��
* ������ڲ�����������ṹ������pkg����д������num
* ��������ֵ��intֵ��0Ϊʧ�ܣ�1Ϊ�ɹ�
*/
int writeFilePKG(PKG pkg[], int num)//д��pkg�ļ�
{
	FILE* fp;
	fp = fopen("C:\\Users\\18357\\Desktop\\����ʵ��\\new\\Project1\\PKG.txt", "w+");
	for (int i = 0; i < num; i++)
	{
		fprintf(fp, "%d %s %.2lf %.2lf %.2lf %.2lf %d\n", pkg[i].ID, pkg[i].name, pkg[i].money, pkg[i].mobileData4G, pkg[i].mobileData5G, pkg[i].callDuration, pkg[i].Broadband);
	}
	printf("\t\t\t\t�ײ������Ѹ��ǡ�\n");
	fclose(fp);
	return 1;
}
/*�������ܣ�����user�ļ�д��
* ������ڲ�����������ṹ������user����д������num
* ��������ֵ��intֵ��0Ϊʧ�ܣ�1Ϊ�ɹ�
*/
int writeFileUSER(USER user[], int num)//д��user�ļ�
{
	FILE* fp;
	fp = fopen("C:\\Users\\18357\\Desktop\\����ʵ��\\new\\Project1\\USER.txt", "w+");
	for (int i = 0; i < num; i++)
	{
		fprintf(fp, "%d %s %s %.2lf %d\n", user[i].ID, user[i].code, user[i].name, user[i].balance, user[i].packageID);
	}
	printf("\t\t\t\t�û������Ѹ��ǡ�\n");
	fclose(fp);
	return 1;
}

/*�������ܣ�����adm�ļ�����
* ������ڲ�����������ṹ������adm
* ��������ֵ��intֵ��0Ϊʧ�ܣ�1Ϊ�ɹ�
*/
int readFileADM(ADM adm[])//����adm�ļ�
{
	FILE* fp;
	fp = fopen("C:\\Users\\18357\\Desktop\\����ʵ��\\new\\Project1\\ADM.txt", "r");
	int flag = 0, file_row = 0, count = 0;
	char c[100];
	while (!feof(fp))
	{
		flag = fgetc(fp);
		if (flag == '\n')
			count++;
	}
	count += 1;
	rewind(fp);
	for (int i = 0; i <count; i++)
	{
		strcpy(c, "");
		fscanf(fp,"%s %s",c, adm[i].code);
		printf("\t\t\t\tc:%s,adm[i].code:%s\n",c, adm[i].code);
		adm[i].ID = atoi(c);
	}
	for (int i = 0; i < count; i++)
	{
		printf("\t\t\t\t%d %s\n", adm[i].ID, adm[i].code);
	}
	fclose(fp);

}
/*�������ܣ�����pkg�ļ�����
* ������ڲ�����������ṹ������pkg
* ��������ֵ��intֵ��0Ϊʧ�ܣ�1Ϊ�ɹ�
*/
int readFilePKG(PKG pkg[])//����pkg�ļ�
{
	FILE* fp;
	fp = fopen("C:\\Users\\18357\\Desktop\\����ʵ��\\new\\Project1\\PKG.txt", "r");
	int flag = 0, file_row = 0, count = 0;
	char c[100],d[100],e[100],f[100],g[100],h[100];
	while (!feof(fp))
	{
		flag = fgetc(fp);
		if (flag == '\n')
			count++;
	}
	count += 1;
	rewind(fp);
	for (int i = 0; i < count; i++)
	{
		strcpy(c, "");
		strcpy(d, "");
		strcpy(e, "");
		strcpy(f, "");
		strcpy(g, "");
		strcpy(h, "");
		fscanf(fp, "%s %s %s %s %s %s %s", c, pkg[i].name,d,e,f,g,h);
		pkg[i].ID = atoi(c);
		pkg[i].money = atof(d);
		pkg[i].mobileData4G = atof(e);
		pkg[i].mobileData5G = atof(f);
		pkg[i].callDuration= atof(g);
		pkg[i].Broadband = atoi(h);
		printf("\t\t\t\t%d %s %.2lf %.2lf %.2lf %.2lf %d\n", pkg[i].ID, pkg[i].name, pkg[i].money, pkg[i].mobileData4G, pkg[i].mobileData5G, pkg[i].callDuration, pkg[i].Broadband);
	}
	for (int i = 0; i < count; i++)
	{
		printf("\t\t\t\t%d %s %.2lf %.2lf %.2lf %.2lf %d\n", pkg[i].ID, pkg[i].name, pkg[i].money, pkg[i].mobileData4G, pkg[i].mobileData5G, pkg[i].callDuration, pkg[i].Broadband);

	}
	fclose(fp);

}
/*�������ܣ�����user�ļ�����
* ������ڲ�����������ṹ������user
* ��������ֵ��intֵ��0Ϊʧ�ܣ�1Ϊ�ɹ�
*/
int readFileUSER(USER user[])//����user�ļ�
{
	FILE* fp;
	fp = fopen("C:\\Users\\18357\\Desktop\\����ʵ��\\new\\Project1\\USER.txt", "r");
	int flag = 0, file_row = 0, count = 0;
	char c[100], d[100], e[100];
	while (!feof(fp))
	{
		flag = fgetc(fp);
		if (flag == '\n')
			count++;
	}
	count += 1;
	rewind(fp);
	for (int i = 0; i < count; i++)
	{
		strcpy(c, "");
		strcpy(d, "");
		strcpy(e, "");
		fscanf(fp, "%s %s %s %s %s", c, user[i].code, user[i].name, d, e);
		user[i].ID = atoi(c);
		user[i].balance = atof(d);
		user[i].packageID = atof(e);
		printf("\t\t\t\t%d %s %s %.2lf %d\n", user[i].ID, user[i].code, user[i].name, user[i].balance, user[i].packageID);

	}
	for (int i = 0; i < count; i++)
	{
		printf("\t\t\t\t%d %s %s %.2lf %d\n", user[i].ID, user[i].code, user[i].name, user[i].balance, user[i].packageID);

	}
	fclose(fp);
}

///*�������ܣ��ж�ADM���ж��ٷ�0��
//* ������ڲ�����ADM
//* ��������ֵ��int�ͣ��ж��ٷ�0��
//*/
//int numADM(ADM adm[])
//{
//	int count = 0;
//	for (int i = 0; i < 100; i++)
//	{
//		if (adm[i].ID!=0)
//		{
//			count++;
//		}
//	}
//	return count;
//}
///*�������ܣ��ж�PKG���ж��ٷ�0��
//* ������ڲ�����PKG
//* ��������ֵ��int�ͣ��ж��ٷ�0��
//*/
//int numPKG(PKG pkg[])
//{
//	int count = 0;
//	for (int i = 0; i < 100; i++)
//	{
//		if (pkg[i].ID != 0)
//		{
//			count++;
//		}
//	}
//	return count;
//}
///*�������ܣ��ж�USER���ж��ٷ�0��
//* ������ڲ�����USER
//* ��������ֵ��int�ͣ��ж��ٷ�0��
//*/
//int numUSER(USER user[])
//{
//	int count = 0;
//	for (int i = 0; i < 100; i++)
//	{
//		if (user[i].ID != 0)
//		{
//			count++;
//		}
//	}
//	return count;
//}