#ifndef STRUCT
#define STRUCT
typedef struct admin      //����Ա--�ṹ��
{
	int ID;               //����Ա�˻�
	char code[50];        //����Ա���� 
}ADM;

typedef struct package    //�ײ�--�ṹ��
{
	int ID;               //�ײ��˻�
	char name[25];        //�ײ�����
	float money;          //�ײͼ۸�
	float mobileData4G;   //�ײ�4G����
	float mobileData5G;   //�ײ�5G����
	float callDuration;   //�ײ�ͨ��ʱ��
	int Broadband;        //�ײͿ������
}PKG;

typedef struct user       //�û�--�ṹ��
{
	int ID;               //�û��˻�
	char code[50];        //�û����� 
	char name[25];        //�û��û���
	float balance;        //�û����
	int packageID;          //�û��ײ�ID
}USER;

#endif 

