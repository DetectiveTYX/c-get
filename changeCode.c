#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "struct.h"
/*�������ܣ� �޸�����
������ڲ�����num���û���ţ������޸Ķ�Ӧ���룬�ɵ�¼ϵͳ����
����ֵ��0��ʾ�˳���1��ʾ�޸ĳɹ�
*/
int changeCodeUSER(USER user[], int num)
{
	char a[100] = { 0 };  //��¼����ľ�����
	char newcode1[100] = { 0 };  //�޸ĵ�������
	char newcode2[100] = { 0 };  //ȷ���޸ĵ�������
	do
	{
		printf("\t\t\t\t�����������:\n");
		printf("\t\t\t\t�����˳����˳�\n");
		printf("\t\t\t\t");
		scanf("%s", &a);
		if (!strcmp(a, "�˳�"))//�ж��Ƿ����롰�˳���
		{
			printf("\t\t\t\t���˳�\n");
			return 0;//�˳�������
		}
		if (!strcmp(a, user[num].code))  //����������������ȶ�
		{
			do
			{
				printf("\t\t\t\t������������\n");
				printf("\t\t\t\t");
				scanf(" %s", &newcode1);
				printf("\t\t\t\t���������룬ȷ��������\n");
				printf("\t\t\t\t");
				scanf(" %s", &newcode2);
				if (!strcmp(newcode1, newcode2))  //ȷ����������һ��
				{
					printf("\t\t\t\t�����޸ĳɹ������¼��\n");
					strcpy(user[num].code, newcode1);  //�޸�����
					return 1; //�޸ĳɹ�
				}
				else
				{
					printf("\t\t\t\t�������벻ƥ�䣡���������룡\n");
				}
			} while (1);
		}
		else
		{
			printf("\t\t\t\t��������������������룡\n");
		}
	} while (1);
}
/*�������ܣ� �޸�����
������ڲ�����num������Ա��ţ������޸Ķ�Ӧ���룬�ɵ�¼ϵͳ����
����ֵ��0��ʾ�˳���1��ʾ�޸ĳɹ�
*/
int changeCodeADM(ADM adm[], int num)
{
	char a[100] = { 0 };  //��¼����ľ�����
	char newcode1[100] = { 0 };  //�޸ĵ�������
	char newcode2[100] = { 0 };  //ȷ���޸ĵ�������
	do
	{
		printf("\t\t\t\t�����������:\n");
		printf("\t\t\t\t�����˳����˳�\n");
		printf("\t\t\t\t");
		scanf("%s", &a);
		if (!strcmp(a, "�˳�"))//�ж��Ƿ����롰�˳���
		{
			printf("\t\t\t\t���˳�\n");
			return 0;//�˳�������
		}
		if (!strcmp(a, adm[num].code))  //����������������ȶ�
		{
			do
			{
				printf("\t\t\t\t������������\n");
				printf("\t\t\t\t");
				scanf(" %s", &newcode1);
				printf("\t\t\t\t���������룬ȷ��������\n");
				printf("\t\t\t\t");
				scanf(" %s", &newcode2);
				if (!strcmp(newcode1, newcode2))  //ȷ����������һ��
				{
					printf("\t\t\t\t�����޸ĳɹ������¼��\n");
					strcpy(adm[num].code, newcode1);  //�޸�����
					return 1; //�޸ĳɹ�
				}
				else
				{
					printf("\t\t\t\t�������벻ƥ�䣡���������룡\n");
				}
			} while (1);
		}
		else
		{
			printf("\t\t\t\t��������������������룡\n");
		}
	} while (1);
}