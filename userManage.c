#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "struct.h"

/*�������ܣ��û���Ϣ��ѯ
*������ڲ�����������ṹ��user
*��������ֵ���޷���ֵ
*/
void userSearch(USER a[])//�û���Ϣ��ѯ����
{
    int i;
    int n = 0;//nָ���û�����
    for (int k = 0; k < 100; k++)
    {
        if (a[k].ID)
        {
            n++;
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("\t\t\t\t�û���%4d \t\t�û��˺ţ�%d \t\t�û����룺%s\n", i + 1, a[i].ID, a[i].code);
        printf("\t\t\t\t�û�����%s \t\t�û���%.2fԪ\t�û��ײͱ�ţ�%d \n", a[i].name, a[i].balance, a[i].packageID);
        //printf("�û��ײͱ�ţ�%d \n", a[i].packageID);
        //printf("\t   �ײ�4G������%8.2fGB\t�ײ�5G������%4.2fGB  \n", b[i].mobileData4G, b[i].mobileData5G );
        //printf("\t   �ײ�ͨ��ʱ����%.2fmin\t�ײͿ������%dMB/S\n", b[i].callDuration, b[i].Broadband);
    }
}
/*�������ܣ��û���Ϣ����
*������ڲ�����������ṹ������user��������ṹ������pkg
* ��������ֵ����ӵ��û���Ϣ������
*/
int userAdd(USER a[], PKG b[])
{
    int i;//�����Ҫ���ӵ��û����ײͱ��
    int j;//�����û���Ϣ�������ӵ�ѭ��
    int p;//���������ײͽṹ���еı��
    int count = 0;//��¼�û���Ϣ��������
    int n;//nָ���û�������
    int m;//mָ���ײ͵�����
    do
    {
        n = 0;
        for (int k = 0; k < 100; k++)
        {
            if (a[k].ID)
            {
                n++;
            }
        }
        printf("\t\t\t\t����������Ҫ���ӵ��û����˺ţ�\n");
        printf("\t\t\t\t");
        scanf("%d", &a[n].ID);
        printf("\t\t\t\t����������Ҫ���ӵ��û������룺\n");
        printf("\t\t\t\t");
        scanf("%s", a[n].code);
        printf("\t\t\t\t����������Ҫ���ӵ��û����û�����\n");
        printf("\t\t\t\t");
        scanf("%s", a[n].name);
        printf("\t\t\t\t����������Ҫ���ӵ��û�����\n");
        printf("\t\t\t\t");
        scanf("%f", &a[n].balance);
        printf("\t\t\t\t����������Ҫ���ӵ��û����ײͱ�ţ�\n");
        do
        {
        reenter://goto����ת�Ʊ�ʶ���������������ײͱ��
            printf("\t\t\t\t");
            scanf("%d", &i);
            m = 0;
            for (int k = 0; k < 100; k++)
            {
                if (b[k].ID)
                {
                    m++;
                }
            }
            if (i<1 || i>m)
            {
                printf("\t\t\t\t�����ڸ��Ż��ײͣ������������ײͱ�ţ�\n");
                continue;//��������ѭ�����¿�ʼѭ��
            }//�ȴ��ȷ���ײͱ���Ƿ����Ҫ��
            else
                break;
        } while (1);//ͨ��while����ѭ��ʹ�����ܹ������ŷ��ϵ��ײͱ��
        for (p = 0;; p++)//for��������ѭ��
        {
            if (i == b[p].ID)
            {
                a[n].packageID = i;
                printf("\t\t\t\t����ɸ��û��ײ���Ϣ�����ӣ�\n");
                break;//�ײͱ�������е��ײ���Ϣ�У�����forѭ��
            }
            if (p >= m)//�����е��ײ���Ϣ��δ�ҵ����ײ���Ϣ
            {
                printf("\t\t\t\t�����ڸ��Ż��ײͣ������������ײͱ�ţ�\n");
                goto reenter;//���ر�ʶ�����½���ѭ��
            }
        }
        count++;//��ʱ����������û����������ӵ��û�������һ
        userSearch(a);
        printf("\t\t\t\t����Ҫ���������û���Ϣ����������0�������������������˳������û���Ϣ��\n");
        printf("\t\t\t\t");
        scanf("%d", &j);
    } while (j == 0);//�ж��Ƿ���������û���Ϣ
    return count;//���������������ӵ��û���Ϣ������
}
/*�������ܣ��û���Ϣ����
*������ڲ�����������ṹ������user��������ṹ������pkg
*��������ֵ���޷���ֵ
*/
void userChange(USER a[], PKG b[])//�û���Ϣ���ĺ���
{
    int i;//�����Ҫ������Ϣ���û��ı��
    int j;//����û����ĺ���ײͱ��
    int k;//�������������û���Ϣ��ѭ��
    int p;//���������ײͽṹ���еı��
    int n;//nָ���û�������
    int m;//mָ���ײ͵�����
    do
    {
        do
        {
            n = 0;
            for (int k = 0; k < 100; k++)
            {
                if (a[k].ID)
                {
                    n++;
                }
            }
            printf("\t\t\t\t��������Ҫ���ĵ��û��ı�ţ�\n");
            printf("\t\t\t\t");
            scanf("%d", &i);
            if (i<1 || i>n)
            {
                printf("\t\t\t\t��Ч�û���ţ����������룺\n");
            }
            else
                break;
        } while (1);//�ж���Ҫ���ĵ��û��Ƿ���ڣ������������ѭ��
        printf("\t\t\t\t��������ĺ���û����˺ţ�\n");
        printf("\t\t\t\t");
        scanf("%d", &a[i - 1].ID);//���ڽṹ���ַ���㿪ʼ������ʵ���û���Ϣ���ڵ�λ��Ϊi-1
        printf("\t\t\t\t��������ĺ���û������룺\n");
        printf("\t\t\t\t");
        scanf("%s", a[i - 1].code);
        printf("\t\t\t\t��������ĺ���û����û�����\n");
        printf("\t\t\t\t");
        scanf("%s", a[i - 1].name);
        printf("\t\t\t\t��������ĺ���û�����\n");
        printf("\t\t\t\t");
        scanf("%f", &a[i - 1].balance);
        printf("\t\t\t\t��������ĺ���û����ײͱ�ţ�\n");
        do
        {
        reenter://goto�������ر�ʶ
            printf("\t\t\t\t");
            scanf("%d", &j);
            m = 0;
            for (int k = 0; k < 100; k++)
            {
                if (b[k].ID)
                {
                    m++;
                }
            }
            if (j<1 || j>m)
            {
                printf("\t\t\t\t�����ڸ��Ż��ײͣ������������ײͱ�ţ�\n");
                continue;
            }//�ȴ���жϸ��ĺ���ײ��Ƿ����
            else
                break;
        } while (1);//ͨ��while����ѭ��ʹ�����ܹ�������ڵ��ײͱ��
        for (p = 0;; p++)//ͨ��for����ѭ�������ײ���Ϣ
        {
            if (j == b[p].ID)//���ĺ���ײʹ��������е��ײ���
            {
                a[i - 1].packageID = j;//�����ײͱ��
                printf("\t\t\t\t����ɸ��û��ײ���Ϣ�ĸ��ģ�\n");
                break;//����forѭ��
            }
            if (p >= m)//���е��ײ���Ϣ��û�и��ײ�
            {
                printf("\t\t\t\t�����ڸ��Ż��ײͣ������������ײͱ�ţ�\n");
                goto reenter;//���ر�ʶ��������������
            }
        }
        userSearch(a);
        printf("\t\t\t\t����Ҫ���������û���Ϣ����������0�������������������˳������û���Ϣ��\n");
        printf("\t\t\t\t");
        scanf("%d", &k);
    } while (k == 0);
}
/*�������ܣ��û���Ϣɾ��
*������ڲ�����������ṹ������user
* ��������ֵ��ɾ�����û���Ϣ����
*/
int userDelete(USER a[])//ɾ���û���Ϣ������temUSER�ݴ�ṹ������ 
{
    USER* temUSER = { 0 };
    int i;//�洢��Ҫɾ�����û��ı��
    int j;//��������ɾ��ѭ��
    int count = 0;//��¼ɾ������������
    int n;//nָ����ǰ�û���Ϣ����
    do
    {
        do
        {
            n = 0;
            for (int k = 0; k < 100; k++)
            {
                if (a[k].ID)
                {
                    n++;
                }
            }
            printf("\t\t\t\t��������Ҫɾ�����û��ı�ţ�\n");
            printf("\t\t\t\t");
            scanf("%d", &i);
            if (i<1 || i>n)
            {
                printf("\t\t\t\t��Ч�û���ţ����������룡\n");
            }
            else
                break;
        } while (1);//�ж��Ƿ���ڸ��û�
        temUSER = &a[i];//���ݴ�ָ����ʱ�����һλ�û�����Ϣ
        for (i; i - 1 < n; i++, temUSER++)//ͨ��forѭ���ú�һλ�û�����Ϣ����ǰһλ�û�����Ϣ
        {
            a[i - 1] = *temUSER;
        }
        count++;//�ɹ�ɾ��һλ�û���Ϣ���¼һ��
        printf("\t\t\t\t�ѳɹ�ɾ�����û�����Ϣ��\n");
        userSearch(a);
        printf("\t\t\t\t�����Ҫ����ɾ���û���Ϣ����������0�����������ּ��˳�ɾ����\n");
        printf("\t\t\t\t");
        scanf("%d", &j);
    } while (j == 0);//�ж��Ƿ����ɾ���û���Ϣ
    return count;//����ɾ�����û���Ϣ����
}

/*�������ܣ��û�������ѡ�����
������ڲ�����pkg
��������ֵ��int�ͣ�            4Ϊ�ײ���Ϣ����2Ϊ����Ա����
*/
int USERManageSelect(USER user[],PKG pkg[])//�ײ͹�����ѡ�����
{
    char a[100] = { 0 };//���ڼ�¼���������ַ�
    int b;//�����ж��Ƿ������һ��
    char x[100] = { 0 };//�������ݴ�
    do {
        b = 1;
        printf("\t\t\t\t");
        scanf("%s", &a);//����
        if (atoi(a) == 1 || atoi(a) == 2 || atoi(a) == 3 || atoi(a) == 4 || atoi(a) == 5)
        {

            if (atoi(a) == 1)
            {
                int s = 0;
                printf("\t\t\t\t��ѯ�û���Ϣ��\n");
                userSearch(user);
                //packageSearch(pkg);
                //printf("��������������ɲ�ѯ�������ϼ��˵�:\n");
                //scanf("%s", x);
                return 5;//������ɺ󷵻�5�û���Ϣ�������
            }
            if (atoi(a) == 2)
            {
                printf("\t\t\t\t�����û���Ϣ:\n");
                userSearch(user);
                userChange(user, pkg);
                //packageSearch(pkg);
                //packageChange(pkg);
                //system("cls");
                //packageSearch(pkg);
                //printf("��������������ɲ�ѯ�������ϼ��˵�:\n");
                //scanf("%s", x);
                return 5;//������ɺ󷵻�5�û���Ϣ�������
            }
            if (atoi(a) == 3)
            {
                printf("\t\t\t\t�����û���Ϣ:\n");
                userSearch(user);
                userAdd(user, pkg);
                //packageSearch(pkg);
                //packageAdd(pkg);
                //system("cls");
                //packageSearch(pkg);
                //printf("��������������ɲ�ѯ�������ϼ��˵�:\n");
                //scanf("%s", x);
                return 5;//������ɺ󷵻�5�û���Ϣ�������
            }
            if (atoi(a) == 4)
            {
                printf("\t\t\t\tɾ���û���Ϣ:\n");
                userSearch(user);
                userDelete(user);
                //packageSearch(pkg);
                //packageDelete(pkg);
                //system("cls");
                //packageSearch(pkg);
                //printf("��������������ɲ�ѯ�������ϼ��˵�:\n");
                //scanf("%s", x);
                return 5;//������ɺ󷵻�5�û���Ϣ�������
            }
            if (atoi(a) == 5)
            {
                printf("\t\t\t\t���ع���Ա����:\n");
                return 2;//����2����Ա����
            }
            b = 0;
        }
        else
        {
            printf("\t\t\t\t������������������\n");
        }
    } while (b);
}