#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define TRUE 1

#define MAXSIZE 20     /*˳����������*/
typedef  int ElemType;  /*�����Ԫ�ص�����*/

/*˳������Ͷ���*/
struct list
{
    ElemType elem[MAXSIZE];  /*�洢�ռ�Ļ���ַ�����洢���Ա���Ԫ�صĴ洢�ռ估��С*/
    int length;           /*˳���ĵ�ǰ����*/
};
typedef struct list  SeqList;/*˳�������������(����*)*/

int Init_SeqList(SeqList *L); /*��ʼ��˳���*/
int Create_SeqList(SeqList *L,int n); /*����˳���*/
int Insert_SeqList(SeqList *L,int i,ElemType x);/*˳���Ĳ������*/
int Traverse_SeqList(SeqList *L);  /*˳���ı���*/
int Delete1_SeqList(SeqList *L,int i); /*˳���İ����ɾ������*/
int Delete2_SeqList(SeqList *L,ElemType x); /*˳���İ�����ɾ������*/
int Find_SeqList(SeqList *L,ElemType x); /*����ֵΪx��Ԫ��*/
int Count_Seqlist(SeqList *L,ElemType x)
{
    int i,cnt=0;
    for(i=0;i<L->length;i++)
    {
        if(L->elem[i]==x)
            cnt++;
    }
    return cnt;
}

/*��ʼ��˳���*/
int Init_SeqList(SeqList *L)
{
    L->length=0; 		/*�ձ���Ϊ0*/
    return TRUE;
}/*InitList*/

/*����˳�����˳���������n������*/
int Create_SeqList(SeqList *L,int n)
{
    ElemType x; //xΪ�������ֵ
    int i;
    if(n>MAXSIZE) return ERROR; /*n�����������*/
    for(i=0;i<n;i++)
    {
        printf("�������% d�����ݣ�",i+1);
        scanf("%d",&x);
        L->elem[L->length++]=x;  /*�����ݴ���˳���(�ȴ��ټ�)*/
    }
    return TRUE;
}/*CreateList*/

/*����˳���*/
int Traverse_SeqList(SeqList *L)
{
    int i;
    for(i=0;i<L->length;i++) printf("%-7d",L->elem[i]);/*��ǰ����������˳����е�Ԫ��*/
    printf("\n\n");
    return TRUE;
}/*TraverseList*/

/*��˳���L�У����i��λ���ϲ���ֵΪx��Ԫ��*/
int Insert_SeqList(SeqList *L,int i,ElemType x)
{
    int j;
    if(i<1||i>L->length) /*���i���*/
    {
        printf("���%d���\n",i);
        return ERROR;
    }
    if(L->length==MAXSIZE)  return ERROR;
    for(j=L->length-1;j>=i-1;j--)  L->elem[j+1]=L->elem[j]; //����>i!
    L->elem[i-1]=x;
    L->length++;
    return TRUE;
}
/*ListInsert*/

/*��˳����а������ɾ�����󣬼�ɾ����i��Ԫ��*/
int Delete1_SeqList(SeqList *L,int i)
{
    int j;
    if(i<1||i>L->length) /*���i���*/
    {
        printf("���%d���\n",i);
        return ERROR;
    }
    /*ɾ����i��Ԫ��*/
    for(j=i;j<L->length;j++) L->elem[j-1]=L->elem[j];
    L->length--;
    return TRUE;
}/*Delete1_*/

/*��˳����а�������ɾ�����󣬼�(��һ��)ɾ��ֵΪx��Ԫ��*/
int Delete2_SeqList(SeqList *L,ElemType x)
{
    int i,j;
    for(i=0;i<L->length;i++)/*��������x��λ��*/
    {
        if(L->elem[i]==x) break;
    }
    if(i==L->length)  return ERROR;  /*s˳�����û��ֵΪx�Ķ���*/
    for(j=i+1;j<L->length;j++) L->elem[j-1]=L->elem[j]; /*ɾ��ֵΪx�Ķ���*/
    L->length--;
    return TRUE;
}/*Delete2*/

void Delete3_SeqList(SeqList *L,ElemType x)
{
    int i,j;
    for(i=0;i<L->length;i++)/*��������x��λ��*/
    {
        if(L->elem[i]==x)
        {
            for(j=i+1;j<L->length;j++) //ɾ��Ԫ�أ�һ��ѭ��ɾ��һ����
            {
                L->elem[j-1]=L->elem[j];
                L->length--;
            }

            i--;  //���˼��
        }
    }



}/*Delete2*/


/*��˳����в���ָ��ֵԪ�أ���������ţ���û�з���ERROR*/
int Find_SeqList(SeqList *L,ElemType x)
{
    int i;
    for(i=0;i<L->length;i++)
    {
        if (L->elem[i] == x)
            break;
    }
    if (i==L->length)  return  ERROR;
    else return i+1;
}/*Find*/

/*˳������ӣ��ѱ�s2������s1�ĺ��棬ʧ�ܷ���0*/
int Cat_SeqList(SeqList *L1,SeqList *L2)
{
    int i;
    if(L1->length+L2->length>MAXSIZE) return ERROR; /*������޷�����*/

    for(i=0;i<L2->length;i++) L1->elem[L1->length+i]=L2->elem[i];
    L1->length+=L2->length;
    return TRUE;

}/*Cat*/

int main( )
{
    struct list *s1,*s2; //*s1 (s1)����(&s1)
    int n,m,k;
    char c;
    printf("Created by �ҵ�������Ox on 2024/4/23 023.\n\n");
    printf("**************************************************\n");
    printf("               ˳ �� �� �� �� �� ��\n");
    printf("**************************************************\n\n");

    s1=(SeqList *)malloc(sizeof(SeqList));	/*����˳���sl��Ϊsl���ٴ洢�ռ�*/
    s2=(SeqList *)malloc(sizeof(SeqList));	/*����˳���sl��Ϊs2���ٴ洢�ռ�*/

    printf("1����ʼ�����Ա�:���ñ�Ϊ0\n");
    if(Init_SeqList(s1))  printf("˳����ʼ���ɹ�����\n\n");

    printf("2������˳���\n");
    do
    {
        printf("������˳����ȣ�n>=0��: ");
        scanf("%d",&n);   /*����˳����Ԫ�ظ���*/
    }
    while (n<0);
    if(Create_SeqList(s1,n)) printf("\n˳������ɹ�����\n\n"); ;

    printf("3������˳���\n");  /*���η���˳���������Ԫ��*/

    Traverse_SeqList(s1);

    printf("4��˳���Ĳ��������\n");
    printf("������������λ��");
    scanf("%d",&m);
    printf("���������������ݣ�");
    scanf("%d",&k);
    if(Insert_SeqList(s1,m,k)) printf("�������ִ�гɹ�����\n���������");

    Traverse_SeqList(s1);

    printf("5��������ɾ����ʽ��1��ʾ������ɾ����2��ʾ�����ɾ��\n");
    scanf("%d",&m);
    if(m==2)
    {
        printf("����ѡ�������ɾ�������������ɾ��Ԫ�ص���ţ�");
        scanf("%d",&k);
        if(Delete1_SeqList(s1,k))
            printf("ɾ����%d��Ԫ�سɹ�����\n�������",k);
        else
            printf("ɾ��ʧ�ܣ�");

        printf("��������ǣ�");

        Traverse_SeqList(s1);
    }

    else if(m==1)
    {
        printf("\n����ѡ��������ɾ�������������ɾ��Ԫ�ص����ݵ�ֵ��\n");
        scanf("%d",&m);
        if(Delete2_SeqList(s1,m))
            printf("ɾ��Ԫ��%d��ֵ�ɹ�����\n�������:\n",m);
        else
            printf("ɾ��ʧ�ܣ�\n");
        Traverse_SeqList(s1);
    }
    else
        printf("�������\n");


    printf("6�������������Ԫ��ֵ��");
    scanf("%d",&m);
    if(Find_SeqList(s1,m)!=ERROR)
        printf("\n���ҳɹ�\n��һ��ֵΪ %d ��Ԫ�����Ϊ %d\n",m,Find_SeqList(s1,m));
    else
        printf("\n����ʧ�ܣ�\n˳�����û��ֵΪ%d��Ԫ�ء�\n",m);

    printf("ֵΪ%d��Ԫ���� %d��\n\n",m, Count_Seqlist(s1,m));


    printf("7������˳���s2��\n");
    if(Init_SeqList(s2))printf("��ʼ����s2�ɹ���\n");

    printf("������˳���s2���ȣ�n>=0����\n");
    scanf("%d",&n);   //����˳���s2��Ԫ�ظ���

    if(Create_SeqList(s2,n)) printf("˳���s2�����ɹ�����\n\n"); ;

    printf("8���������Ӳ�����\n");

    if(Cat_SeqList(s1,s2))  printf("˳������Ӳ����ɹ�����\n�������:\n");

    Traverse_SeqList(s1);

    return 0;

}