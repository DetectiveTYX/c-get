#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
/*函数功能：进行adm文件写入
* 函数入口参数：主程序结构体数组adm，共写入行数num
* 函数返回值：int值，0为失败，1为成功
*/
int writeFileADM(ADM adm[], int num)//写入adm文件
{
	FILE* fp;
	fp = fopen("C:\\Users\\18357\\Desktop\\程序实践\\new\\Project1\\ADM.txt", "w+");
	for (int i = 0; i < num; i++)
	{
		fprintf(fp, "%d %s\n", adm[i].ID, adm[i].code);
	}
	printf("\t\t\t\t管理员数据已覆盖。\n");
	fclose(fp);
	return 1;
}
/*函数功能：进行pkg文件写入
* 函数入口参数：主程序结构体数组pkg，共写入行数num
* 函数返回值：int值，0为失败，1为成功
*/
int writeFilePKG(PKG pkg[], int num)//写入pkg文件
{
	FILE* fp;
	fp = fopen("C:\\Users\\18357\\Desktop\\程序实践\\new\\Project1\\PKG.txt", "w+");
	for (int i = 0; i < num; i++)
	{
		fprintf(fp, "%d %s %.2lf %.2lf %.2lf %.2lf %d\n", pkg[i].ID, pkg[i].name, pkg[i].money, pkg[i].mobileData4G, pkg[i].mobileData5G, pkg[i].callDuration, pkg[i].Broadband);
	}
	printf("\t\t\t\t套餐数据已覆盖。\n");
	fclose(fp);
	return 1;
}
/*函数功能：进行user文件写入
* 函数入口参数：主程序结构体数组user，共写入行数num
* 函数返回值：int值，0为失败，1为成功
*/
int writeFileUSER(USER user[], int num)//写入user文件
{
	FILE* fp;
	fp = fopen("C:\\Users\\18357\\Desktop\\程序实践\\new\\Project1\\USER.txt", "w+");
	for (int i = 0; i < num; i++)
	{
		fprintf(fp, "%d %s %s %.2lf %d\n", user[i].ID, user[i].code, user[i].name, user[i].balance, user[i].packageID);
	}
	printf("\t\t\t\t用户数据已覆盖。\n");
	fclose(fp);
	return 1;
}

/*函数功能：进行adm文件读出
* 函数入口参数：主程序结构体数组adm
* 函数返回值：int值，0为失败，1为成功
*/
int readFileADM(ADM adm[])//读出adm文件
{
	FILE* fp;
	fp = fopen("C:\\Users\\18357\\Desktop\\程序实践\\new\\Project1\\ADM.txt", "r");
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
/*函数功能：进行pkg文件读出
* 函数入口参数：主程序结构体数组pkg
* 函数返回值：int值，0为失败，1为成功
*/
int readFilePKG(PKG pkg[])//读出pkg文件
{
	FILE* fp;
	fp = fopen("C:\\Users\\18357\\Desktop\\程序实践\\new\\Project1\\PKG.txt", "r");
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
/*函数功能：进行user文件读出
* 函数入口参数：主程序结构体数组user
* 函数返回值：int值，0为失败，1为成功
*/
int readFileUSER(USER user[])//读出user文件
{
	FILE* fp;
	fp = fopen("C:\\Users\\18357\\Desktop\\程序实践\\new\\Project1\\USER.txt", "r");
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

///*函数功能：判断ADM中有多少非0数
//* 函数入口参数：ADM
//* 函数返回值：int型，有多少非0数
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
///*函数功能：判断PKG中有多少非0数
//* 函数入口参数：PKG
//* 函数返回值：int型，有多少非0数
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
///*函数功能：判断USER中有多少非0数
//* 函数入口参数：USER
//* 函数返回值：int型，有多少非0数
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