#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "struct.h"
#include"usersMatchPackage.h"
#include"usersModifyBalance.h"
#include"changeCode.h"
#include"printMessage.h"



/*函数功能：管理员登录界面
函数入口参数：
函数返回值：int型，4为套餐信息管理，5为用户信息管理，3修改密码，4为退出到0菜单
*/
int ADMSelect(ADM adm[], int* admNumPointer)//管理员界面
{
	char a[100] = { 0 };//用于记录键盘输入字符
	int b;//用于判断是否进入下一步
	do {
		b = 1;
		printf("\t\t\t\t");
		scanf("%s", &a);//输入
		if (atoi(a) == 1 || atoi(a) == 2|| atoi(a)==3|| atoi(a) == 4)
		{

			if (atoi(a) == 1)
			{
				printf("\t\t\t\t进入套餐信息管理系统：\n");
				return 4;
			}
			if (atoi(a) == 2)
			{
				printf("\t\t\t\t进入用户信息管理系统\n");
				return 5;
			}
			if (atoi(a) == 3)
			{
				printf("\t\t\t\t正在修改密码\n");
				changeCodeADM(adm,*admNumPointer );
				return 2;
			}
			if (atoi(a) == 4)
			{
				printf("\t\t\t\t账号已退出\n");
				return 0;
			}
			b = 0;
		}
		else
		{
			printf("\t\t\t\t输入有误，请重新输入\n");
		}
	} while (b);
}

/*函数功能：用户登录界面
函数入口参数：
函数返回值：int型，6为进入余额查询系统，5为用户信息管理，6为退出至0号菜单，1为用户界面
*/
int USERSelect(USER user[], PKG pkg[],int* userNumPointer)//用户界面
{
	char a[100] = { 0 };//用于记录键盘输入字符
	int b;//用于判断是否进入下一步
	char x[100] = { 0 };

	do {
		b = 1;
		printf("\t\t\t\t");
		scanf("%s", &a);//输入
		if (atoi(a) == 1 || atoi(a) == 2 || atoi(a) == 3 || atoi(a) == 4 || atoi(a) == 5 || atoi(a) == 6)
		{

			if (atoi(a) == 1)
			{
				printf("\t\t\t\t您的个人信息为：\n");
				queryPersonal(user, userNumPointer);
				printf("\t\t\t\t输入任意内容完成查询，返回上级菜单:\n");
                scanf("%s", x);
				return 1;//返回用户主菜单
			}
			if (atoi(a) == 2)
			{
				printf("\t\t\t\t正在查询套餐信息 \n");
				return queryPackage(user, pkg, userNumPointer);//1时返回用户主菜单，3时用户开始修改套餐信息
			}
			if (atoi(a) == 3)
			{
				printf("\t\t\t\t正在修改套餐 \n");
				matchPackage(user, pkg);
				return 1;//返回用户主菜单
			}
			if (atoi(a) == 4)
			{
				printf("\t\t\t\t正在查询余额(充值入口) \n");
				return 6;//进入余额查询系统
			}
			if (atoi(a) == 5)
			{
				printf("\t\t\t\t正在修改密码 \n");
				changeCodeUSER(user, *userNumPointer);
				return 1;//回到用户界面
			}
			if (atoi(a) == 6)
			{
				printf("\t\t\t\t正在退出账号 \n");
				return 0;//退出至0号菜单
			}
			b = 0;
		}
		else
		{
			printf("\t\t\t\t输入有误，请重新输入\n");
		}
	} while (b);
}