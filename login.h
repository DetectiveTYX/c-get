#include "struct.h"
#ifndef LOGIN
#define LOGIN
int adminLogIn(ADM adm[]);//����Աϵͳ���е�¼
int logIn(USER user[], ADM adm[],int* userNumPointer, int* admNumPointer);//��¼��ʼ����
int selectUserAdmin();//�жϵ�¼����Աϵͳ�����û�ϵͳ
int AccountInput();//�����˺�
int admAccountToPassword(ADM adm[], int accountInput);//�жϹ���Ա�˺��Ƿ���ȷ
int PasswordInput(char* k);//��������
int admPasswordDetection(ADM adm[], char* admPasswordIuput, int i);//�ж϶�Ӧ�����Ƿ���ȷ
int userLogIn(USER user[]);//�û�ϵͳ���е�¼
int userAccountToPassword(USER user[], int accountInput);//�ж��û��˺��Ƿ���ȷ
int userPasswordDetection(USER user[], char* userPasswordIuput, int i);//�ж϶�Ӧ�����Ƿ���ȷ
int judgeRegis();//�Ƿ����ע��
#endif 