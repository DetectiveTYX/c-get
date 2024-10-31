#include<stdio.h>
#include<stdlib.h>
#include "struct.h"
#include "usersModifyBalance.h"
#include "login.h"
#include"fileReadWrite.h"
#include"regis.h"
#include"changeCode.h"
#include"usersMatchPackage.h"
#include"packageManage.h"
#include"userManage.h"
#include"Select.h"
#include"printMessage.h"

void printPrompt(int num, USER user[], ADM adm[], PKG pkg[]);//
int actionPrompt(int num, USER user[], ADM adm[], PKG pkg[], int* userNumPointer,int*admNumPointer);//�ú�������ֵ�ḳֵ��num

int main()
{
	ADM adm[100] = { 0};
	PKG pkg[100] = { 0};
	USER user[100] = { 0};
	//int userNum = 0;
	//PKG needPKG = { 0,"0",0,0,0,0,0 };
	PKG needPKG = { 0,"0",0,0,50,200,1000 };
	int mustget[4] = { 0, 1, 0, 1 };
	float pkgCompare[100] = { 0 };
	int USERNUM = 0,*userNumPointer=&USERNUM;
	int ADMNUM = 0, *admNumPointer = &ADMNUM;
	int actionNum = 0;

	readFilePKG(pkg); 
	readFileADM(adm);
	readFileUSER(user);

	//comparePackage(pkg, needPKG, mustget,pkgCompare);
	//putSuggest(pkg, needPKG, mustget, pkgCompare);
	while (1)
	{	
		printPrompt(actionNum,user,adm,pkg);
		actionNum=actionPrompt(actionNum,user,adm,pkg, userNumPointer,admNumPointer);
	}



	//packageAdd(pkg,16);
	return 0;
}

void printPrompt(int num, USER user[], ADM adm[], PKG pkg[])
{
	switch (num)
	{
	case -1:
		system("cls");
		break;
	case 0:
		system("cls");
		printf("\n\n\n\n\t\t\t\t-----------------------------------");
		printf("\n\t\t\t\t|   ��ӭ�����ƶ��ͻ���        ��  |");
		printf("\n\t\t\t\t-----------------------------------");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|        1.����Ա��¼             |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|        2.�û���¼               |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t-----------------------------------");
		printf("\n\n\n\t\t\t\t  ��ѡ��ʹ�ù���Ա���û���¼��\n\t\t\t\t  ����Աѡ��1\n\t\t\t\t  �û�ѡ��2\n");//������ʾ
		break;
	case 1:
		system("cls");
		printf("\n\n\n\n\t\t\t\t--------------------------------------");
		printf("\n\t\t\t\t|          ��ӭ�����û����棡        |");
		printf("\n\t\t\t\t--------------------------------------");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          1.��ѯ������Ϣ            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          2.��ѯ�ײ���Ϣ            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          3.�޸��ײ�                |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          4.��ѯ���(��ֵ���)      |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          5.�޸�����                |");
		printf("\n\t\t\t\t|                                    |");		
		printf("\n\t\t\t\t|          6.�˳��˺�                |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t--------------------------------------");
		printf("\n\n\n\t\t\t\t\t  ��ѡ����Ҫ���еĲ�����\n\t\t\t\t\t  ��ѯ������Ϣ��1\n\t\t\t\t\t  ��ѯ�ײ���Ϣ��2\n");//������ʾ
		printf("\t\t\t\t\t  �޸��ײͣ�3\n\t\t\t\t\t  ��ѯ���(��ֵ���)��4\n");//������ʾ
		printf("\t\t\t\t\t  �޸����룺5\n\t\t\t\t\t�˳��˺�\n");//������ʾ
		break;
	case 2:
		system("cls");
		printf("���ڽ������Ա�˺�");
		printf("\n\n\n\n\t\t\t\t-----------------------------------");
		printf("\n\t\t\t\t|       ��ӭ�������Ա���棡      |");
		printf("\n\t\t\t\t-----------------------------------");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|       1.�����ײ���Ϣ����        |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|       2.�����û���Ϣ����        |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|       3.�޸�����                |");		
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|       4.�˳��˺�                |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t|                                 |");
		printf("\n\t\t\t\t-----------------------------------");
		printf("\n\n\n\t\t\t\t  ��ѡ����Ҫ�������Ϣ����\n\t\t\t\t  �ײ���Ϣ����1\n\t\t\t\t  �û���Ϣ����2");//������ʾ
		printf("\n\t\t\t\t  �޸����룺3\n\t\t\t\t  �˳��˺ţ�4\n");//������ʾ

		break;
	case 3:
		printf("��ӭ����ע����棡\n");
		break;
	case 4:
		system("cls");
		printf("\n\n\n\n\t\t\t\t--------------------------------------");
		printf("\n\t\t\t\t|      ��ӭ�����ײ���Ϣ������棡    |");
		printf("\n\t\t\t\t--------------------------------------");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          1.��ѯ�ײ���Ϣ            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          2.�����ײ���Ϣ            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          3.�����ײ���Ϣ            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          4.ɾ���ײ���Ϣ            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          5.���ع���Ա����          |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t--------------------------------------");
		printf("\n\n\n\t\t\t\t\t  ��ѡ����Ҫ���еĲ�����\n\t\t\t\t\t  ��ѯ�ײ���Ϣ��1\n\t\t\t\t\t  �����ײ���Ϣ��2\n");//������ʾ
		printf("\t\t\t\t\t  �����ײ���Ϣ��3\n\t\t\t\t\t  ɾ���ײ���Ϣ��4\n");//������ʾ
		printf("\t\t\t\t\t  ���ع���Ա���棺5 \n");//������ʾ
		break;
	case 5:
		system("cls");
		printf("\n\n\n\n\t\t\t\t--------------------------------------");
		printf("\n\t\t\t\t|      ��ӭ�����û���Ϣ������棡    |");
		printf("\n\t\t\t\t--------------------------------------");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          1.��ѯ�û���Ϣ            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          2.�����û���Ϣ            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          3.�����û���Ϣ            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          4.ɾ���û���Ϣ            |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t|          5.���ع���Ա����          |");
		printf("\n\t\t\t\t|                                    |");
		printf("\n\t\t\t\t--------------------------------------");
		printf("\n\n\n\t\t\t\t\t  ��ѡ����Ҫ���еĲ�����\n\t\t\t\t\t  ��ѯ�û���Ϣ��1\n\t\t\t\t\t  �����û���Ϣ��2\n");//������ʾ
		printf("\t\t\t\t\t  �����û���Ϣ��3\n\t\t\t\t\t  ɾ���û���Ϣ��4\n");//������ʾ
		printf("\t\t\t\t\t  ���ع���Ա���棺5 \n");//������ʾ
		break;
	case 6:
		system("cls");
		printf("\n\n\n\n\t\t\t\t--------------------------------------");
		printf("\n\t\t\t\t|      ���ڲ�ѯ�û���    |");
		printf("\n\t\t\t\t--------------------------------------");
		//printf("\n\t\t\t\t|                                    |");
		//printf("\n\t\t\t\t|          1.��ѯ�û���Ϣ            |");
		//printf("\n\t\t\t\t|                                    |");
		//printf("\n\t\t\t\t|          2.�����û���Ϣ            |");
		//printf("\n\t\t\t\t|                                    |");
		//printf("\n\t\t\t\t|          3.�����û���Ϣ            |");
		//printf("\n\t\t\t\t|                                    |");
		//printf("\n\t\t\t\t|          4.ɾ���û���Ϣ            |");
		//printf("\n\t\t\t\t|                                    |");
		//printf("\n\t\t\t\t|          5.���ع���Ա����          |");
		//printf("\n\t\t\t\t|                                    |");
		//printf("\n\t\t\t\t--------------------------------------");
		//printf("\n\n\n\t\t\t\t\t  ��ѡ����Ҫ���еĲ�����\n\t\t\t\t\t  ��ѯ�û���Ϣ��1\n\t\t\t\t\t  �����û���Ϣ��2\n");//������ʾ
		//printf("\t\t\t\t\t  �����û���Ϣ��3\n\t\t\t\t\t  ɾ���û���Ϣ��4\n");//������ʾ
		//printf("\t\t\t\t\t  ���ع���Ա���棺5 \n");//������ʾ
		break;
	default:
		break;
	}
}

int actionPrompt(int num, USER user[], ADM adm[], PKG pkg[], int* userNumPointer, int* admNumPointer)//�ú�������ֵ�ḳֵ��num
{
	int a = 0;
	char x[100] = { 0 };
	switch (num)
	{
	case -1:
		return 0;
	case 0://ѡ�����Ա���û�����
		a = logIn(user, adm, userNumPointer,admNumPointer);
		return a;
	case 1://�����û�����
		return USERSelect(user, pkg, userNumPointer);
	case 2://�������Ա����
		return ADMSelect(user,admNumPointer);
	case 3://����ע�����
		return	regis(user);
	case 4://�����ײ���Ϣ����ϵͳ
		return PKGManageSelect(pkg);
	case 5://�����û���Ϣ����ϵͳ
		return USERManageSelect(user, pkg);
	case 6://��������ѯϵͳ
		return modifyBalance(user, *userNumPointer);
	default:
		break;
	}

}






