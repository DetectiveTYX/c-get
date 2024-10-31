#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
#include <math.h>
#include"fileReadWrite.h"

/*�������ܣ��û�ƥ���ײ���ں���
* ������ڲ�����������ṹ������user,pkg
* ��������ֵ��ֱ���޸�������ṹ������
*/
void matchPackage(USER user[], PKG pkg[])
{
	PKG needPKG = { 0,"",0,0,0,0,0 }, * a = &needPKG;//��ʼ�����������ṹ
	int mustGet[4] = { 0,0,0,0 };
	int b = getPKG(a, mustGet);//��ȡ�û������ṹ���Ƿ����,b=1ʱ��ȡ�ɹ�
	float pkgCompare[100] = { 0 };//��ȡÿһ��pkg��ռ��
	comparePackage(pkg, needPKG, mustGet, pkgCompare);
	putSuggest(pkg, needPKG, mustGet, pkgCompare);
}

/*�������ܣ���ȡ�û����������Ƿ����
* ������ڲ�����ͳ���Ƿ��������mustget���ڼ���num
* ��������ֵ��ֱ���޸�mustget����
*/
void getMust(int mustGet[], int num)//�Ƿ����
{
	char a[100] = { 0 };//���ڼ�¼���������ַ�
	int b;//�����ж��Ƿ������һ��
	int d;//�����ж��û������Ƿ���Ϲ���
	do {
		b = 1;
		d = 1;
		printf("\t\t\t\t��Ҫ���Ƿ����ﵽ������룬������1���粻���룬������2\n");//������ʾ
		printf("\t\t\t\t");
		scanf("%s", &a);//����
		if (atoi(a) == 1 || atoi(a) == 2)
		{
			mustGet[num] = atoi(a);
			if (atoi(a) == 1)
			{
				printf("\t\t\t\t��ѡ���˱���\n");
			}
			else
			{
				printf("\t\t\t\t��ѡ���˲�����\n");
			}
			b = 0;//������һ��
		}
		else
		{
			printf("\t\t\t\t������������������\n");
		}
	} while (b);
}
/*�������ܣ���ȡ�û��������ײ�
* ������ڲ����������ײ���ϸ�ݴ���pkg��ͳ���Ƿ��������mustget
* ��������ֵ��int�ͣ�0Ϊ�����ϼ��ײͣ�1Ϊ�ɹ��ռ���Ϣ��ֱ���޸�������ṹ������
*/
int getPKG(PKG* needPKG, int mustGet[])//��ȡ�û��������ײͣ�0Ϊ�����ϼ��ײͣ�1Ϊ�ɹ��ռ���Ϣ
{
	char a[100] = { 0 };//���ڼ�¼���������ַ�
	int b;//�����ж��Ƿ������һ��
	char c;
	int d;//�����ж��û������Ƿ���Ϲ���
	do {
		b = 1;
		d = 1;
		printf("\t\t\t\t��������ϣ���ļ۸񣺣����롰�˳������˳���\n");//������ʾ
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
				needPKG->money = atof(a);//��һ������
				printf("\t\t\t\tmoney��%f\n", needPKG->money);
				b = 0;//������һ��
			}
		}
	} while (b);//�ײͼ۸��������
	do {
		b = 1;
		d = 1;
		printf("\t\t\t\t��������ϣ����4G�����������롰�˳������˳���\n");//������ʾ
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
					printf("\t\t\t\t������������������");
					d = 0;//�û����벻���Ϲ���
					break;
				}
			}
			if (d)//�û�������Ϲ���
			{
				needPKG->mobileData4G = atof(a);//��һ������
				printf("\t\t\t\tmobileData4G��%f\n", needPKG->mobileData4G);
				b = 0;//������һ��
			}
		}
	} while (b);//4G�����������
	getMust(mustGet, 0);//��ȡ4G�Ƿ����
	do {
		b = 1;
		d = 1;
		printf("\t\t\t\t��������ϣ����5G�����������롰�˳������˳���\n");//������ʾ
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
					printf("\t\t\t\t������������������");
					d = 0;//�û����벻���Ϲ���
					break;
				}
			}
			if (d)//�û�������Ϲ���
			{
				needPKG->mobileData5G = atof(a);//��һ������
				printf("\t\t\t\tmobileData5G��%f\n", needPKG->mobileData5G);
				b = 0;//������һ��
			}
		}
	} while (b);//5G�����������
	getMust(mustGet, 1);//��ȡ5G�Ƿ����
	do {
		b = 1;
		d = 1;
		printf("\t\t\t\t��������ϣ����ͨ��ʱ���������롰�˳������˳���\n");//������ʾ
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
					printf("\t\t\t\t������������������");
					d = 0;//�û����벻���Ϲ���
					break;
				}
			}
			if (d)//�û�������Ϲ���
			{
				needPKG->callDuration = atof(a);//��һ������
				printf("\t\t\t\tcallDuration��%f\n", needPKG->callDuration);
				b = 0;//������һ��
			}
		}
	} while (b);//ͨ��ʱ���������
	getMust(mustGet, 2);//��ȡͨ��ʱ���Ƿ����
	do {
		b = 1;
		d = 1;
		printf("\t\t\t\t��������ϣ���Ŀ�����������롰�˳������˳���\n");//������ʾ
		printf("\t\t\t\t��ѡ�����100,300,500,1000\n");//������ʾ
		printf("\t\t\t\t");
		scanf("%s", &a);//����
		if (!strcmp(&a, "�˳�"))//�ж��Ƿ����롰�˳���
		{
			printf("\t\t\t\t���˳�");
			return 0;//�˳�������
		}
		else
		{
			if (atoi(a) == 100 || atoi(a) == 300 || atoi(a) == 500 || atoi(a) == 1000)
			{
				needPKG->Broadband = atoi(a);
				printf("\t\t\t\tBroadband��%d\n", needPKG->Broadband);
				b = 0;//������һ��
			}
			else
			{
				printf("\t\t\t\t������������������\n");
			}
		}
	} while (b);//��������������
	getMust(mustGet, 3);//��ȡͨ��ʱ���Ƿ����
	return 1;
}
/*�������ܣ��Ա��ײ���Ϣ���Ƚ��ṩ����
* ������ڲ�����������ṹ������pkg���û������ײ���Ϣ���û�ѡ���Ƿ���룬�ԱȽ������
* ��������ֵ��ֱ���޸�pkgCompare����
*/
int comparePackage(PKG pkg[], PKG needPKG,int mustGet[],float pkgCompare[])
{
	for (int i = 0; i < 100; i++)
	{
		if (pkg[i].ID==0)
		{
			pkgCompare[i] = 0;

		}
		else
		{
			pkgCompare[i] = 0;
			if (!((needPKG.mobileData4G >= -0.00001) && (needPKG.mobileData4G <= 0.00001)))
			{
				pkgCompare[i] += fabsf(pkg[i].mobileData4G - needPKG.mobileData4G) / needPKG.mobileData4G * 0.25;

			}
			//printf("%d�ı�ֵ�ǣ�%lf\n", i, pkgCompare[i]);
			if (!((needPKG.mobileData5G >= -0.00001) && (needPKG.mobileData5G <= 0.00001)))
			{
				pkgCompare[i] += fabsf(pkg[i].mobileData5G - needPKG.mobileData5G) / needPKG.mobileData5G * 0.25;

			}
			//printf("%d�ı�ֵ�ǣ�%lf\n", i, pkgCompare[i]);
			if (!((needPKG.callDuration >= -0.00001) && (needPKG.callDuration <= 0.00001)))
			{
				pkgCompare[i] += fabsf(pkg[i].callDuration - needPKG.callDuration) / needPKG.callDuration * 0.05;

			}
			//printf("%d�ı�ֵ�ǣ�%lf\n", i, pkgCompare[i]);
			
			if (!((needPKG.Broadband >= -0.00001) && (needPKG.Broadband <= 0.00001)))
			{
				pkgCompare[i] += abs(pkg[i].Broadband - needPKG.Broadband) / needPKG.Broadband * 0.2;

			}
			printf("\t\t\t\t%d�ı�ֵ�ǣ�%lf\n", i, pkgCompare[i]);
		}
	}
	printf("\t\t\t\tint=%d", withoutZeroNum(pkgCompare));
}
/*�������ܣ������������������һ�������¼ԭ˳��
* ������ڲ�������Ҫ��������飬�����������˳��
* ��������ֵ�������������˳��a,ԭ����˳��b
*/
void sort(float* a, int length, int* b)
{
	int i, j, t1, t;
	for (j = 0; j < length; j++)
		for (i = 0; i < length - 1 - j; i++)
			if (a[i] < a[i + 1])
			{
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;


				t1 = b[i];
				b[i] = b[i + 1];
				b[i + 1] = t1;
			}
}
/*�������ܣ��ж��������ж��ٷ�0����float���ͣ�
* ������ڲ�����float����
* ��������ֵ��int�ͣ�Ϊ�ж��ٷ�0��
*/
int withoutZeroNum(float pkgCompare[])
{
	//int size = sizeof(pkgCompare) / sizeof(pkgCompare[0]);
	int count = 0;
	for (int i = 0; i <100; i++)
	{
		if ((pkgCompare[i] >= -0.00001)&& (pkgCompare[i] <= 0.00001))
		{
			count++;
		}
	}
	return 100-count;
}
	
/*�������ܣ��жϵ�ǰ�ײ��Ƿ������û���������
* ������ڲ�����������pkg����ǰ�ǵ�num��pkg�����жϣ��û�����needpkg���û�������������mustget
* ��������ֵ��int�ͣ�0Ϊ����������1Ϊ��������
*/
int judgeOK(PKG pkg[], PKG needPKG, int mustGet[],int num)
{
	int a = 1;
	if (mustGet[0] == 1 && (pkg[num].mobileData4G < needPKG.mobileData4G))
	{
		a = 0;
	}	
	if (mustGet[1] == 1 && (pkg[num].mobileData5G < needPKG.mobileData5G))
	{
		a = 0;
	}
	if (mustGet[2] == 1 && (pkg[num].callDuration < needPKG.callDuration))
	{
		a = 0;
	}
	if (mustGet[3] == 1 && (pkg[num].Broadband < needPKG.Broadband))
	{
		a = 0;
	}
	return a;
}


int putSuggest(PKG pkg[], PKG needPKG, int mustGet[], float pkgCompare[])
{
	int b = withoutZeroNum(pkgCompare);
	int sortNum[100] = { 0 };
	int right[100] = { 0 };//����Ҫ��
	int recommend[100] = { 0 };//�Ƽ�����һ������Ҫ��
	int rightNum = 0;//���ϵ�����
	int recommendNum = 0;//�Ƽ�������

	for (int i = 0; i < 100; i++)
	{
		sortNum[i] = i;
	}
	sort(pkgCompare, withoutZeroNum(pkgCompare), sortNum);//�˲�֮��pkgcompare��������˳�����У�sortNum��Ӧ��Ӧ��pkg���
	
	for (int i = 0; i < b; i++)
	{
		if (judgeOK(pkg, needPKG, mustGet, i))
		{
			right[rightNum] = sortNum[i];
			rightNum += 1;
			printf("\t\t\t\t��%d����������\n", i);//��ʱ��i����ֱ�Ӷ�Ӧ������pkg
		}
		else
		{
			recommend[recommendNum]= sortNum[i];
			recommendNum += 1;
		}
		
	}
	if (!rightNum)
	{
		printf("\t\t\t\t��ʱû�з�����������ײ�Ŷ\n");

	}
	if (rightNum < 6)
	{
		printf("\t\t\t\t���Կ��������ײ�\n");
		for (int i = 0; i < 3; i++)
		{
			printf("\t\t\t\t��%d����������\n", recommend[i]);
		}

	}
	char x[100] = { 0 };
	printf("\t\t\t\t");
	scanf("%s", x);
}

