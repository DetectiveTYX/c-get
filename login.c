#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
#include"fileReadWrite.h"
/*�������ܣ�����Աϵͳ���е�¼
������ڲ�����������ṹ������adm
��������ֵ��int�ͣ�iΪ����Ĺ���Ա��ţ�-1Ϊ����ѡ�����
*/
int adminLogIn(ADM adm[])
{
	int i = 0;
	int admAccountNum = 0;
	char admPassword[100] = { 0 };
	int a = 0;
	int uadmNum = 0;

	do
	{
		a = AccountInput();
		if (!a)
		{
			return -1;
		}
		i = admAccountToPassword(adm, a);//��i�ǵ�i������Ա�˺�

	} while (!(i + 1));//iΪ-1��ѭ������
	int b, c;
	char k[100] = "";
	do
	{
		b = PasswordInput(k);//0Ϊ�˳����˺ţ�1Ϊ�������
		if (b)
		{
			c = admPasswordDetection(adm, k, i);//0Ϊ��ȷ��1Ϊ�������
		}

	} while (b && c);//��һ��Ϊ0���˳�


	if (!b)
	{
		return adminLogIn(adm);//���µ�������ʼ�����˺�
	}

	return i;//�������Ա�˺�
}

/*�������ܣ��������뵫�ǽ���ֻ��ʾ*
* ������ڲ�������
* ��������ֵ��һ���������ĵ�ַ
*/
char* codeInput()
{
	int i;
	int count = 0;//��¼�����ַ����������
	static char a[20] = { 0 };//����һ������Ϊ20�ľ�̬�ַ���������������룬����ʼ��Ϊ��,��̬�ַ��������ʹ���ŵ����ݵ��������ڹᴩ����������������
	for (i = 0; i < 20; i++)
	{
		a[i] = getch();//�������뵫�ǲ�����Ļ����ʾ
		if (a[i] != '\r'&&a[i]!='\0')//�ж������ַ��Ƿ�Ϊ�ո������ǿո�������Ļ����ʾ*
		{
			putchar('*');
			count++;
		}
		else//�������ַ�Ϊ�ո������ѭ��
			break;
	}
	for (count; count < 20; count++)
	{
		a[count] = '\0';//��̬������û���޸ĵ������ַ�Ϊ��
	}
	return a;//���ش�����������
}

/*�������ܣ���¼��ʼ����
* ������ڲ�����������ṹ������user��adm
* ��������ֵ��int ���ͣ�3Ϊ�û���Ҫע�ᣬ1Ϊ�û���¼�ɹ���2Ϊ����Ա��¼�ɹ�,0Ϊ����ѡ��ϵͳ
*/
int logIn(USER user[], ADM adm[], int* userNumPointer, int* admNumPointer)
{
	int a = 0;
	switch (selectUserAdmin())
	{
	case 1:
		a = adminLogIn(user);
		if (a != -1)
		{
			*admNumPointer = a;//�����a���˻���������ָ��
			a = 2;//���˵��������Ա����
		}

		if (a == -1)
		{
			a = 0;//���˵�����ѡ�����
		}
		return a;//0Ϊѡ����棬2Ϊ����Աϵͳ   
		break;

	case 2:
		a = userLogIn(user);
		if (a != -2 && a != -1)
		{
			*userNumPointer = a;//�����a���˻���������ָ��
			a = 1;//���˵������û�����
		}
		if (a == -2)
		{
			a = 3;//���˵������û�����
		}
		if (a == -1)
		{
			a = 0;//���˵������û�����
		}
		return a;//3Ϊ��Ҫע�ᣬ0Ϊ�˳���ѡ�����Ա���û���1Ϊ�û���¼�ɹ�
		break;
	}
}
/*�������ܣ��жϵ�¼����Աϵͳ�����û�ϵͳ
������ڲ�������
��������ֵ��int�ͣ�1Ϊ����Ա��2Ϊ�û�
*/
int selectUserAdmin()
{
	char a[100] = { 0 };//���ڼ�¼���������ַ�
	int b;//�����ж��Ƿ������һ��
	do {
		b = 1;
		//printf("��ѡ��ʹ�ù���Ա���û���¼������Աѡ��1���û�ѡ��2��\n");//������ʾ
		printf("\t\t\t\t"); 
		scanf("%s", &a);//����
		if (atoi(a) == 1 || atoi(a) == 2)
		{

			if (atoi(a) == 1)
			{
				printf("\t\t\t\t���ڵ�¼����Աϵͳ\n");
				return 1;
			}
			else
			{
				printf("\t\t\t\t���ڵ�¼�û�ϵͳ\n");
				return 2;
			}
			b = 0;
		}
		else
		{
			printf("\t\t\t\t������������������\n");
		}
	} while (b);
}

/*�������ܣ������˺�
������ڲ�������
��������ֵ��int�ͣ�0�˳���ѡ�����Ա���û�����������Ϊ�˺����
*/
int AccountInput()
{

	char a[100] = { 0 };//���ڼ�¼���������ַ�
	int b;//�����ж��Ƿ������һ��
	char c;
	int d;//�����ж��û������Ƿ���Ϲ���
	do {
		b = 1;
		d = 1;
		printf("\t\t\t\t�������˺�(���롰�˳������˳�)\n");//������ʾ
		printf("\t\t\t\t");
		scanf("%s", &a);//����
		if (!strcmp(a, "�˳�"))//�ж��Ƿ����롰�˳���
		{
			printf("\t\t\t\t���˳�\n");
			return 0;//�˳���ѡ�����Ա���û�
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
				return atof(a);
				b = 0;//������һ��
			}
		}
	} while (b);//�˺��������
}
/*�������ܣ��жϹ���Ա�˺��Ƿ���ȷ
������ڲ�����������ṹ������adm��������жϵ��˺�
��������ֵ��int�ͣ�-1Ϊδע�ᣬ��������Ϊ�˺������еڼ�����
*/
int admAccountToPassword(ADM adm[], int accountInput)
{
	int i = 0;
	for (; i < 100; i++)
	{
		if (accountInput == adm[i].ID)
		{
			return i;
		}
	}
	if (i == 100)
	{
		printf("\t\t\t\t���˺���Ч\n");
		return -1;
	}
}
/*�������ܣ���������
������ڲ�����k���ɴ��ݳ�����
��������ֵ��int�ͣ�0�˳���1Ϊ������ɡ�k�����������
*/
int PasswordInput(char* k)
{

	char a[100] = { 0 };//���ڼ�¼���������ַ�
	int b;//�����ж��Ƿ������һ��
	char c;
	int d;//�����ж��û������Ƿ���Ϲ���
	b = 1;
	d = 1;
	printf("\t\t\t\t����������(���롰�˳������˳�)\n");//������ʾ
	printf("\t\t\t\t");
	//scanf("%s", &a);//����

	strcpy(a, codeInput());
	printf("a:%s\n", a);


	if (!strcmp(&a, "�˳�"))//�ж��Ƿ����롰�˳���
	{
		printf("\t\t\t\t���˳�\n");
		return 0;//�˳�������
	}
	strcpy(k, a);
	return 1;//�����������
}
/*�������ܣ��ж϶�Ӧ�����Ƿ���ȷ
������ڲ������ṹ��adm���ַ���ָ�봫����������룬��i���˻������ж�
��������ֵ��int�ͣ�1Ϊ����0Ϊ��ȷ
*/
int admPasswordDetection(ADM adm[], char* admPasswordIuput, int i)
{
	if (!strcmp(admPasswordIuput, adm[i].code))//�ж��Ƿ����롰ע�ᡱ

	{
		printf("\t\t\t\t������ȷ����¼�ɹ�\n");
		return 0;//��¼�ɹ�
	}
	printf("\t\t\t\t�������\n");
	return 1;//�������

}





/*�������ܣ��û�ϵͳ���е�¼
������ڲ�����������ṹ������user
��������ֵ��int�ͣ�-2Ϊ��Ҫע�ᣬiΪ��i��һ���û��˺ţ�-1Ϊ�˳���ѡ�����Ա���û�
*/
int userLogIn(USER user[])
{
	int i = 0;
	int uesrAccountNum = 0;
	char userPassword[100] = { 0 };
	int a = 0;
	int userNum = 0;
	do
	{
		a = AccountInput();
		if (!a)
		{
			return -1;//-1Ϊ�˳���ѡ�����Ա���û�
		}
		i = userAccountToPassword(user, a);//��i�ǵ�i���û��˺�
		if (i == -1)
		{
			printf("\t\t\t\t�Ƿ���Ҫע�᣿\n");//ѯ���Ƿ���Ҫע��
			if (judgeRegis())
			{
				return -2;//��Ҫע��
			}
		}
	} while (!(i + 1));//iΪ-1��ѭ������
	int b, c;
	char k[100] = "";
	do
	{
		b = PasswordInput(k);//0Ϊ�˳����˺ţ�1Ϊ�������
		if (b)
		{
			c = userPasswordDetection(user, k, i);//0Ϊ��ȷ��1Ϊ�������
		}
	} while (b && c);//��һ��Ϊ0���˳�
	if (!b)
	{
		return userLogIn(user);//���µ�������ʼ�����˺�
	}
	return i;
}

/*�������ܣ��ж��û��˺��Ƿ���ȷ
������ڲ�����������ṹ������user��������жϵ��˺�
��������ֵ��int�ͣ�0Ϊδע�ᣬ��������Ϊ�˺������еڼ�����
*/
int userAccountToPassword(USER user[], int accountInput)
{
	int i = 0;
	for (; i < 100; i++)
	{
		if (accountInput == user[i].ID)
		{
			return i;
		}
	}
	if (i == 100)
	{
		printf("\t\t\t\t�˺�δע��\n");
		return -1;
	}
}

/*�������ܣ��ж϶�Ӧ�����Ƿ���ȷ
������ڲ������ṹ��user���ַ���ָ�봫����������룬��i���˻������ж�
��������ֵ��int�ͣ�1Ϊ����0Ϊ��ȷ
*/
int userPasswordDetection(USER user[], char* userPasswordIuput, int i)
{
	if (!strcmp(userPasswordIuput, user[i].code))//�ж��Ƿ����롰ע�ᡱ
	{
		printf("\t\t\t\t������ȷ����¼�ɹ�\n");
		return 0;//��¼�ɹ�
	}
	printf("\t\t\t\t�������\n");
	return 1;//�������

}
/*�������ܣ��ж��Ƿ�ע��
������ڲ�����
��������ֵ��int�ͣ�1Ϊע�ᣬ0Ϊ��ע��
*/
int judgeRegis()//�Ƿ����ע��
{
	char a[100] = { 0 };//���ڼ�¼���������ַ�
	int b;//�����ж��Ƿ������һ��
	do {
		b = 1;
		printf("\t\t\t\t�Ƿ����ע�᣿ע��������1����ע��������2\n");//������ʾ
		printf("\t\t\t\t");
		scanf("%s", &a);//����
		if (atoi(a) == 1 || atoi(a) == 2)
		{

			if (atoi(a) == 1)
			{
				printf("\t\t\t\tע��\n");
				return 1;
			}
			else
			{
				printf("\t\t\t\t��ע��\n");
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


