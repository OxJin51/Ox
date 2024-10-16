#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define TRUE 1

#define MAXSIZE 20     /*顺序表最大容量*/
typedef  int ElemType;  /*定义表元素的类型*/

/*顺序表类型定义*/
struct list
{
    ElemType elem[MAXSIZE];  /*存储空间的基地址，即存储线性表中元素的存储空间及大小*/
    int length;           /*顺序表的当前长度*/
};
typedef struct list  SeqList;/*顺序表类型再命名(不带*)*/

int Init_SeqList(SeqList *L); /*初始化顺序表*/
int Create_SeqList(SeqList *L,int n); /*创建顺序表*/
int Insert_SeqList(SeqList *L,int i,ElemType x);/*顺序表的插入操作*/
int Traverse_SeqList(SeqList *L);  /*顺序表的遍历*/
int Delete1_SeqList(SeqList *L,int i); /*顺序表的按序号删除操作*/
int Delete2_SeqList(SeqList *L,ElemType x); /*顺序表的按数据删除操作*/
int Find_SeqList(SeqList *L,ElemType x); /*查找值为x的元素*/
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

/*初始化顺序表*/
int Init_SeqList(SeqList *L)
{
    L->length=0; 		/*空表长度为0*/
    return TRUE;
}/*InitList*/

/*创建顺序表，向顺序表中输入n个数据*/
int Create_SeqList(SeqList *L,int n)
{
    ElemType x; //x为待存入的值
    int i;
    if(n>MAXSIZE) return ERROR; /*n超出最大容量*/
    for(i=0;i<n;i++)
    {
        printf("请输入第% d个数据：",i+1);
        scanf("%d",&x);
        L->elem[L->length++]=x;  /*把数据存入顺序表(先存再加)*/
    }
    return TRUE;
}/*CreateList*/

/*遍历顺序表*/
int Traverse_SeqList(SeqList *L)
{
    int i;
    for(i=0;i<L->length;i++) printf("%-7d",L->elem[i]);/*从前向后依次输出顺序表中的元素*/
    printf("\n\n");
    return TRUE;
}/*TraverseList*/

/*在顺序表L中，序号i的位置上插入值为x的元素*/
int Insert_SeqList(SeqList *L,int i,ElemType x)
{
    int j;
    if(i<1||i>L->length) /*序号i溢出*/
    {
        printf("序号%d溢出\n",i);
        return ERROR;
    }
    if(L->length==MAXSIZE)  return ERROR;
    for(j=L->length-1;j>=i-1;j--)  L->elem[j+1]=L->elem[j]; //不是>i!
    L->elem[i-1]=x;
    L->length++;
    return TRUE;
}
/*ListInsert*/

/*在顺序表中按照序号删除对象，即删除第i个元素*/
int Delete1_SeqList(SeqList *L,int i)
{
    int j;
    if(i<1||i>L->length) /*序号i溢出*/
    {
        printf("序号%d溢出\n",i);
        return ERROR;
    }
    /*删除第i号元素*/
    for(j=i;j<L->length;j++) L->elem[j-1]=L->elem[j];
    L->length--;
    return TRUE;
}/*Delete1_*/

/*在顺序表中按照数据删除对象，即(第一个)删除值为x的元素*/
int Delete2_SeqList(SeqList *L,ElemType x)
{
    int i,j;
    for(i=0;i<L->length;i++)/*查找数据x的位置*/
    {
        if(L->elem[i]==x) break;
    }
    if(i==L->length)  return ERROR;  /*s顺序表中没有值为x的对象*/
    for(j=i+1;j<L->length;j++) L->elem[j-1]=L->elem[j]; /*删除值为x的对象*/
    L->length--;
    return TRUE;
}/*Delete2*/

void Delete3_SeqList(SeqList *L,ElemType x)
{
    int i,j;
    for(i=0;i<L->length;i++)/*查找数据x的位置*/
    {
        if(L->elem[i]==x)
        {
            for(j=i+1;j<L->length;j++) //删除元素（一次循环删除一个）
            {
                L->elem[j-1]=L->elem[j];
                L->length--;
            }

            i--;  //回退检查
        }
    }



}/*Delete2*/


/*在顺序表中查找指定值元素，返回其序号，若没有返回ERROR*/
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

/*顺序表链接，把表s2连接在s1的后面，失败返回0*/
int Cat_SeqList(SeqList *L1,SeqList *L2)
{
    int i;
    if(L1->length+L2->length>MAXSIZE) return ERROR; /*溢出，无法连接*/

    for(i=0;i<L2->length;i++) L1->elem[L1->length+i]=L2->elem[i];
    L1->length+=L2->length;
    return TRUE;

}/*Cat*/

int main( )
{
    struct list *s1,*s2; //*s1 (s1)不是(&s1)
    int n,m,k;
    char c;
    printf("Created by 我的名字是Ox on 2024/4/23 023.\n\n");
    printf("**************************************************\n");
    printf("               顺 序 表 常 用 算 法\n");
    printf("**************************************************\n\n");

    s1=(SeqList *)malloc(sizeof(SeqList));	/*建立顺序表sl，为sl开辟存储空间*/
    s2=(SeqList *)malloc(sizeof(SeqList));	/*建立顺序表sl，为s2开辟存储空间*/

    printf("1、初始化线性表:设置表长为0\n");
    if(Init_SeqList(s1))  printf("顺序表初始化成功……\n\n");

    printf("2、创建顺序表：\n");
    do
    {
        printf("请输入顺序表长度（n>=0）: ");
        scanf("%d",&n);   /*输入顺序表的元素个数*/
    }
    while (n<0);
    if(Create_SeqList(s1,n)) printf("\n顺序表创建成功……\n\n"); ;

    printf("3、遍历顺序表：\n");  /*依次访问顺序表中所有元素*/

    Traverse_SeqList(s1);

    printf("4、顺序表的插入操作：\n");
    printf("请输入待插入的位序：");
    scanf("%d",&m);
    printf("请输入待插入的数据：");
    scanf("%d",&k);
    if(Insert_SeqList(s1,m,k)) printf("插入操作执行成功……\n操作结果：");

    Traverse_SeqList(s1);

    printf("5、请输入删除方式，1表示按内容删除，2表示按序号删除\n");
    scanf("%d",&m);
    if(m==2)
    {
        printf("您是选择按照序号删除对象，请输入带删除元素的序号：");
        scanf("%d",&k);
        if(Delete1_SeqList(s1,k))
            printf("删除第%d号元素成功……\n操作结果",k);
        else
            printf("删除失败！");

        printf("操作结果是：");

        Traverse_SeqList(s1);
    }

    else if(m==1)
    {
        printf("\n您是选择按照内容删除对象，请输入待删除元素的数据的值：\n");
        scanf("%d",&m);
        if(Delete2_SeqList(s1,m))
            printf("删除元素%d的值成功……\n操作结果:\n",m);
        else
            printf("删除失败！\n");
        Traverse_SeqList(s1);
    }
    else
        printf("输入错误！\n");


    printf("6、请输入待查找元素值：");
    scanf("%d",&m);
    if(Find_SeqList(s1,m)!=ERROR)
        printf("\n查找成功\n第一个值为 %d 的元素序号为 %d\n",m,Find_SeqList(s1,m));
    else
        printf("\n查找失败！\n顺序表中没有值为%d的元素。\n",m);

    printf("值为%d的元素有 %d个\n\n",m, Count_Seqlist(s1,m));


    printf("7、创建顺序表s2：\n");
    if(Init_SeqList(s2))printf("初始化表s2成功！\n");

    printf("请输入顺序表s2长度（n>=0）：\n");
    scanf("%d",&n);   //输入顺序表s2的元素个数

    if(Create_SeqList(s2,n)) printf("顺序表s2创建成功……\n\n"); ;

    printf("8、序表的连接操作：\n");

    if(Cat_SeqList(s1,s2))  printf("顺序表链接操作成功……\n操作结果:\n");

    Traverse_SeqList(s1);

    return 0;

}