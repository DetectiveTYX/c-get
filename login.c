#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
#include"fileReadWrite.h"
/*函数功能：管理员系统进行登录
函数入口参数：主程序结构体数组adm
函数返回值：int型，i为进入的管理员编号，-1为返回选择界面
*/
int adminLogIn(ADM adm[])
{
	int i = 0;
	int admAccountNum = 0;
	char admPassword[100] = { 0 };
	int a = 0;
	int uadmNum = 0;

	do
	{
		a = AccountInput();
		if (!a)
		{
			return -1;
		}
		i = admAccountToPassword(adm, a);//此i是第i个管理员账号

	} while (!(i + 1));//i为-1是循环输入
	int b, c;
	char k[100] = "";
	do
	{
		b = PasswordInput(k);//0为退出至账号，1为输入完成
		if (b)
		{
			c = admPasswordDetection(adm, k, i);//0为正确，1为密码错误
		}

	} while (b && c);//有一项为0即退出


	if (!b)
	{
		return adminLogIn(adm);//重新到本条开始输入账号
	}

	return i;//进入管理员账号
}

/*函数功能：输入密码但是界面只显示*
* 函数入口参数：无
* 函数返回值：一个存放数组的地址
*/
char* codeInput()
{
	int i;
	int count = 0;//记录密码字符的输入个数
	static char a[20] = { 0 };//定义一个长度为20的静态字符数组用来存放密码，并初始化为空,静态字符数组可以使其存放的数据的生命周期贯穿整个程序运行周期
	for (i = 0; i < 20; i++)
	{
		a[i] = getch();//输入密码但是不在屏幕上显示
		if (a[i] != '\r'&&a[i]!='\0')//判断输入字符是否为空格，若不是空格则在屏幕上显示*
		{
			putchar('*');
			count++;
		}
		else//若输入字符为空格，则结束循环
			break;
	}
	for (count; count < 20; count++)
	{
		a[count] = '\0';//静态数组中没有修改的密码字符为空
	}
	return a;//返回存放密码的数组
}

/*函数功能：登录开始功能
* 函数入口参数：主程序结构体数组user，adm
* 函数返回值：int 类型，3为用户需要注册，1为用户登录成功，2为管理员登录成功,0为返回选择系统
*/
int logIn(USER user[], ADM adm[], int* userNumPointer, int* admNumPointer)
{
	int a = 0;
	switch (selectUserAdmin())
	{
	case 1:
		a = adminLogIn(user);
		if (a != -1)
		{
			*admNumPointer = a;//进入第a个账户，传递至指针
			a = 2;//主菜单进入管理员界面
		}

		if (a == -1)
		{
			a = 0;//主菜单进入选择界面
		}
		return a;//0为选择界面，2为管理员系统   
		break;

	case 2:
		a = userLogIn(user);
		if (a != -2 && a != -1)
		{
			*userNumPointer = a;//进入第a个账户，传递至指针
			a = 1;//主菜单进入用户界面
		}
		if (a == -2)
		{
			a = 3;//主菜单进入用户界面
		}
		if (a == -1)
		{
			a = 0;//主菜单进入用户界面
		}
		return a;//3为需要注册，0为退出至选择管理员或用户，1为用户登录成功
		break;
	}
}
/*函数功能：判断登录管理员系统或者用户系统
函数入口参数：无
函数返回值：int型，1为管理员，2为用户
*/
int selectUserAdmin()
{
	char a[100] = { 0 };//用于记录键盘输入字符
	int b;//用于判断是否进入下一步
	do {
		b = 1;
		//printf("请选择使用管理员或用户登录。管理员选择1，用户选择2。\n");//输入提示
		printf("\t\t\t\t"); 
		scanf("%s", &a);//输入
		if (atoi(a) == 1 || atoi(a) == 2)
		{

			if (atoi(a) == 1)
			{
				printf("\t\t\t\t正在登录管理员系统\n");
				return 1;
			}
			else
			{
				printf("\t\t\t\t正在登录用户系统\n");
				return 2;
			}
			b = 0;
		}
		else
		{
			printf("\t\t\t\t输入有误，请重新输入\n");
		}
	} while (b);
}

/*函数功能：输入账号
函数入口参数：无
函数返回值：int型，0退出至选择管理员或用户，其他数字为账号输出
*/
int AccountInput()
{

	char a[100] = { 0 };//用于记录键盘输入字符
	int b;//用于判断是否进入下一步
	char c;
	int d;//用于判断用户输入是否符合规则
	do {
		b = 1;
		d = 1;
		printf("\t\t\t\t请输入账号(输入“退出”可退出)\n");//输入提示
		printf("\t\t\t\t");
		scanf("%s", &a);//输入
		if (!strcmp(a, "退出"))//判断是否输入“退出”
		{
			printf("\t\t\t\t已退出\n");
			return 0;//退出至选择管理员或用户
		}
		else
		{
			for (int i = 0; i < 100; i++)//判断是否输入均为数字
			{
				if (a[i] == '\0')//此时已经把所有有效判断完成，退出判断
				{
					break;
				}
				if (a[i] < '0' || a[i] > '9')//具体判断不符合规则方式
				{
					printf("\t\t\t\t输入有误，请重新输入\n");
					d = 0;//用户输入不符合规则
					break;
				}
			}
			if (d)//用户输入符合规则
			{
				return atof(a);
				b = 0;//进入下一步
			}
		}
	} while (b);//账号输入完成
}
/*函数功能：判断管理员账号是否正确
函数入口参数：主程序结构体数组adm，输入待判断的账号
函数返回值：int型，-1为未注册，其余数字为账号数组中第几个数
*/
int admAccountToPassword(ADM adm[], int accountInput)
{
	int i = 0;
	for (; i < 100; i++)
	{
		if (accountInput == adm[i].ID)
		{
			return i;
		}
	}
	if (i == 100)
	{
		printf("\t\t\t\t该账号无效\n");
		return -1;
	}
}
/*函数功能：输入密码
函数入口参数：k，可传递出密码
函数返回值：int型，0退出，1为输入完成。k传递密码输出
*/
int PasswordInput(char* k)
{

	char a[100] = { 0 };//用于记录键盘输入字符
	int b;//用于判断是否进入下一步
	char c;
	int d;//用于判断用户输入是否符合规则
	b = 1;
	d = 1;
	printf("\t\t\t\t请输入密码(输入“退出”可退出)\n");//输入提示
	printf("\t\t\t\t");
	//scanf("%s", &a);//输入

	strcpy(a, codeInput());
	printf("a:%s\n", a);


	if (!strcmp(&a, "退出"))//判断是否输入“退出”
	{
		printf("\t\t\t\t已退出\n");
		return 0;//退出此内容
	}
	strcpy(k, a);
	return 1;//密码输入完成
}
/*函数功能：判断对应密码是否正确
函数入口参数：结构体adm，字符串指针传递输入的密码，第i个账户进行判断
函数返回值：int型，1为错误，0为正确
*/
int admPasswordDetection(ADM adm[], char* admPasswordIuput, int i)
{
	if (!strcmp(admPasswordIuput, adm[i].code))//判断是否输入“注册”

	{
		printf("\t\t\t\t密码正确，登录成功\n");
		return 0;//登录成功
	}
	printf("\t\t\t\t密码错误\n");
	return 1;//密码错误

}





/*函数功能：用户系统进行登录
函数入口参数：主程序结构体数组user
函数返回值：int型，-2为需要注册，i为第i个一个用户账号，-1为退出至选择管理员或用户
*/
int userLogIn(USER user[])
{
	int i = 0;
	int uesrAccountNum = 0;
	char userPassword[100] = { 0 };
	int a = 0;
	int userNum = 0;
	do
	{
		a = AccountInput();
		if (!a)
		{
			return -1;//-1为退出至选择管理员或用户
		}
		i = userAccountToPassword(user, a);//此i是第i个用户账号
		if (i == -1)
		{
			printf("\t\t\t\t是否需要注册？\n");//询问是否需要注册
			if (judgeRegis())
			{
				return -2;//需要注册
			}
		}
	} while (!(i + 1));//i为-1是循环输入
	int b, c;
	char k[100] = "";
	do
	{
		b = PasswordInput(k);//0为退出至账号，1为输入完成
		if (b)
		{
			c = userPasswordDetection(user, k, i);//0为正确，1为密码错误
		}
	} while (b && c);//有一项为0即退出
	if (!b)
	{
		return userLogIn(user);//重新到本条开始输入账号
	}
	return i;
}

/*函数功能：判断用户账号是否正确
函数入口参数：主程序结构体数组user，输入待判断的账号
函数返回值：int型，0为未注册，其余数字为账号数组中第几个数
*/
int userAccountToPassword(USER user[], int accountInput)
{
	int i = 0;
	for (; i < 100; i++)
	{
		if (accountInput == user[i].ID)
		{
			return i;
		}
	}
	if (i == 100)
	{
		printf("\t\t\t\t账号未注册\n");
		return -1;
	}
}

/*函数功能：判断对应密码是否正确
函数入口参数：结构体user，字符串指针传递输入的密码，第i个账户进行判断
函数返回值：int型，1为错误，0为正确
*/
int userPasswordDetection(USER user[], char* userPasswordIuput, int i)
{
	if (!strcmp(userPasswordIuput, user[i].code))//判断是否输入“注册”
	{
		printf("\t\t\t\t密码正确，登录成功\n");
		return 0;//登录成功
	}
	printf("\t\t\t\t密码错误\n");
	return 1;//密码错误

}
/*函数功能：判断是否注册
函数入口参数：
函数返回值：int型，1为注册，0为不注册
*/
int judgeRegis()//是否进行注册
{
	char a[100] = { 0 };//用于记录键盘输入字符
	int b;//用于判断是否进入下一步
	do {
		b = 1;
		printf("\t\t\t\t是否进行注册？注册请输入1，不注册请输入2\n");//输入提示
		printf("\t\t\t\t");
		scanf("%s", &a);//输入
		if (atoi(a) == 1 || atoi(a) == 2)
		{

			if (atoi(a) == 1)
			{
				printf("\t\t\t\t注册\n");
				return 1;
			}
			else
			{
				printf("\t\t\t\t不注册\n");
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


