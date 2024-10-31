#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "struct.h"

/*函数功能：判断输入的字符串是否为数字类型
*函数入口参数：调用函数的输入字符串input
*函数返回值：若字符串中的每一个字符都是数字类型，返回1；若含有非数字类型的字符，返回0
*/
int numberJudge(char* a)
{
    int i;//遍历字符串的每一个字符
    int n;//存放字符串的长度
    n = strlen(a);//函数判断字符串的长度，并赋值给n
    for (i = 0; i < n; i++)
    {
        if (isdigit(a[i]) == 0&&(a[i]!='.'))//判断每一个字符是否为数字类型
        {
            printf("\t\t\t\t当前输入为无效值，请输入数字！\n");
            return 0;//如果存在非数字类型返回0
        }
    }
    return 1;//全部都为数字类型返回1
}
/*函数功能：查询套餐信息
*函数入口参数：主程序结构体数组pkg，套餐总数n
* 函数返回值：int型
*/
void packageSearch(PKG a[])//套餐信息查询函数,n指代套餐总数 
{
    int i;
    int n = 0;
    int s = 0;
    for (int k = 0; k < 100; k++)
    {
        if (a[k].ID)
        {
            n++;
        }
    }
    for (i = 0; i < n; i++)//遍历每一个套餐信息结构体
    {
        printf("\t\t\t\t编号：%2d  套餐名：%s  套餐价格：%.2f 元\n", a[i].ID, a[i].name, a[i].money);
        printf("\t\t\t\t套餐4G流量：%.2f GB  套餐5G流量：%.2f GB\n", a[i].mobileData4G, a[i].mobileData5G);
        printf("\t\t\t\t套餐通话时长：%.2f min  宽带带宽：%d MB/S\n", a[i].callDuration, a[i].Broadband);
    }

    
}

/*函数功能：对套餐信息进行增加
*函数入口参数：主程序结构体数组pkg，套餐总数
* 返回值：添加的套餐数量
*/
int packageAdd(PKG a[])//套餐信息增加函数，n指代套餐总数
{
    int i = 1;//辅助while循环
    int count = 0;//记录增加的套餐数量
    int judge;//与判断字符串数据函数配合进行判断
    char input[20] = { 0 };//暂存输入的数据
    int n = 0;

    do
    {
        n = 0;
        for (int k = 0; k < 100; k++)
        {
            if (a[k].ID)
            {
                n++;
            }
        }
        a[n].ID = n + 1;//按照顺序给增加的套餐编号
        printf("\t\t\t\t请输入增加的套餐名称：\n");
        printf("\t\t\t\t");
        scanf("%s", a[n].name);
        do
        {
            printf("\t\t\t\t请输入增加的套餐价格：\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//判断输入的套餐价格是否为数字类型，若不是重新输入
        a[n].money = atof(input);
        do
        {
            printf("\t\t\t\t请输入增加的套餐的4G流量的数量：\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//判断输入的4G流量的数量是否为数字类型，若不是重新输入
        a[n].mobileData4G = atof(input);
        do
        {
            printf("\t\t\t\t请输入增加的套餐的5G流量的数量：\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//判断输入的5G流量的数量是否为数字类型，若不是重新输入
        a[n].mobileData5G = atof(input);
        do
        {
            printf("\t\t\t\t请输入增加的套餐通话时长：\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//判断输入的套餐通话时长是否为数字类型，若不是重新输入
        a[n].callDuration = atof(input);
        do
        {
            printf("\t\t\t\t请输入增加的套餐宽带带宽：\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//判断输入的套餐宽带带宽是否为数字类型，若不是重新输入
        a[n].Broadband = atoi(input);
        n++;//套餐总数增加
        printf("\t\t\t\t已成功增加该套餐信息！\n");
        count++;//成功增加套餐后记录+1
        printf("\t\t\t\t输入数字0，继续套餐信息添加；输入其他任意数字，结束增加套餐信息： \n");
        printf("\t\t\t\t");
        scanf("%d", &i);
    } while (i == 0);//判断是否继续添加套餐信息
    return count;//返回已成功添加的套餐信息数量
}
/*函数功能：删除套餐信息
*函数入口参数：主程序暂存结构体数组temPKG，结构体数组pkg，套餐总数n
* 函数返回值：输出的套餐信息数量
*/
int packageDelete(PKG a[])//删除套餐信息函数,temPKG为临时指针暂存要删除的数据之后的结构体内容
{
    PKG* temPKG = { 0 };
    int i;//存放需要删除的套餐信息的编号
    int j;//辅助遍历套餐信息的编号
    int k;//辅助继续删除套餐信息的循环
    int count = 0;//记录删除的套餐数量
    int n = 0;
    do
    {
        printf("\t\t\t\t请输入需要删除的套餐编号：\n");
        printf("\t\t\t\t");
        scanf("%d", &i);
        for (int k = 0; k < 100; k++)
        {
            if (a[k].ID)
            {
                n++;
            }
        }
        if (i<1 || i>n)
        {
            printf("\t\t\t\t不存在该套餐信息编号，请重新输入！\n");
            continue;//不存在该套餐信息编号结束本次运行，重新开始循环
        }//判断是否存在该套餐信息
        for (j = 0;; j++)
        {
            if (i == a[j].ID)//在先有套餐信息寻找到该套餐信息
            {
                temPKG = &a[j+1];//temPKG为临时指针暂存要删除的数据之后的结构体内容
                for (j; j - 1 < n; j++, temPKG++)//通过for循环将后一个的套餐信息覆盖到当前套餐信息中
                {
                    a[j] = *temPKG;
                }
                count++;//每删除一个套餐信息记录一次
                n--;//套餐现有数量减少一个
                printf("\t\t\t\t已经将该套餐信息删除！\n");
                break;//结束遍历套餐信息的for循环
            }
            if (j >= n)//在现有的套餐中没有找到该套餐
            {
                printf("\t\t\t\t该编号的套餐已经被删除过了！\n");
                break;//结束遍历套餐信息的for循环
            }
        }
        printf("\t\t\t\t如果需要继续删除套餐信息请输入数字0，按任意数字键退出删除！\n");
        printf("\t\t\t\t");
        scanf("%d", &k);
    } while (k == 0);//判断是否需要继续删除套餐信息
    return count;//返回已删除的套餐数量，但是不影响存在过的套餐的数量
}
/*函数功能：更改套餐信息
*函数入口参数：主程序结构体数组pkg，套餐总数n
* 函数返回值：无返回值
*/
void packageChange(PKG a[])
{
    int i;//用来存储输入的套餐编号
    int j;//引入一个变量，辅助循环更改套餐信息
    int p;//用来辅助遍历套餐编号
    int judge;//辅助判断输入的数据是否为数字类型
    char input[20] = { 0 };//暂时存放输入的字符
    int n;
    do
    {
        n = 0;
        for (int k = 0; k < 100; k++)
        {
            if (a[k].ID)
            {
                n++;
            }
        }
        printf("\t\t\t\t请输入你要更改的套餐信息的编号：\n");
    reenter://goto函数的转移标识
        printf("\t\t\t\t");
        scanf("%d", &i);
        if (i<1 || i>n)
        {
            printf("\t\t\t\t不存在该套餐信息编号，请重新输入！\n");
            continue;//结束本次循环，重新进入while循环
        }//大致判断输入的套餐编号是否符合要求
        for (p = 0;; p++)//对套餐编号进行遍历
        {
            if (i == a[p].ID)//在现有套餐中找到该套餐
                break;//结束for循环，继续向下运行
            if (p >= n)//未在现有套餐中找到该套餐
            {
                printf("\t\t\t\t不存在该套餐信息编号，请重新输入！\n");
                goto reenter;//转移至标识处继续运行
            }
        }
        printf("\t\t\t\t请输入更改后的套餐名称：\n");
        printf("\t\t\t\t");
        scanf("%s", a[p].name);
        do
        {
            printf("\t\t\t\t请输入更改后的套餐价格：\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//判断输入的套餐价格是否为数字类型，若不是重新输入
        a[p].money = atof(input);//将字符型数据转为数字类型
        do
        {
            printf("\t\t\t\t请输入更改后的套餐的4G流量的数量：\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//判断输入的4G流量的数量是否为数字类型，若不是重新输入
        a[p].mobileData4G = atof(input);//将字符型数据转为数字类型
        do
        {
            printf("\t\t\t\t请输入更改后的套餐的5G流量的数量：\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//判断输入的5G流量的数量是否为数字类型，若不是重新输入
        a[p].mobileData5G = atof(input);//将字符型数据转为数字类型
        do
        {
            printf("\t\t\t\t请输入更改后的套餐通话时长：\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//判断输入的套餐通话时长是否为数字类型，若不是重新输入
        a[p].callDuration = atof(input);//将字符型数据转为数字类型
        do
        {
            printf("\t\t\t\t请输入更改后的套餐宽带带宽：\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//判断输入的套餐宽带带宽是否为数字类型，若不是重新输入
        a[p].Broadband = atoi(input);//将字符型数据转为数字类型
        printf("\t\t\t\t已成功更改该套餐信息！\n");
        printf("\t\t\t\t如果需要继续更改套餐信息请输入数字0，按任意数字键退出删除！\n");
        printf("\t\t\t\t");
        scanf("%d", &j);
    } while (j == 0);//判断是否需要更改套餐信息
}
/*函数功能：套餐管理总选择界面
函数入口参数：pkg
函数返回值：int型，4为套餐信息管理，2为管理员界面
*/
int PKGManageSelect(PKG pkg[])//套餐管理总选择界面
{
    char a[100] = { 0 };//用于记录键盘输入字符
    int b;//用于判断是否进入下一步
    char x[100] = { 0 };//无意义暂存
    do {
        b = 1;
        printf("\t\t\t\t");
        scanf("%s", &a);//输入
        if (atoi(a) == 1 || atoi(a) == 2 || atoi(a) == 3 || atoi(a) == 4 || atoi(a) == 5)
        {

            if (atoi(a) == 1)
            {
                int s = 0;
                printf("\t\t\t\t查询套餐信息：\n");
                packageSearch(pkg);
                printf("\t\t\t\t输入任意内容完成查询，返回上级菜单:\n");
                printf("\t\t\t\t");
                scanf("%s", x);
                return 4;//操作完成后返回4套餐信息管理界面
            }
            if (atoi(a) == 2)
            {
                printf("\t\t\t\t更改套餐信息:\n");
                packageSearch(pkg);
                packageChange(pkg);
                system("cls");
                packageSearch(pkg);
                printf("\t\t\t\t输入任意内容完成查询，返回上级菜单:\n");
                printf("\t\t\t\t");
                scanf("%s", x);
                return 4;//操作完成后返回4套餐信息管理界面
            }
            if (atoi(a) == 3)
            {
                printf("\t\t\t\t增加套餐信息:\n");
                packageSearch(pkg);
                packageAdd(pkg);
                system("cls");
                packageSearch(pkg);
                printf("\t\t\t\t输入任意内容完成查询，返回上级菜单:\n");
                printf("\t\t\t\t");
                scanf("%s", x);
                return 4;//操作完成后返回4套餐信息管理界面
            }
            if (atoi(a) == 4)
            {
                printf("\t\t\t\t删除套餐信息:\n");
                packageSearch(pkg);
                packageDelete(pkg);
                system("cls");
                packageSearch(pkg);
                printf("\t\t\t\t输入任意内容完成查询，返回上级菜单:\n");
                printf("\t\t\t\t");
                scanf("%s", x);
                return 4;//操作完成后返回4套餐信息管理界面
            }
            if (atoi(a) == 5)
            {
                printf("\t\t\t\t返回管理员界面:\n");
                return 2;//返回2管理员界面
            }
            b = 0;
        }
        else
        {
            printf("\t\t\t\t输入有误，请重新输入\n");
        }
    } while (b);
}