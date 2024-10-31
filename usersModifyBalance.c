#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
/*函数功能：查询余额整体开始功能
* 函数入口参数：主程序结构体数组user，当前查询用户序号num
* 函数返回值：直接修改主程序结构体数组,int类型，1为回到用户主菜单
*/
int modifyBalance(USER user[], int num)
{
	char x[100] = { 0 };
	int a = 1;
	do
	{
		printf("\t\t\t\t您正在查询余额\n");
		getBanlance(user, num);

		if (getRecharge())
		{
            a=howMuch();
			if (a)
			{
				user[num].balance += a;
				printf("\t\t\t\t您现在拥有余额为%.2lf\n", user[num].balance);
				printf("\t\t\t\t输入任何信息返回用户界面\n");
				printf("\t\t\t\t");
				scanf("%s", x);
				return 1;
			}

		}
	} while (!a);//a为0时重复
	

}
/*函数功能：获取用户当前余额
* 函数入口参数：主程序结构体数组user，当前查询用户序号num
* 函数返回值：int型，1为成功查询；直接修改主程序结构体数组
*/
int getBanlance(USER user[], int num) //获取用户当前余额
{
	printf("\t\t\t\t您拥有的余额是%.2f\n", user[num].balance);
	return 1;
}
/*函数功能：获取用户是否进行充值
* 函数入口参数：无
* 函数返回值：int型，1为进行充值，0为不进行
*/
int getRecharge()//是否进行充值
{
	char a[100] = { 0 };//用于记录键盘输入字符
	int b;//用于判断是否进入下一步
	do {
		b = 1;
		printf("\t\t\t\t是否进行充值？充值请输入1，退出请输入2\n");//输入提示
		printf("\t\t\t\t");
		scanf("%s", &a);//输入
		if (atoi(a) == 1 || atoi(a) == 2)
		{

			if (atoi(a) == 1)
			{
				printf("\t\t\t\t进行充值\n");
				return 1;
			}
			else
			{
				printf("\t\t\t\t已退出\n");
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
/*函数功能：收集用户充值价格
* 函数入口参数：无
* 函数返回值：int型，0为退出，其他数字值为具体充值价格
*/
int howMuch()//收集用户充值价格
{
	char a[100] = { 0 };//用于记录键盘输入字符
	int b;//用于判断是否进入下一步
	char c;
	int d;//用于判断用户输入是否符合规则
	do {
		b = 1;
		d = 1;
		printf("\t\t\t\t请输入您充值的价格：（输入“退出”可退出）\n");//输入提示
		printf("\t\t\t\t");
		scanf("%s", &a);//输入
		if (!strcmp(&a, "退出"))//判断是否输入“退出”
		{
			printf("\t\t\t\t已退出");
			return 0;//退出此内容
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
				printf("\t\t\t\t您充值的金额为：%f\n", atof(a));
				return atof(a);
				b = 0;//进入下一步
			}
		}
	} while (b);//充值价格输入完成
}