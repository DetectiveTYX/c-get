#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "struct.h"

/*函数功能：用户注册功能
* 函数入口参数：主程序结构体数组user
* 函数返回值：直接修改主程序结构体数组，int类型，0为成功退出至用户登录界面，成功注册或用户取消均可
*/
int regis(USER user[])
{
	USER b;
	int i, j, d, f, k;
	char UserCode[20];
	char a[100] = { 0 };//用于记录键盘输入字符
	do
	{
		printf("\t\t\t\t请输入你准备注册的账号(输入“退出”可退出)\n");
		printf("\t\t\t\t");
		scanf("%s", &a);
		f = 1;
		d = 1;
		k = 0;
		if (!strcmp(a, "退出"))//判断是否输入“退出”
		{
			printf("\t\t\t\t已返回用户登录界面\n");
			return 1;//退出至用户登录系统
		}
		for (j = 0; j < 100; j++)//判断是否输入均为数字
		{
			if (a[j] == '\0')//此时已经把所有有效判断完成，退出判断
			{
				break;
			}
			if (a[j] < '0' || a[j] > '9')//具体判断不符合规则方式
			{
				printf("\t\t\t\t输入有误，请重新输入\n");
				printf("\t\t\t\t");
				scanf("%s", &a);
				d = 0;//用户输入不符合规则
				break;
			}
		}
		b.ID = atoi(a);//b的ID临时赋值
		if (d)//用户输入符合规则
		{
			for (i = 0; i < 100; i++)
			{
				if (b.ID == user[i].ID)//判断用户名是否与已有的重复
				{
					printf("\t\t\t\t该用户名已存在\n");
					break;
				}
				if (user[i].ID==0)//判断用户名与已有的不重复且此时user已经为空
				{
					f = 0;//跳出整个do while循环 
					k = i;//k是应写入信息的位置
					user[i].ID = b.ID;
					break;
				}
			}
		}
	} while (f);
	printf("\t\t\t\t请输入昵称：\n");
	printf("\t\t\t\t");
	scanf("%s", &b.name);
	do
	{
		printf("\t\t\t\t请输入密码\n");
		printf("\t\t\t\t");
		scanf(" %s", &b.code);
		printf("\t\t\t\t请重新输入，确认密码\n");
		printf("\t\t\t\t");
		scanf(" %s", &UserCode);
		if (!strcmp(b.code, UserCode))
		{
			printf("\t\t\t\t账号注册成功，请登录！\n");
			strcpy(user[k].code, b.code);
			strcpy(user[k].name, b.name);
			return 0;//账号注册成功，返回0
		}
		else
		{
			printf("\t\t\t\t两次密码不匹配！请重新输入！\n");
		}
	} while (1);
}