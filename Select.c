#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "struct.h"
#include"usersMatchPackage.h"
#include"usersModifyBalance.h"
#include"changeCode.h"
#include"printMessage.h"



/*�������ܣ�����Ա��¼����
������ڲ�����
��������ֵ��int�ͣ�4Ϊ�ײ���Ϣ����5Ϊ�û���Ϣ����3�޸����룬4Ϊ�˳���0�˵�
*/
int ADMSelect(ADM adm[], int* admNumPointer)//����Ա����
{
	char a[100] = { 0 };//���ڼ�¼���������ַ�
	int b;//�����ж��Ƿ������һ��
	do {
		b = 1;
		printf("\t\t\t\t");
		scanf("%s", &a);//����
		if (atoi(a) == 1 || atoi(a) == 2|| atoi(a)==3|| atoi(a) == 4)
		{

			if (atoi(a) == 1)
			{
				printf("\t\t\t\t�����ײ���Ϣ����ϵͳ��\n");
				return 4;
			}
			if (atoi(a) == 2)
			{
				printf("\t\t\t\t�����û���Ϣ����ϵͳ\n");
				return 5;
			}
			if (atoi(a) == 3)
			{
				printf("\t\t\t\t�����޸�����\n");
				changeCodeADM(adm,*admNumPointer );
				return 2;
			}
			if (atoi(a) == 4)
			{
				printf("\t\t\t\t�˺����˳�\n");
				return 0;
			}
			b = 0;
		}
		else
		{
			printf("\t\t\t\t������������������\n");
		}
	} while (b);
}

/*�������ܣ��û���¼����
������ڲ�����
��������ֵ��int�ͣ�6Ϊ��������ѯϵͳ��5Ϊ�û���Ϣ����6Ϊ�˳���0�Ų˵���1Ϊ�û�����
*/
int USERSelect(USER user[], PKG pkg[],int* userNumPointer)//�û�����
{
	char a[100] = { 0 };//���ڼ�¼���������ַ�
	int b;//�����ж��Ƿ������һ��
	char x[100] = { 0 };

	do {
		b = 1;
		printf("\t\t\t\t");
		scanf("%s", &a);//����
		if (atoi(a) == 1 || atoi(a) == 2 || atoi(a) == 3 || atoi(a) == 4 || atoi(a) == 5 || atoi(a) == 6)
		{

			if (atoi(a) == 1)
			{
				printf("\t\t\t\t���ĸ�����ϢΪ��\n");
				queryPersonal(user, userNumPointer);
				printf("\t\t\t\t��������������ɲ�ѯ�������ϼ��˵�:\n");
                scanf("%s", x);
				return 1;//�����û����˵�
			}
			if (atoi(a) == 2)
			{
				printf("\t\t\t\t���ڲ�ѯ�ײ���Ϣ \n");
				return queryPackage(user, pkg, userNumPointer);//1ʱ�����û����˵���3ʱ�û���ʼ�޸��ײ���Ϣ
			}
			if (atoi(a) == 3)
			{
				printf("\t\t\t\t�����޸��ײ� \n");
				matchPackage(user, pkg);
				return 1;//�����û����˵�
			}
			if (atoi(a) == 4)
			{
				printf("\t\t\t\t���ڲ�ѯ���(��ֵ���) \n");
				return 6;//��������ѯϵͳ
			}
			if (atoi(a) == 5)
			{
				printf("\t\t\t\t�����޸����� \n");
				changeCodeUSER(user, *userNumPointer);
				return 1;//�ص��û�����
			}
			if (atoi(a) == 6)
			{
				printf("\t\t\t\t�����˳��˺� \n");
				return 0;//�˳���0�Ų˵�
			}
			b = 0;
		}
		else
		{
			printf("\t\t\t\t������������������\n");
		}
	} while (b);
}