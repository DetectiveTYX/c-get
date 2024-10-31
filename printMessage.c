#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
#include"packageManage.h"
#define _CRT_SECURE_NO_WARNINGS

/*�������ܣ��û���ѯ������Ϣ
������ڲ�����user,��ǰ�û����ָ��
��������ֵ��
*/
void queryPersonal(USER user[], PKG pkg[] ,int* userNumPointer)
{
    int usernum = *userNumPointer;
	int pkgnum = user[usernum].packageID;
    printf("\t\t\t\t�û���%4d \t\t�û��˺ţ�%d \t\t�û����룺%s\n", usernum+1, user[usernum].ID, user[usernum].code);
    printf("\t\t\t\t�û�����%s \t\t�û���%.2fԪ\t�û��ײͱ�ţ�%d \n", user[usernum].name, user[usernum].balance, user[usernum].packageID);
	printf("\t\t\t\t����ǰ���ײ�Ϊ��\n");
	printf("\t\t\t\t��ţ�%2d  �ײ�����%s  �ײͼ۸�%.2f Ԫ\n", pkg[pkgnum].ID, pkg[pkgnum].name, pkg[pkgnum].money);
	printf("\t\t\t\t�ײ�4G������%.2f GB  �ײ�5G������%.2f GB\n", pkg[pkgnum].mobileData4G, pkg[pkgnum].mobileData5G);
	printf("\t\t\t\t�ײ�ͨ��ʱ����%.2f min  �������%d MB/S\n", pkg[pkgnum].callDuration, pkg[pkgnum].Broadband);
}
/*�������ܣ��û���ѯ�ײ���Ϣ
������ڲ�����user,��ǰ�û����ָ��
��������ֵ��int�ͣ�1�����û����˵���3�����޸��ײͽ���
*/
int queryPackage(USER user[],PKG pkg[],int* userNumPointer)
{
    int usernum = *userNumPointer;
	int pkgnum = user[usernum].packageID;
	char a[100] = { 0 };//���ڼ�¼���������ַ�
	int b;//�����ж��Ƿ������һ��
	char x[100] = { 0 };

	do {
		b = 1;
		printf("\t\t\t\t����ѯ�Լ����ײ�������1��ϣ����ѯ�����ײ�������2 \n");
		printf("\t\t\t\t");
		scanf("%s", &a);//����
		if (atoi(a) == 2 || atoi(a) == 1)
		{
			b = 0;
			if (atoi(a) == 1)
			{
				printf("\t\t\t\t����ǰ���ײ�Ϊ��\n");
				printf("\t\t\t\t��ţ�%2d  �ײ�����%s  �ײͼ۸�%.2f Ԫ\n", pkg[pkgnum].ID, pkg[pkgnum].name, pkg[pkgnum].money);
				printf("\t\t\t\t�ײ�4G������%.2f GB  �ײ�5G������%.2f GB\n", pkg[pkgnum].mobileData4G, pkg[pkgnum].mobileData5G);
				printf("\t\t\t\t�ײ�ͨ��ʱ����%.2f min  �������%d MB/S\n", pkg[pkgnum].callDuration, pkg[pkgnum].Broadband);
				//printf("\t\t\t\t��������������ɲ�ѯ�������ϼ��˵�:\n");
				//scanf("%s", x);
				//return 1;//�����û����˵�
			}
			if (atoi(a) == 2)
			{
				printf("\t\t\t\t����Ϊ���ײ���Ϣ�� \n");
				packageSearch(pkg);
				//return 1;
			}

		}
		else
		{
			printf("\t\t\t\t������������������\n");
		}
	} while (b);//������������в�ѯ�ײ���Ϣ�������
	do {//���´���ѯ���û��Ƿ�ϣ�����ĵ�ǰ�����ײ�
		b = 1;
		printf("\t\t\t\t�Ƿ�ϣ�����ĵ�ǰ�����ײͣ�\n");
		printf("\t\t\t\t�������������1������Ҫ������2\n");
		printf("\t\t\t\t");
		scanf("%s", &a);//����
		if (atoi(a) == 2 || atoi(a) == 1)
		{

			if (atoi(a) == 2)
			{
				return 1;//�����û����˵�
			}
			if (atoi(a) == 1)
			{
				return 3;//�����޸��ײͽ���
			}

		}
		else
		{
			printf("\t\t\t\t������������������\n");
		}
	} while (b);
}

