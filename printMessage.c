#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
#include"packageManage.h"
#define _CRT_SECURE_NO_WARNINGS

/*函数功能：用户查询个人信息
函数入口参数：user,当前用户编号指针
函数返回值：
*/
void queryPersonal(USER user[], PKG pkg[] ,int* userNumPointer)
{
    int usernum = *userNumPointer;
	int pkgnum = user[usernum].packageID;
    printf("\t\t\t\t用户：%4d \t\t用户账号：%d \t\t用户密码：%s\n", usernum+1, user[usernum].ID, user[usernum].code);
    printf("\t\t\t\t用户名：%s \t\t用户余额：%.2f元\t用户套餐编号：%d \n", user[usernum].name, user[usernum].balance, user[usernum].packageID);
	printf("\t\t\t\t您当前的套餐为：\n");
	printf("\t\t\t\t编号：%2d  套餐名：%s  套餐价格：%.2f 元\n", pkg[pkgnum].ID, pkg[pkgnum].name, pkg[pkgnum].money);
	printf("\t\t\t\t套餐4G流量：%.2f GB  套餐5G流量：%.2f GB\n", pkg[pkgnum].mobileData4G, pkg[pkgnum].mobileData5G);
	printf("\t\t\t\t套餐通话时长：%.2f min  宽带带宽：%d MB/S\n", pkg[pkgnum].callDuration, pkg[pkgnum].Broadband);
}
/*函数功能：用户查询套餐信息
函数入口参数：user,当前用户编号指针
函数返回值：int型，1返回用户主菜单，3进入修改套餐界面
*/
int queryPackage(USER user[],PKG pkg[],int* userNumPointer)
{
    int usernum = *userNumPointer;
	int pkgnum = user[usernum].packageID;
	char a[100] = { 0 };//用于记录键盘输入字符
	int b;//用于判断是否进入下一步
	char x[100] = { 0 };

	do {
		b = 1;
		printf("\t\t\t\t仅查询自己的套餐请输入1，希望查询所有套餐请输入2 \n");
		printf("\t\t\t\t");
		scanf("%s", &a);//输入
		if (atoi(a) == 2 || atoi(a) == 1)
		{
			b = 0;
			if (atoi(a) == 1)
			{
				printf("\t\t\t\t您当前的套餐为：\n");
				printf("\t\t\t\t编号：%2d  套餐名：%s  套餐价格：%.2f 元\n", pkg[pkgnum].ID, pkg[pkgnum].name, pkg[pkgnum].money);
				printf("\t\t\t\t套餐4G流量：%.2f GB  套餐5G流量：%.2f GB\n", pkg[pkgnum].mobileData4G, pkg[pkgnum].mobileData5G);
				printf("\t\t\t\t套餐通话时长：%.2f min  宽带带宽：%d MB/S\n", pkg[pkgnum].callDuration, pkg[pkgnum].Broadband);
				//printf("\t\t\t\t输入任意内容完成查询，返回上级菜单:\n");
				//scanf("%s", x);
				//return 1;//返回用户主菜单
			}
			if (atoi(a) == 2)
			{
				printf("\t\t\t\t以下为总套餐信息： \n");
				packageSearch(pkg);
				//return 1;
			}

		}
		else
		{
			printf("\t\t\t\t输入有误，请重新输入\n");
		}
	} while (b);//分两种情况进行查询套餐信息，已完成
	do {//以下代码询问用户是否希望更改当前享受套餐
		b = 1;
		printf("\t\t\t\t是否希望更改当前享受套餐？\n");
		printf("\t\t\t\t如需更改请输入1，不需要请输入2\n");
		printf("\t\t\t\t");
		scanf("%s", &a);//输入
		if (atoi(a) == 2 || atoi(a) == 1)
		{

			if (atoi(a) == 2)
			{
				return 1;//返回用户主菜单
			}
			if (atoi(a) == 1)
			{
				return 3;//进入修改套餐界面
			}

		}
		else
		{
			printf("\t\t\t\t输入有误，请重新输入\n");
		}
	} while (b);
}

