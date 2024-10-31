#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
#include <math.h>
#include"fileReadWrite.h"

/*函数功能：用户匹配套餐入口函数
* 函数入口参数：主程序结构体数组user,pkg
* 函数返回值：直接修改主程序结构体数组
*/
void matchPackage(USER user[], PKG pkg[])
{
	PKG needPKG = { 0,"",0,0,0,0,0 }, * a = &needPKG;//初始化需求流量结构
	int mustGet[4] = { 0,0,0,0 };
	int b = getPKG(a, mustGet);//获取用户流量结构和是否必须,b=1时获取成功
	float pkgCompare[100] = { 0 };//获取每一项pkg的占比
	comparePackage(pkg, needPKG, mustGet, pkgCompare);
	putSuggest(pkg, needPKG, mustGet, pkgCompare);
}

/*函数功能：获取用户此项需求是否必须
* 函数入口参数：统计是否必须数组mustget，第几项num
* 函数返回值：直接修改mustget数组
*/
void getMust(int mustGet[], int num)//是否必须
{
	char a[100] = { 0 };//用于记录键盘输入字符
	int b;//用于判断是否进入下一步
	int d;//用于判断用户输入是否符合规则
	do {
		b = 1;
		d = 1;
		printf("\t\t\t\t该要求是否必须达到？如必须，请输入1；如不必须，请输入2\n");//输入提示
		printf("\t\t\t\t");
		scanf("%s", &a);//输入
		if (atoi(a) == 1 || atoi(a) == 2)
		{
			mustGet[num] = atoi(a);
			if (atoi(a) == 1)
			{
				printf("\t\t\t\t您选择了必须\n");
			}
			else
			{
				printf("\t\t\t\t您选择了不必须\n");
			}
			b = 0;//进入下一步
		}
		else
		{
			printf("\t\t\t\t输入有误，请重新输入\n");
		}
	} while (b);
}
/*函数功能：获取用户的意向套餐
* 函数入口参数：需求套餐详细暂存体pkg，统计是否必须数组mustget
* 函数返回值：int型，0为返回上级套餐，1为成功收集信息；直接修改主程序结构体数组
*/
int getPKG(PKG* needPKG, int mustGet[])//获取用户的意向套餐，0为返回上级套餐，1为成功收集信息
{
	char a[100] = { 0 };//用于记录键盘输入字符
	int b;//用于判断是否进入下一步
	char c;
	int d;//用于判断用户输入是否符合规则
	do {
		b = 1;
		d = 1;
		printf("\t\t\t\t请输入您希望的价格：（输入“退出”可退出）\n");//输入提示
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
				needPKG->money = atof(a);//进一步操作
				printf("\t\t\t\tmoney：%f\n", needPKG->money);
				b = 0;//进入下一步
			}
		}
	} while (b);//套餐价格输入完成
	do {
		b = 1;
		d = 1;
		printf("\t\t\t\t请输入您希望的4G流量：（输入“退出”可退出）\n");//输入提示
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
					printf("\t\t\t\t输入有误，请重新输入");
					d = 0;//用户输入不符合规则
					break;
				}
			}
			if (d)//用户输入符合规则
			{
				needPKG->mobileData4G = atof(a);//进一步操作
				printf("\t\t\t\tmobileData4G：%f\n", needPKG->mobileData4G);
				b = 0;//进入下一步
			}
		}
	} while (b);//4G流量输入完成
	getMust(mustGet, 0);//获取4G是否必须
	do {
		b = 1;
		d = 1;
		printf("\t\t\t\t请输入您希望的5G流量：（输入“退出”可退出）\n");//输入提示
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
					printf("\t\t\t\t输入有误，请重新输入");
					d = 0;//用户输入不符合规则
					break;
				}
			}
			if (d)//用户输入符合规则
			{
				needPKG->mobileData5G = atof(a);//进一步操作
				printf("\t\t\t\tmobileData5G：%f\n", needPKG->mobileData5G);
				b = 0;//进入下一步
			}
		}
	} while (b);//5G流量输入完成
	getMust(mustGet, 1);//获取5G是否必须
	do {
		b = 1;
		d = 1;
		printf("\t\t\t\t请输入您希望的通话时长：（输入“退出”可退出）\n");//输入提示
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
					printf("\t\t\t\t输入有误，请重新输入");
					d = 0;//用户输入不符合规则
					break;
				}
			}
			if (d)//用户输入符合规则
			{
				needPKG->callDuration = atof(a);//进一步操作
				printf("\t\t\t\tcallDuration：%f\n", needPKG->callDuration);
				b = 0;//进入下一步
			}
		}
	} while (b);//通话时长输入完成
	getMust(mustGet, 2);//获取通话时长是否必须
	do {
		b = 1;
		d = 1;
		printf("\t\t\t\t请输入您希望的宽带带宽：（输入“退出”可退出）\n");//输入提示
		printf("\t\t\t\t可选择带宽：100,300,500,1000\n");//输入提示
		printf("\t\t\t\t");
		scanf("%s", &a);//输入
		if (!strcmp(&a, "退出"))//判断是否输入“退出”
		{
			printf("\t\t\t\t已退出");
			return 0;//退出此内容
		}
		else
		{
			if (atoi(a) == 100 || atoi(a) == 300 || atoi(a) == 500 || atoi(a) == 1000)
			{
				needPKG->Broadband = atoi(a);
				printf("\t\t\t\tBroadband：%d\n", needPKG->Broadband);
				b = 0;//进入下一步
			}
			else
			{
				printf("\t\t\t\t输入有误，请重新输入\n");
			}
		}
	} while (b);//宽带带宽输入完成
	getMust(mustGet, 3);//获取通话时长是否必须
	return 1;
}
/*函数功能：对比套餐信息，比较提供建议
* 函数入口参数：主程序结构体数组pkg，用户需求套餐信息，用户选择是否必须，对比结果数组
* 函数返回值：直接修改pkgCompare数组
*/
int comparePackage(PKG pkg[], PKG needPKG,int mustGet[],float pkgCompare[])
{
	for (int i = 0; i < 100; i++)
	{
		if (pkg[i].ID==0)
		{
			pkgCompare[i] = 0;

		}
		else
		{
			pkgCompare[i] = 0;
			if (!((needPKG.mobileData4G >= -0.00001) && (needPKG.mobileData4G <= 0.00001)))
			{
				pkgCompare[i] += fabsf(pkg[i].mobileData4G - needPKG.mobileData4G) / needPKG.mobileData4G * 0.25;

			}
			//printf("%d的比值是：%lf\n", i, pkgCompare[i]);
			if (!((needPKG.mobileData5G >= -0.00001) && (needPKG.mobileData5G <= 0.00001)))
			{
				pkgCompare[i] += fabsf(pkg[i].mobileData5G - needPKG.mobileData5G) / needPKG.mobileData5G * 0.25;

			}
			//printf("%d的比值是：%lf\n", i, pkgCompare[i]);
			if (!((needPKG.callDuration >= -0.00001) && (needPKG.callDuration <= 0.00001)))
			{
				pkgCompare[i] += fabsf(pkg[i].callDuration - needPKG.callDuration) / needPKG.callDuration * 0.05;

			}
			//printf("%d的比值是：%lf\n", i, pkgCompare[i]);
			
			if (!((needPKG.Broadband >= -0.00001) && (needPKG.Broadband <= 0.00001)))
			{
				pkgCompare[i] += abs(pkg[i].Broadband - needPKG.Broadband) / needPKG.Broadband * 0.2;

			}
			printf("\t\t\t\t%d的比值是：%lf\n", i, pkgCompare[i]);
		}
	}
	printf("\t\t\t\tint=%d", withoutZeroNum(pkgCompare));
}
/*函数功能：对数组进行排序，另返回一个数组记录原顺序
* 函数入口参数：需要排序的数组，排序后的数组的顺序
* 函数返回值：排序后的数组的顺序a,原数组顺序b
*/
void sort(float* a, int length, int* b)
{
	int i, j, t1, t;
	for (j = 0; j < length; j++)
		for (i = 0; i < length - 1 - j; i++)
			if (a[i] < a[i + 1])
			{
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;


				t1 = b[i];
				b[i] = b[i + 1];
				b[i + 1] = t1;
			}
}
/*函数功能：判断数组中有多少非0数（float类型）
* 函数入口参数：float数组
* 函数返回值：int型，为有多少非0数
*/
int withoutZeroNum(float pkgCompare[])
{
	//int size = sizeof(pkgCompare) / sizeof(pkgCompare[0]);
	int count = 0;
	for (int i = 0; i <100; i++)
	{
		if ((pkgCompare[i] >= -0.00001)&& (pkgCompare[i] <= 0.00001))
		{
			count++;
		}
	}
	return 100-count;
}
	
/*函数功能：判断当前套餐是否满足用户必须需求
* 函数入口参数：主程序pkg，当前是第num个pkg进行判断，用户需求needpkg，用户必须需求数组mustget
* 函数返回值：int型，0为不符合需求，1为符合需求
*/
int judgeOK(PKG pkg[], PKG needPKG, int mustGet[],int num)
{
	int a = 1;
	if (mustGet[0] == 1 && (pkg[num].mobileData4G < needPKG.mobileData4G))
	{
		a = 0;
	}	
	if (mustGet[1] == 1 && (pkg[num].mobileData5G < needPKG.mobileData5G))
	{
		a = 0;
	}
	if (mustGet[2] == 1 && (pkg[num].callDuration < needPKG.callDuration))
	{
		a = 0;
	}
	if (mustGet[3] == 1 && (pkg[num].Broadband < needPKG.Broadband))
	{
		a = 0;
	}
	return a;
}


int putSuggest(PKG pkg[], PKG needPKG, int mustGet[], float pkgCompare[])
{
	int b = withoutZeroNum(pkgCompare);
	int sortNum[100] = { 0 };
	int right[100] = { 0 };//符合要求
	int recommend[100] = { 0 };//推荐，不一定符合要求
	int rightNum = 0;//符合的数量
	int recommendNum = 0;//推荐的数量

	for (int i = 0; i < 100; i++)
	{
		sortNum[i] = i;
	}
	sort(pkgCompare, withoutZeroNum(pkgCompare), sortNum);//此步之后，pkgcompare按照最优顺序排列，sortNum对应相应的pkg序号
	
	for (int i = 0; i < b; i++)
	{
		if (judgeOK(pkg, needPKG, mustGet, i))
		{
			right[rightNum] = sortNum[i];
			rightNum += 1;
			printf("\t\t\t\t第%d条符合需求\n", i);//此时的i可以直接对应大程序的pkg
		}
		else
		{
			recommend[recommendNum]= sortNum[i];
			recommendNum += 1;
		}
		
	}
	if (!rightNum)
	{
		printf("\t\t\t\t暂时没有符合您需求的套餐哦\n");

	}
	if (rightNum < 6)
	{
		printf("\t\t\t\t可以考虑以下套餐\n");
		for (int i = 0; i < 3; i++)
		{
			printf("\t\t\t\t第%d条符合需求\n", recommend[i]);
		}

	}
	char x[100] = { 0 };
	printf("\t\t\t\t");
	scanf("%s", x);
}

