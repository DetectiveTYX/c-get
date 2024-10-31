#include "struct.h"
#ifndef USERMANAGE
#define USERMANAGE
void userSearch(USER a[]);
int userAdd(USER a[], PKG b[]);
void userChange(USER a[], PKG b[]);
int userDelete(USER a[]);
int USERManageSelect(USER user[], PKG pkg[]);//套餐管理总选择界面
#endif