#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "struct.h"

/*函数功能：用户信息查询
*函数入口参数：主程序结构体user
*函数返回值：无返回值
*/
void userSearch(USER a[])//用户信息查询函数
{
    int i;
    int n = 0;//n指代用户数量
    for (int k = 0; k < 100; k++)
    {
        if (a[k].ID)
        {
            n++;
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("\t\t\t\t用户：%4d \t\t用户账号：%d \t\t用户密码：%s\n", i + 1, a[i].ID, a[i].code);
        printf("\t\t\t\t用户名：%s \t\t用户余额：%.2f元\t用户套餐编号：%d \n", a[i].name, a[i].balance, a[i].packageID);
        //printf("用户套餐编号：%d \n", a[i].packageID);
        //printf("\t   套餐4G流量：%8.2fGB\t套餐5G流量：%4.2fGB  \n", b[i].mobileData4G, b[i].mobileData5G );
        //printf("\t   套餐通话时长：%.2fmin\t套餐宽带带宽：%dMB/S\n", b[i].callDuration, b[i].Broadband);
    }
}
/*函数功能：用户信息增加
*函数入口参数：主程序结构体数组user，主程序结构体数组pkg
* 函数返回值：添加的用户信息的数量
*/
int userAdd(USER a[], PKG b[])
{
    int i;//存放需要增加的用户的套餐编号
    int j;//辅助用户信息继续增加的循环
    int p;//用来遍历套餐结构体中的编号
    int count = 0;//记录用户信息增加数量
    int n;//n指代用户的总数
    int m;//m指代套餐的总数
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
        printf("\t\t\t\t请输入您需要增加的用户的账号：\n");
        printf("\t\t\t\t");
        scanf("%d", &a[n].ID);
        printf("\t\t\t\t请输入您需要增加的用户的密码：\n");
        printf("\t\t\t\t");
        scanf("%s", a[n].code);
        printf("\t\t\t\t请输入您需要增加的用户的用户名：\n");
        printf("\t\t\t\t");
        scanf("%s", a[n].name);
        printf("\t\t\t\t请输入您需要增加的用户的余额：\n");
        printf("\t\t\t\t");
        scanf("%f", &a[n].balance);
        printf("\t\t\t\t请输入您需要增加的用户的套餐编号：\n");
        do
        {
        reenter://goto函数转移标识，进行重新输入套餐编号
            printf("\t\t\t\t");
            scanf("%d", &i);
            m = 0;
            for (int k = 0; k < 100; k++)
            {
                if (b[k].ID)
                {
                    m++;
                }
            }
            if (i<1 || i>m)
            {
                printf("\t\t\t\t不存在该优惠套餐，请重新输入套餐编号！\n");
                continue;//结束本次循环重新开始循环
            }//先大概确定套餐编号是否符合要求
            else
                break;
        } while (1);//通过while无限循环使得其能够输入大概符合的套餐编号
        for (p = 0;; p++)//for函数无限循环
        {
            if (i == b[p].ID)
            {
                a[n].packageID = i;
                printf("\t\t\t\t已完成该用户套餐信息的增加！\n");
                break;//套餐编号在已有的套餐信息中，结束for循环
            }
            if (p >= m)//在已有的套餐信息中未找到该套餐信息
            {
                printf("\t\t\t\t不存在该优惠套餐，请重新输入套餐编号！\n");
                goto reenter;//返回标识处重新进行循环
            }
        }
        count++;//此时已完成增加用户操作，增加的用户数量加一
        userSearch(a);
        printf("\t\t\t\t如需要继续增加用户信息请输入数字0，输入其他任意数字退出增加用户信息！\n");
        printf("\t\t\t\t");
        scanf("%d", &j);
    } while (j == 0);//判断是否继续增加用户信息
    return count;//向主函数返回增加的用户信息的数量
}
/*函数功能：用户信息更改
*函数入口参数：主程序结构体数组user，主程序结构体数组pkg
*函数返回值：无返回值
*/
void userChange(USER a[], PKG b[])//用户信息更改函数
{
    int i;//存放需要更改信息的用户的编号
    int j;//存放用户更改后的套餐编号
    int k;//辅助继续更改用户信息的循环
    int p;//用来遍历套餐结构体中的编号
    int n;//n指代用户的总数
    int m;//m指代套餐的总数
    do
    {
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
            printf("\t\t\t\t请输入需要更改的用户的编号：\n");
            printf("\t\t\t\t");
            scanf("%d", &i);
            if (i<1 || i>n)
            {
                printf("\t\t\t\t无效用户编号，请重新输入：\n");
            }
            else
                break;
        } while (1);//判断需要更改的用户是否存在，若存在则结束循环
        printf("\t\t\t\t请输入更改后的用户的账号：\n");
        printf("\t\t\t\t");
        scanf("%d", &a[i - 1].ID);//由于结构体地址从零开始，所以实际用户信息存在的位置为i-1
        printf("\t\t\t\t请输入更改后的用户的密码：\n");
        printf("\t\t\t\t");
        scanf("%s", a[i - 1].code);
        printf("\t\t\t\t请输入更改后的用户的用户名：\n");
        printf("\t\t\t\t");
        scanf("%s", a[i - 1].name);
        printf("\t\t\t\t请输入更改后的用户的余额：\n");
        printf("\t\t\t\t");
        scanf("%f", &a[i - 1].balance);
        printf("\t\t\t\t请输入更改后的用户的套餐编号：\n");
        do
        {
        reenter://goto函数返回标识
            printf("\t\t\t\t");
            scanf("%d", &j);
            m = 0;
            for (int k = 0; k < 100; k++)
            {
                if (b[k].ID)
                {
                    m++;
                }
            }
            if (j<1 || j>m)
            {
                printf("\t\t\t\t不存在该优惠套餐，请重新输入套餐编号！\n");
                continue;
            }//先大概判断更改后的套餐是否存在
            else
                break;
        } while (1);//通过while无限循环使得其能够输入存在的套餐编号
        for (p = 0;; p++)//通过for无限循环遍历套餐信息
        {
            if (j == b[p].ID)//更改后的套餐存在于已有的套餐中
            {
                a[i - 1].packageID = j;//更改套餐编号
                printf("\t\t\t\t已完成该用户套餐信息的更改！\n");
                break;//结束for循环
            }
            if (p >= m)//已有的套餐信息中没有该套餐
            {
                printf("\t\t\t\t不存在该优惠套餐，请重新输入套餐编号！\n");
                goto reenter;//返回标识处继续向下运行
            }
        }
        userSearch(a);
        printf("\t\t\t\t如需要继续更改用户信息请输入数字0，输入其他任意数字退出更改用户信息！\n");
        printf("\t\t\t\t");
        scanf("%d", &k);
    } while (k == 0);
}
/*函数功能：用户信息删除
*函数入口参数：主程序结构体数组user
* 函数返回值：删除的用户信息数量
*/
int userDelete(USER a[])//删除用户信息函数，temUSER暂存结构体数据 
{
    USER* temUSER = { 0 };
    int i;//存储需要删除的用户的编号
    int j;//辅助继续删除循环
    int count = 0;//记录删除的数据数量
    int n;//n指代当前用户信息数量
    do
    {
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
            printf("\t\t\t\t请输入需要删除的用户的编号：\n");
            printf("\t\t\t\t");
            scanf("%d", &i);
            if (i<1 || i>n)
            {
                printf("\t\t\t\t无效用户编号，请重新输入！\n");
            }
            else
                break;
        } while (1);//判断是否存在该用户
        temUSER = &a[i];//用暂存指针临时存放下一位用户的信息
        for (i; i - 1 < n; i++, temUSER++)//通过for循环用后一位用户的信息覆盖前一位用户的信息
        {
            a[i - 1] = *temUSER;
        }
        count++;//成功删除一位用户信息后记录一次
        printf("\t\t\t\t已成功删除该用户的信息！\n");
        userSearch(a);
        printf("\t\t\t\t如果需要继续删除用户信息请输入数字0，按任意数字键退出删除！\n");
        printf("\t\t\t\t");
        scanf("%d", &j);
    } while (j == 0);//判断是否继续删除用户信息
    return count;//返回删除的用户信息数量
}

/*函数功能：用户管理总选择界面
函数入口参数：pkg
函数返回值：int型，            4为套餐信息管理，2为管理员界面
*/
int USERManageSelect(USER user[],PKG pkg[])//套餐管理总选择界面
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
                printf("\t\t\t\t查询用户信息：\n");
                userSearch(user);
                //packageSearch(pkg);
                //printf("输入任意内容完成查询，返回上级菜单:\n");
                //scanf("%s", x);
                return 5;//操作完成后返回5用户信息管理界面
            }
            if (atoi(a) == 2)
            {
                printf("\t\t\t\t更改用户信息:\n");
                userSearch(user);
                userChange(user, pkg);
                //packageSearch(pkg);
                //packageChange(pkg);
                //system("cls");
                //packageSearch(pkg);
                //printf("输入任意内容完成查询，返回上级菜单:\n");
                //scanf("%s", x);
                return 5;//操作完成后返回5用户信息管理界面
            }
            if (atoi(a) == 3)
            {
                printf("\t\t\t\t增加用户信息:\n");
                userSearch(user);
                userAdd(user, pkg);
                //packageSearch(pkg);
                //packageAdd(pkg);
                //system("cls");
                //packageSearch(pkg);
                //printf("输入任意内容完成查询，返回上级菜单:\n");
                //scanf("%s", x);
                return 5;//操作完成后返回5用户信息管理界面
            }
            if (atoi(a) == 4)
            {
                printf("\t\t\t\t删除用户信息:\n");
                userSearch(user);
                userDelete(user);
                //packageSearch(pkg);
                //packageDelete(pkg);
                //system("cls");
                //packageSearch(pkg);
                //printf("输入任意内容完成查询，返回上级菜单:\n");
                //scanf("%s", x);
                return 5;//操作完成后返回5用户信息管理界面
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