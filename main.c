#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
#include "usersModifyBalance.h"
#include "login.h"
#include"fileReadWrite.h"
#include"regis.h"
#include"changeCode.h"
#include"usersMatchPackage.h"
#include"packageManage.h"
#include"userManage.h"
#include"Select.h"
#include"printMessage.h"

void printPrompt(int num, USER user[], ADM adm[], PKG pkg[]);//
int actionPrompt(int num, USER user[], ADM adm[], PKG pkg[], int* userNumPointer,int*admNumPointer);//该函数返回值会赋值给num

int main()
{
	ADM adm[100] = { 0};
	PKG pkg[100] = { 0};
	USER user[100] = { 0};
	//int userNum = 0;
	//PKG needPKG = { 0,"0",0,0,0,0,0 };
	PKG needPKG = { 0,"0",0,0,50,200,1000 };
	int mustget[4] = { 0, 1, 0, 1 };
	float pkgCompare[100] = { 0 };
	int USERNUM = 0,*userNumPointer=&USERNUM;
	int ADMNUM = 0, *admNumPointer = &ADMNUM;
	int actionNum = 0;

	readFilePKG(pkg); 
	readFileADM(adm);
	readFileUSER(user);

	//comparePackage(pkg, needPKG, mustget,pkgCompare);
	//putSuggest(pkg, needPKG, mustget, pkgCompare);
	while (1)
	{	
		printPrompt(actionNum,user,adm,pkg);
		actionNum=actionPrompt(actionNum,user,adm,pkg, userNumPointer,admNumPointer);
	}



	//packageAdd(pkg,16);
	return 0;
}

void printPrompt(int num, USER user[], ADM adm[], PKG pkg[])
{
	switch (num)
	{
	case -1:
		system("cls");
		break;
	case 0:
		system("cls");
		printf("\n\n\n\n\t\t\t\t-----------------------------------");
		printf("\n\t\t\t\t|   欢迎电信移动客户端        ！  |");
		printf("\n\t\t\t\t-----------------------------------");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|        1.管理员登录             |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|        2.用户登录               |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t-----------------------------------");
		printf("\n\n\n\t\t\t\t  请选择使用管理员或用户登录。\n\t\t\t\t  管理员选择1\n\t\t\t\t  用户选择2\n");//输入提示
		break;
	case 1:
		system("cls");
		printf("\n\n\n\n\t\t\t\t--------------------------------------");
		printf("\n\t\t\t\t|          欢迎进入用户界面！        |");
		printf("\n\t\t\t\t--------------------------------------");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          1.查询个人信息            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          2.查询套餐信息            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          3.修改套餐                |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          4.查询余额(充值入口)      |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          5.修改密码                |");
		printf("\n\t\t\t\t|                                    |");		
		printf("\n\t\t\t\t|          6.退出账号                |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t--------------------------------------");
		printf("\n\n\n\t\t\t\t\t  请选择需要进行的操作。\n\t\t\t\t\t  查询个人信息：1\n\t\t\t\t\t  查询套餐信息：2\n");//输入提示
		printf("\t\t\t\t\t  修改套餐：3\n\t\t\t\t\t  查询余额(充值入口)：4\n");//输入提示
		printf("\t\t\t\t\t  修改密码：5\n\t\t\t\t\t退出账号\n");//输入提示
		break;
	case 2:
		system("cls");
		printf("正在进入管理员账号");
		printf("\n\n\n\n\t\t\t\t-----------------------------------");
		printf("\n\t\t\t\t|       欢迎进入管理员界面！      |");
		printf("\n\t\t\t\t-----------------------------------");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|       1.进入套餐信息管理        |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|       2.进入用户信息管理        |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|       3.修改密码                |");		
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|       4.退出账号                |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t-----------------------------------");
		printf("\n\n\n\t\t\t\t  请选择需要进入的信息管理。\n\t\t\t\t  套餐信息管理：1\n\t\t\t\t  用户信息管理：2");//输入提示
		printf("\n\t\t\t\t  修改密码：3\n\t\t\t\t  退出账号：4\n");//输入提示

		break;
	case 3:
		printf("欢迎来到注册界面！\n");
		break;
	case 4:
		system("cls");
		printf("\n\n\n\n\t\t\t\t--------------------------------------");
		printf("\n\t\t\t\t|      欢迎进入套餐信息管理界面！    |");
		printf("\n\t\t\t\t--------------------------------------");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          1.查询套餐信息            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          2.更改套餐信息            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          3.增加套餐信息            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          4.删除套餐信息            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          5.返回管理员界面          |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t--------------------------------------");
		printf("\n\n\n\t\t\t\t\t  请选择需要进行的操作。\n\t\t\t\t\t  查询套餐信息：1\n\t\t\t\t\t  更改套餐信息：2\n");//输入提示
		printf("\t\t\t\t\t  增加套餐信息：3\n\t\t\t\t\t  删除套餐信息：4\n");//输入提示
		printf("\t\t\t\t\t  返回管理员界面：5 \n");//输入提示
		break;
	case 5:
		system("cls");
		printf("\n\n\n\n\t\t\t\t--------------------------------------");
		printf("\n\t\t\t\t|      欢迎进入用户信息管理界面！    |");
		printf("\n\t\t\t\t--------------------------------------");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          1.查询用户信息            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          2.更改用户信息            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          3.增加用户信息            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          4.删除用户信息            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          5.返回管理员界面          |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t--------------------------------------");
		printf("\n\n\n\t\t\t\t\t  请选择需要进行的操作。\n\t\t\t\t\t  查询用户信息：1\n\t\t\t\t\t  更改用户信息：2\n");//输入提示
		printf("\t\t\t\t\t  增加用户信息：3\n\t\t\t\t\t  删除用户信息：4\n");//输入提示
		printf("\t\t\t\t\t  返回管理员界面：5 \n");//输入提示
		break;
	case 6:
		system("cls");
		printf("\n\n\n\n\t\t\t\t--------------------------------------");
		printf("\n\t\t\t\t|      正在查询用户余额！    |");
		printf("\n\t\t\t\t--------------------------------------");
		//printf("\n\t\t\t\t|                                    |");
		//printf("\n\t\t\t\t|          1.查询用户信息            |");
		//printf("\n\t\t\t\t|                                    |");
		//printf("\n\t\t\t\t|          2.更改用户信息            |");
		//printf("\n\t\t\t\t|                                    |");
		//printf("\n\t\t\t\t|          3.增加用户信息            |");
		//printf("\n\t\t\t\t|                                    |");
		//printf("\n\t\t\t\t|          4.删除用户信息            |");
		//printf("\n\t\t\t\t|                                    |");
		//printf("\n\t\t\t\t|          5.返回管理员界面          |");
		//printf("\n\t\t\t\t|                                    |");
		//printf("\n\t\t\t\t--------------------------------------");
		//printf("\n\n\n\t\t\t\t\t  请选择需要进行的操作。\n\t\t\t\t\t  查询用户信息：1\n\t\t\t\t\t  更改用户信息：2\n");//输入提示
		//printf("\t\t\t\t\t  增加用户信息：3\n\t\t\t\t\t  删除用户信息：4\n");//输入提示
		//printf("\t\t\t\t\t  返回管理员界面：5 \n");//输入提示
		break;
	default:
		break;
	}
}

int actionPrompt(int num, USER user[], ADM adm[], PKG pkg[], int* userNumPointer, int* admNumPointer)//该函数返回值会赋值给num
{
	int a = 0;
	char x[100] = { 0 };
	switch (num)
	{
	case -1:
		return 0;
	case 0://选择管理员或用户界面
		a = logIn(user, adm, userNumPointer,admNumPointer);
		return a;
	case 1://进入用户界面
		return USERSelect(user, pkg, userNumPointer);
	case 2://进入管理员界面
		return ADMSelect(user,admNumPointer);
	case 3://进入注册界面
		return	regis(user);
	case 4://进入套餐信息管理系统
		return PKGManageSelect(pkg);
	case 5://进入用户信息管理系统
		return USERManageSelect(user, pkg);
	case 6://进入余额查询系统
		return modifyBalance(user, *userNumPointer);
	default:
		break;
	}

}






