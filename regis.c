#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "struct.h"

/*�������ܣ��û�ע�Ṧ��
* ������ڲ�����������ṹ������user
* ��������ֵ��ֱ���޸�������ṹ�����飬int���ͣ�0Ϊ�ɹ��˳����û���¼���棬�ɹ�ע����û�ȡ������
*/
int regis(USER user[])
{
	USER b;
	int i, j, d, f, k;
	char UserCode[20];
	char a[100] = { 0 };//���ڼ�¼���������ַ�
	do
	{
		printf("\t\t\t\t��������׼��ע����˺�(���롰�˳������˳�)\n");
		printf("\t\t\t\t");
		scanf("%s", &a);
		f = 1;
		d = 1;
		k = 0;
		if (!strcmp(a, "�˳�"))//�ж��Ƿ����롰�˳���
		{
			printf("\t\t\t\t�ѷ����û���¼����\n");
			return 1;//�˳����û���¼ϵͳ
		}
		for (j = 0; j < 100; j++)//�ж��Ƿ������Ϊ����
		{
			if (a[j] == '\0')//��ʱ�Ѿ���������Ч�ж���ɣ��˳��ж�
			{
				break;
			}
			if (a[j] < '0' || a[j] > '9')//�����жϲ����Ϲ���ʽ
			{
				printf("\t\t\t\t������������������\n");
				printf("\t\t\t\t");
				scanf("%s", &a);
				d = 0;//�û����벻���Ϲ���
				break;
			}
		}
		b.ID = atoi(a);//b��ID��ʱ��ֵ
		if (d)//�û�������Ϲ���
		{
			for (i = 0; i < 100; i++)
			{
				if (b.ID == user[i].ID)//�ж��û����Ƿ������е��ظ�
				{
					printf("\t\t\t\t���û����Ѵ���\n");
					break;
				}
				if (user[i].ID==0)//�ж��û��������еĲ��ظ��Ҵ�ʱuser�Ѿ�Ϊ��
				{
					f = 0;//��������do whileѭ�� 
					k = i;//k��Ӧд����Ϣ��λ��
					user[i].ID = b.ID;
					break;
				}
			}
		}
	} while (f);
	printf("\t\t\t\t�������ǳƣ�\n");
	printf("\t\t\t\t");
	scanf("%s", &b.name);
	do
	{
		printf("\t\t\t\t����������\n");
		printf("\t\t\t\t");
		scanf(" %s", &b.code);
		printf("\t\t\t\t���������룬ȷ������\n");
		printf("\t\t\t\t");
		scanf(" %s", &UserCode);
		if (!strcmp(b.code, UserCode))
		{
			printf("\t\t\t\t�˺�ע��ɹ������¼��\n");
			strcpy(user[k].code, b.code);
			strcpy(user[k].name, b.name);
			return 0;//�˺�ע��ɹ�������0
		}
		else
		{
			printf("\t\t\t\t�������벻ƥ�䣡���������룡\n");
		}
	} while (1);
}