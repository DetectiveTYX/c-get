#include "struct.h"
#ifndef LOGIN
#define LOGIN
int adminLogIn(ADM adm[]);//管理员系统进行登录
int logIn(USER user[], ADM adm[],int* userNumPointer, int* admNumPointer);//登录开始功能
int selectUserAdmin();//判断登录管理员系统或者用户系统
int AccountInput();//输入账号
int admAccountToPassword(ADM adm[], int accountInput);//判断管理员账号是否正确
int PasswordInput(char* k);//输入密码
int admPasswordDetection(ADM adm[], char* admPasswordIuput, int i);//判断对应密码是否正确
int userLogIn(USER user[]);//用户系统进行登录
int userAccountToPassword(USER user[], int accountInput);//判断用户账号是否正确
int userPasswordDetection(USER user[], char* userPasswordIuput, int i);//判断对应密码是否正确
int judgeRegis();//是否进行注册
#endif 