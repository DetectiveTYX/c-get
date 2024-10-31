#include "struct.h"
#ifndef USERSMODIFYBALANCE
#define USERSMODIFYBALANCE
   int modifyBalance(USER user[], int num);       //用户查询或充值余额
   int getRecharge();                              //是否进行充值
   int howMuch();                                  //收集用户充值价格
   int getBanlance(USER user[], int num);          //获取用户当前余额
#endif 
