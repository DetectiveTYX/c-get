#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "struct.h"

/*�������ܣ��ж�������ַ����Ƿ�Ϊ��������
*������ڲ��������ú����������ַ���input
*��������ֵ�����ַ����е�ÿһ���ַ������������ͣ�����1�������з��������͵��ַ�������0
*/
int numberJudge(char* a)
{
    int i;//�����ַ�����ÿһ���ַ�
    int n;//����ַ����ĳ���
    n = strlen(a);//�����ж��ַ����ĳ��ȣ�����ֵ��n
    for (i = 0; i < n; i++)
    {
        if (isdigit(a[i]) == 0&&(a[i]!='.'))//�ж�ÿһ���ַ��Ƿ�Ϊ��������
        {
            printf("\t\t\t\t��ǰ����Ϊ��Чֵ�����������֣�\n");
            return 0;//������ڷ��������ͷ���0
        }
    }
    return 1;//ȫ����Ϊ�������ͷ���1
}
/*�������ܣ���ѯ�ײ���Ϣ
*������ڲ�����������ṹ������pkg���ײ�����n
* ��������ֵ��int��
*/
void packageSearch(PKG a[])//�ײ���Ϣ��ѯ����,nָ���ײ����� 
{
    int i;
    int n = 0;
    int s = 0;
    for (int k = 0; k < 100; k++)
    {
        if (a[k].ID)
        {
            n++;
        }
    }
    for (i = 0; i < n; i++)//����ÿһ���ײ���Ϣ�ṹ��
    {
        printf("\t\t\t\t��ţ�%2d  �ײ�����%s  �ײͼ۸�%.2f Ԫ\n", a[i].ID, a[i].name, a[i].money);
        printf("\t\t\t\t�ײ�4G������%.2f GB  �ײ�5G������%.2f GB\n", a[i].mobileData4G, a[i].mobileData5G);
        printf("\t\t\t\t�ײ�ͨ��ʱ����%.2f min  �������%d MB/S\n", a[i].callDuration, a[i].Broadband);
    }

    
}

/*�������ܣ����ײ���Ϣ��������
*������ڲ�����������ṹ������pkg���ײ�����
* ����ֵ����ӵ��ײ�����
*/
int packageAdd(PKG a[])//�ײ���Ϣ���Ӻ�����nָ���ײ�����
{
    int i = 1;//����whileѭ��
    int count = 0;//��¼���ӵ��ײ�����
    int judge;//���ж��ַ������ݺ�����Ͻ����ж�
    char input[20] = { 0 };//�ݴ����������
    int n = 0;

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
        a[n].ID = n + 1;//����˳������ӵ��ײͱ��
        printf("\t\t\t\t���������ӵ��ײ����ƣ�\n");
        printf("\t\t\t\t");
        scanf("%s", a[n].name);
        do
        {
            printf("\t\t\t\t���������ӵ��ײͼ۸�\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//�ж�������ײͼ۸��Ƿ�Ϊ�������ͣ���������������
        a[n].money = atof(input);
        do
        {
            printf("\t\t\t\t���������ӵ��ײ͵�4G������������\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//�ж������4G�����������Ƿ�Ϊ�������ͣ���������������
        a[n].mobileData4G = atof(input);
        do
        {
            printf("\t\t\t\t���������ӵ��ײ͵�5G������������\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//�ж������5G�����������Ƿ�Ϊ�������ͣ���������������
        a[n].mobileData5G = atof(input);
        do
        {
            printf("\t\t\t\t���������ӵ��ײ�ͨ��ʱ����\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//�ж�������ײ�ͨ��ʱ���Ƿ�Ϊ�������ͣ���������������
        a[n].callDuration = atof(input);
        do
        {
            printf("\t\t\t\t���������ӵ��ײͿ������\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//�ж�������ײͿ�������Ƿ�Ϊ�������ͣ���������������
        a[n].Broadband = atoi(input);
        n++;//�ײ���������
        printf("\t\t\t\t�ѳɹ����Ӹ��ײ���Ϣ��\n");
        count++;//�ɹ������ײͺ��¼+1
        printf("\t\t\t\t��������0�������ײ���Ϣ��ӣ����������������֣����������ײ���Ϣ�� \n");
        printf("\t\t\t\t");
        scanf("%d", &i);
    } while (i == 0);//�ж��Ƿ��������ײ���Ϣ
    return count;//�����ѳɹ���ӵ��ײ���Ϣ����
}
/*�������ܣ�ɾ���ײ���Ϣ
*������ڲ������������ݴ�ṹ������temPKG���ṹ������pkg���ײ�����n
* ��������ֵ��������ײ���Ϣ����
*/
int packageDelete(PKG a[])//ɾ���ײ���Ϣ����,temPKGΪ��ʱָ���ݴ�Ҫɾ��������֮��Ľṹ������
{
    PKG* temPKG = { 0 };
    int i;//�����Ҫɾ�����ײ���Ϣ�ı��
    int j;//���������ײ���Ϣ�ı��
    int k;//��������ɾ���ײ���Ϣ��ѭ��
    int count = 0;//��¼ɾ�����ײ�����
    int n = 0;
    do
    {
        printf("\t\t\t\t��������Ҫɾ�����ײͱ�ţ�\n");
        printf("\t\t\t\t");
        scanf("%d", &i);
        for (int k = 0; k < 100; k++)
        {
            if (a[k].ID)
            {
                n++;
            }
        }
        if (i<1 || i>n)
        {
            printf("\t\t\t\t�����ڸ��ײ���Ϣ��ţ����������룡\n");
            continue;//�����ڸ��ײ���Ϣ��Ž����������У����¿�ʼѭ��
        }//�ж��Ƿ���ڸ��ײ���Ϣ
        for (j = 0;; j++)
        {
            if (i == a[j].ID)//�������ײ���ϢѰ�ҵ����ײ���Ϣ
            {
                temPKG = &a[j+1];//temPKGΪ��ʱָ���ݴ�Ҫɾ��������֮��Ľṹ������
                for (j; j - 1 < n; j++, temPKG++)//ͨ��forѭ������һ�����ײ���Ϣ���ǵ���ǰ�ײ���Ϣ��
                {
                    a[j] = *temPKG;
                }
                count++;//ÿɾ��һ���ײ���Ϣ��¼һ��
                n--;//�ײ�������������һ��
                printf("\t\t\t\t�Ѿ������ײ���Ϣɾ����\n");
                break;//���������ײ���Ϣ��forѭ��
            }
            if (j >= n)//�����е��ײ���û���ҵ����ײ�
            {
                printf("\t\t\t\t�ñ�ŵ��ײ��Ѿ���ɾ�����ˣ�\n");
                break;//���������ײ���Ϣ��forѭ��
            }
        }
        printf("\t\t\t\t�����Ҫ����ɾ���ײ���Ϣ����������0�����������ּ��˳�ɾ����\n");
        printf("\t\t\t\t");
        scanf("%d", &k);
    } while (k == 0);//�ж��Ƿ���Ҫ����ɾ���ײ���Ϣ
    return count;//������ɾ�����ײ����������ǲ�Ӱ����ڹ����ײ͵�����
}
/*�������ܣ������ײ���Ϣ
*������ڲ�����������ṹ������pkg���ײ�����n
* ��������ֵ���޷���ֵ
*/
void packageChange(PKG a[])
{
    int i;//�����洢������ײͱ��
    int j;//����һ������������ѭ�������ײ���Ϣ
    int p;//�������������ײͱ��
    int judge;//�����ж�����������Ƿ�Ϊ��������
    char input[20] = { 0 };//��ʱ���������ַ�
    int n;
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
        printf("\t\t\t\t��������Ҫ���ĵ��ײ���Ϣ�ı�ţ�\n");
    reenter://goto������ת�Ʊ�ʶ
        printf("\t\t\t\t");
        scanf("%d", &i);
        if (i<1 || i>n)
        {
            printf("\t\t\t\t�����ڸ��ײ���Ϣ��ţ����������룡\n");
            continue;//��������ѭ�������½���whileѭ��
        }//�����ж�������ײͱ���Ƿ����Ҫ��
        for (p = 0;; p++)//���ײͱ�Ž��б���
        {
            if (i == a[p].ID)//�������ײ����ҵ����ײ�
                break;//����forѭ����������������
            if (p >= n)//δ�������ײ����ҵ����ײ�
            {
                printf("\t\t\t\t�����ڸ��ײ���Ϣ��ţ����������룡\n");
                goto reenter;//ת������ʶ����������
            }
        }
        printf("\t\t\t\t��������ĺ���ײ����ƣ�\n");
        printf("\t\t\t\t");
        scanf("%s", a[p].name);
        do
        {
            printf("\t\t\t\t��������ĺ���ײͼ۸�\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//�ж�������ײͼ۸��Ƿ�Ϊ�������ͣ���������������
        a[p].money = atof(input);//���ַ�������תΪ��������
        do
        {
            printf("\t\t\t\t��������ĺ���ײ͵�4G������������\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//�ж������4G�����������Ƿ�Ϊ�������ͣ���������������
        a[p].mobileData4G = atof(input);//���ַ�������תΪ��������
        do
        {
            printf("\t\t\t\t��������ĺ���ײ͵�5G������������\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//�ж������5G�����������Ƿ�Ϊ�������ͣ���������������
        a[p].mobileData5G = atof(input);//���ַ�������תΪ��������
        do
        {
            printf("\t\t\t\t��������ĺ���ײ�ͨ��ʱ����\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//�ж�������ײ�ͨ��ʱ���Ƿ�Ϊ�������ͣ���������������
        a[p].callDuration = atof(input);//���ַ�������תΪ��������
        do
        {
            printf("\t\t\t\t��������ĺ���ײͿ������\n");
            printf("\t\t\t\t");
            scanf("%s", input);
            judge = numberJudge(input);
        } while (judge == 0);//�ж�������ײͿ�������Ƿ�Ϊ�������ͣ���������������
        a[p].Broadband = atoi(input);//���ַ�������תΪ��������
        printf("\t\t\t\t�ѳɹ����ĸ��ײ���Ϣ��\n");
        printf("\t\t\t\t�����Ҫ���������ײ���Ϣ����������0�����������ּ��˳�ɾ����\n");
        printf("\t\t\t\t");
        scanf("%d", &j);
    } while (j == 0);//�ж��Ƿ���Ҫ�����ײ���Ϣ
}
/*�������ܣ��ײ͹�����ѡ�����
������ڲ�����pkg
��������ֵ��int�ͣ�4Ϊ�ײ���Ϣ����2Ϊ����Ա����
*/
int PKGManageSelect(PKG pkg[])//�ײ͹�����ѡ�����
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
                printf("\t\t\t\t��ѯ�ײ���Ϣ��\n");
                packageSearch(pkg);
                printf("\t\t\t\t��������������ɲ�ѯ�������ϼ��˵�:\n");
                printf("\t\t\t\t");
                scanf("%s", x);
                return 4;//������ɺ󷵻�4�ײ���Ϣ�������
            }
            if (atoi(a) == 2)
            {
                printf("\t\t\t\t�����ײ���Ϣ:\n");
                packageSearch(pkg);
                packageChange(pkg);
                system("cls");
                packageSearch(pkg);
                printf("\t\t\t\t��������������ɲ�ѯ�������ϼ��˵�:\n");
                printf("\t\t\t\t");
                scanf("%s", x);
                return 4;//������ɺ󷵻�4�ײ���Ϣ�������
            }
            if (atoi(a) == 3)
            {
                printf("\t\t\t\t�����ײ���Ϣ:\n");
                packageSearch(pkg);
                packageAdd(pkg);
                system("cls");
                packageSearch(pkg);
                printf("\t\t\t\t��������������ɲ�ѯ�������ϼ��˵�:\n");
                printf("\t\t\t\t");
                scanf("%s", x);
                return 4;//������ɺ󷵻�4�ײ���Ϣ�������
            }
            if (atoi(a) == 4)
            {
                printf("\t\t\t\tɾ���ײ���Ϣ:\n");
                packageSearch(pkg);
                packageDelete(pkg);
                system("cls");
                packageSearch(pkg);
                printf("\t\t\t\t��������������ɲ�ѯ�������ϼ��˵�:\n");
                printf("\t\t\t\t");
                scanf("%s", x);
                return 4;//������ɺ󷵻�4�ײ���Ϣ�������
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