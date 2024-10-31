#include "struct.h"
#ifndef PACKAGEMANAGE
#define PACKAGEMANAGE
int numberJudge(char* a);//判断输入的字符串是否为数字类型
void packageSearch(PKG a[]);//套餐信息查询函数,n指代套餐总数 
int packageAdd(PKG a[]);//套餐信息增加函数，n指代套餐总数
int packageDelete( PKG a[]);//删除套餐信息函数
void packageChange(PKG a[]);//更改套餐信息
int PKGManageSelect(PKG pkg[]);//套餐管理总选择界面
#endif

