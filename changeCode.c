#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "struct.h"
/*函数功能： 修改密码
函数入口参数：num，用户编号，用于修改对应密码，由登录系统输入
返回值：0表示退出，1表示修改成功
*/
int changeCodeUSER(USER user[], int num)
{
	char a[100] = { 0 };  //记录输入的旧密码
	char newcode1[100] = { 0 };  //修改的新密码
	char newcode2[100] = { 0 };  //确认修改的新密码
	do
	{
		printf("\t\t\t\t请输入旧密码:\n");
		printf("\t\t\t\t输入退出可退出\n");
		printf("\t\t\t\t");
		scanf("%s", &a);
		if (!strcmp(a, "退出"))//判断是否输入“退出”
		{
			printf("\t\t\t\t已退出\n");
			return 0;//退出此内容
		}
		if (!strcmp(a, user[num].code))  //输入的密码与旧密码比对
		{
			do
			{
				printf("\t\t\t\t请输入新密码\n");
				printf("\t\t\t\t");
				scanf(" %s", &newcode1);
				printf("\t\t\t\t请重新输入，确认新密码\n");
				printf("\t\t\t\t");
				scanf(" %s", &newcode2);
				if (!strcmp(newcode1, newcode2))  //确认两次密码一致
				{
					printf("\t\t\t\t密码修改成功，请登录！\n");
					strcpy(user[num].code, newcode1);  //修改密码
					return 1; //修改成功
				}
				else
				{
					printf("\t\t\t\t两次密码不匹配！请重新输入！\n");
				}
			} while (1);
		}
		else
		{
			printf("\t\t\t\t密码输入错误，请重新输入！\n");
		}
	} while (1);
}
/*函数功能： 修改密码
函数入口参数：num，管理员编号，用于修改对应密码，由登录系统输入
返回值：0表示退出，1表示修改成功
*/
int changeCodeADM(ADM adm[], int num)
{
	char a[100] = { 0 };  //记录输入的旧密码
	char newcode1[100] = { 0 };  //修改的新密码
	char newcode2[100] = { 0 };  //确认修改的新密码
	do
	{
		printf("\t\t\t\t请输入旧密码:\n");
		printf("\t\t\t\t输入退出可退出\n");
		printf("\t\t\t\t");
		scanf("%s", &a);
		if (!strcmp(a, "退出"))//判断是否输入“退出”
		{
			printf("\t\t\t\t已退出\n");
			return 0;//退出此内容
		}
		if (!strcmp(a, adm[num].code))  //输入的密码与旧密码比对
		{
			do
			{
				printf("\t\t\t\t请输入新密码\n");
				printf("\t\t\t\t");
				scanf(" %s", &newcode1);
				printf("\t\t\t\t请重新输入，确认新密码\n");
				printf("\t\t\t\t");
				scanf(" %s", &newcode2);
				if (!strcmp(newcode1, newcode2))  //确认两次密码一致
				{
					printf("\t\t\t\t密码修改成功，请登录！\n");
					strcpy(adm[num].code, newcode1);  //修改密码
					return 1; //修改成功
				}
				else
				{
					printf("\t\t\t\t两次密码不匹配！请重新输入！\n");
				}
			} while (1);
		}
		else
		{
			printf("\t\t\t\t密码输入错误，请重新输入！\n");
		}
	} while (1);
}