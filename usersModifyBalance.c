#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
/*�������ܣ���ѯ������忪ʼ����
* ������ڲ�����������ṹ������user����ǰ��ѯ�û����num
* ��������ֵ��ֱ���޸�������ṹ������,int���ͣ�1Ϊ�ص��û����˵�
*/
int modifyBalance(USER user[], int num)
{
	char x[100] = { 0 };
	int a = 1;
	do
	{
		printf("\t\t\t\t�����ڲ�ѯ���\n");
		getBanlance(user, num);

		if (getRecharge())
		{
            a=howMuch();
			if (a)
			{
				user[num].balance += a;
				printf("\t\t\t\t������ӵ�����Ϊ%.2lf\n", user[num].balance);
				printf("\t\t\t\t�����κ���Ϣ�����û�����\n");
				printf("\t\t\t\t");
				scanf("%s", x);
				return 1;
			}

		}
	} while (!a);//aΪ0ʱ�ظ�
	

}
/*�������ܣ���ȡ�û���ǰ���
* ������ڲ�����������ṹ������user����ǰ��ѯ�û����num
* ��������ֵ��int�ͣ�1Ϊ�ɹ���ѯ��ֱ���޸�������ṹ������
*/
int getBanlance(USER user[], int num) //��ȡ�û���ǰ���
{
	printf("\t\t\t\t��ӵ�е������%.2f\n", user[num].balance);
	return 1;
}
/*�������ܣ���ȡ�û��Ƿ���г�ֵ
* ������ڲ�������
* ��������ֵ��int�ͣ�1Ϊ���г�ֵ��0Ϊ������
*/
int getRecharge()//�Ƿ���г�ֵ
{
	char a[100] = { 0 };//���ڼ�¼���������ַ�
	int b;//�����ж��Ƿ������һ��
	do {
		b = 1;
		printf("\t\t\t\t�Ƿ���г�ֵ����ֵ������1���˳�������2\n");//������ʾ
		printf("\t\t\t\t");
		scanf("%s", &a);//����
		if (atoi(a) == 1 || atoi(a) == 2)
		{

			if (atoi(a) == 1)
			{
				printf("\t\t\t\t���г�ֵ\n");
				return 1;
			}
			else
			{
				printf("\t\t\t\t���˳�\n");
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
/*�������ܣ��ռ��û���ֵ�۸�
* ������ڲ�������
* ��������ֵ��int�ͣ�0Ϊ�˳�����������ֵΪ�����ֵ�۸�
*/
int howMuch()//�ռ��û���ֵ�۸�
{
	char a[100] = { 0 };//���ڼ�¼���������ַ�
	int b;//�����ж��Ƿ������һ��
	char c;
	int d;//�����ж��û������Ƿ���Ϲ���
	do {
		b = 1;
		d = 1;
		printf("\t\t\t\t����������ֵ�ļ۸񣺣����롰�˳������˳���\n");//������ʾ
		printf("\t\t\t\t");
		scanf("%s", &a);//����
		if (!strcmp(&a, "�˳�"))//�ж��Ƿ����롰�˳���
		{
			printf("\t\t\t\t���˳�");
			return 0;//�˳�������
		}
		else
		{
			for (int i = 0; i < 100; i++)//�ж��Ƿ������Ϊ����
			{
				if (a[i] == '\0')//��ʱ�Ѿ���������Ч�ж���ɣ��˳��ж�
				{
					break;
				}
				if (a[i] < '0' || a[i] > '9')//�����жϲ����Ϲ���ʽ
				{
					printf("\t\t\t\t������������������\n");
					d = 0;//�û����벻���Ϲ���
					break;
				}
			}
			if (d)//�û�������Ϲ���
			{
				printf("\t\t\t\t����ֵ�Ľ��Ϊ��%f\n", atof(a));
				return atof(a);
				b = 0;//������һ��
			}
		}
	} while (b);//��ֵ�۸��������
}