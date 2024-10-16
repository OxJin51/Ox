//
// Created by 我的名字是Ox on 2024/4/27 027.
//
#include<stdlib.h>  /* stdlib.h包括函数malloc()、free()等等。*/
#include<stdio.h>
typedef int ElemType;   /* 定义链表数据元素类型ElemType，int类型 */
#define TRUE 1
#define FALSE 0
#define flag -1

typedef struct node  //单链表的结点类型
{
    ElemType data;   //数据域
    struct node *next;   //指针域
} LNode, *LinkList;   //LNode是此结构体的类型名，而LinkList是结构体指针的类型名

//普通结点Lnode 头节点 Linklist

LinkList Init_LinkList()/* 初始化单链表，建立一个空的单链表 */
{
    LinkList H=(LinkList) malloc(sizeof (LinkList));  //为头结点分配内存
    H->next=NULL;  //头结点的指针域为空，即头结点没有后继结点
    return H;
}

void Create_LinkList1(LinkList H )   /*头插法建立单链表*/
{
    LNode	*s;   //指向单链表结点的指针s
    ElemType x;  //待插入的数据元素值x
    printf("请输入单链表数据元素，以-1为结束:\n");
    scanf("%d",&x);
    while (x!=flag)
    {
        s=(LNode *) malloc(sizeof (LNode));  //为s指向的结点分配内存
        //先连后面
        s->data=x;     //设置s指向的结点的数据域为x
        s->next=H->next;    //s结点的后继结点是头结点的后继结点
        H->next=s;   //头结点的后继结点是S结点
        scanf("%d",&x);
    }
}

void Create_LinkList2( LinkList H)   /*尾插法建立单链表*/
{
    LNode	*s,*r=H;   //s指向待插入的结点，r为尾指针指向尾结点
    ElemType x;   //待插入的数据元素值x
    printf("请输入数据以-1为结束:\n");
    scanf("%d",&x);
    while (x!=flag)
    {
        s=(LNode *) malloc(sizeof(LNode));    //为s指向的结点分配内存
        s->data=x;  //设置s指向的结点的数据域为x
        s->next=NULL;  //s结点的后继结点为空值
        r->next=s;  //r结点的后继结点为s结点
        r=s;   //尾指针指向新插入进来的s结点
        scanf("%d",&x);
    }
}

void Traverse_LinkList(LinkList H)  /* 遍历单链表 */
{
    LinkList p;     //遍历是将单链表中的所有元素都依次访问一次
    p=H->next;   //p指向头结点的后继a1结点
    while (p!=NULL)   //当p结点存在
    {
        printf("%d ",p->data);  //输出p结点的值
        p=p->next;   //p指针后移
    }
    printf("\n\n");
}

int Length_LinkList (LinkList H)   /*求链表长度*/
{
    LinkList p=H;   //p指向头结点
    int j=0;   //结点计数器j归零
    while (p->next!=NULL)   //当p结点的后继结点存在
    {
        j++;   //计数器+1
        p=p->next;   //指针后移
    }
    return j;
}

LinkList Get_LinkList (LinkList H, int k)  /*按位序查找结点指针*/
{ LNode *p=H;  //p指向头结点
    int j=0;  //结点计数器j归零
    while(p->next!=NULL && j!=k)   //当p结点的后继结点存在，且计数器未达到指定位序k
    {
        j++;   //计数器+1
        p=p->next;   //指针后移
    }
    if(j==k) return p;  //当计数器达到位序要求，返回指向第k个结点的指针p
    else return NULL;
}

ElemType Get_LinkList1 (LinkList H, int k)  /*按位序查找元素值*/
{
    LNode *p=H;
    int j=0;
    while(p->next!=NULL && j!=k)
    {j++; p=p->next;}
    if(j==k) return p->data;
    else return FALSE;
}

LinkList Get_LinkList2 (LinkList H, ElemType x)  /*按值查找结点指针*/
{
    LNode *p=H->next;  //p指向头结点的后继a1结点
    while(p!=NULL &&p->data!=x)  //当p结点存在且p结点的值不等于待查找值x
        p=p->next;  //指针后移
    if(p!=NULL)  return p;
    else
    {printf("链表中不存在值为%d的元素\n",x);
        return NULL;
    }
}

int Get_LinkList3 (LinkList H, ElemType x)  /*按值查找结点位序*/
{ LNode *p=H->next;   //p指向头结点的后继a1结点
    int j=1;  //设置函数返回位序的初始值为1
    while(p!=NULL && p->data!=x)
//当p结点存在且p结点的值不等于待查找值x
    {j++; p=p->next;}
//指针后移，位序+1
    if(p->data==x) return j;
            else return FALSE;
}

int Insert_LinkList1(LinkList H, int i, ElemType x)  //在链表中第i个位置插入元素
{
    LNode *p,*s;
    int j=0;
    p=H;
    while(j!=i-1 && p!=NULL)//p指向i-1个结点(或调用Get_Linklist)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
    {printf("插入位置错");  return FALSE;}
    else
    { s=(LNode *) malloc(sizeof (LNode));  //为s结点分配空间
        s->data=x;  //将x写入s结点的数据域
        s->next=p->next;  //设置s结点的后继结点为p结点的后继结点
        p->next=s;  //设置p结点的后继为s结点
        return TRUE;
    }
}

int Del_LinkList1 (LinkList H,ElemType x)  /*按值删除节点*/
{
    LinkList pre,p;
    int j;
    pre=H;  //pre指针指向p结点的前驱，初始指向头结点
    p=H->next;  //p指针初始指向头结点的后继a1结点
    j=1;  //p结点对应的位序j
    while (p!=NULL && p->data!=x)  //当p结点存在且p结点的值不等于x
    {
        pre=pre->next;  //pre结点后移
        p=p->next;  //p结点后移
        j++;  //p结点位序+1
    }
    if (p==NULL)
    {
        printf("链表中不存在值为%d的结点\n",x);
        return FALSE;
    }
    pre->next=p->next;  //设置pre结点的后继为p结点的后继
    free(p);  //释放p结点
    return TRUE;
}

int Del_LinkList2 (LinkList H, int i)  /*按位序删除节点*/
{
    LinkList p,q;
    int j=0;
    p=H;
    while(j!=i-1 && p!=NULL)//p指向i-1个结点
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
    {printf("第%d个结点不存在\n",i-1);  return FALSE;}
    else if(p->next ==NULL)
    {printf("第%d个结点不存在\n",i);  return FALSE;}
    else
    {
       q=p->next;   //设置q指针指向p结点的后继
       p->next=q->next;  //设置p结点的后继为q结点的后继结点
        free(q);  //释放q结点
        return TRUE;
    }
}

ElemType Min_LinkList (LinkList H)  /*查找单链表最小值*/
{
    LinkList p=H->next; //p指向a1结点
    ElemType x=p->data; //设置最小值初始x等于a1结点的值
    while(p->next!=NULL) //若p存在后继结点
    {
        if(p->next->data<x)  //若p后继结点的值小于当前最小值x
         x=p->next->data; //刷新x的值
       p=p->next;  //p指针后移
    }
    return x;
}

int Cat_LinkList (LinkList H1,LinkList H2)  /*单链表链接*/
{
    LinkList p=H1; //不是H1->next;

    //定位p到H1尾结点上
    while(p->next!=NULL) p=p->next;

    p->next=H2->next;

    free(H2);
}


int main()
{
    int i,j;
    char ch;
    ElemType e;
    LinkList L;
    ElemType x;
    printf("   Created by 我的名字是Ox on 2024/4/27 027\n");
    printf("**************************************************\n");
    printf("               单 链 表 常 用 算 法\n");
    printf("**************************************************\n\n");

    printf("1、初始化单链表:设置其为空表\n");
    L=Init_LinkList();
    if(L)  printf("单链表初始化成功……\n\n");

    printf("2、创建单链表：\n");

    do
    {
        fflush(stdin);
        printf("请选择头插法（T）还是尾插法（W）： ");
        scanf("%c",&ch);
    }while(ch!='T' && ch!='t' && ch!='W' && ch!='w');

    if(ch=='T' || ch=='t')
        Create_LinkList1(L);
    else
        Create_LinkList2(L);
    printf("单链表创建成功……\n\n");

    printf("3、遍历单链表：\n");  /*依次访问单链表中所有元素*/

    Traverse_LinkList(L);

    printf("4、单链表长度为：%d\n\n",Length_LinkList(L));

    printf("5、单链表的插入操作：\n");
    printf("请输入待插入的数据及其位序(location,data)：");
    scanf("%d,%d",&i,&e);
    if(Insert_LinkList1(L,i,e)) printf("插入操作执行成功……\n操作结果：");

    Traverse_LinkList(L);

    printf("6、单链表的删除操作：\n");
    do
    {
        fflush(stdin);
        printf("请选择按值删除（Z）还是按位序删除（X）： ");
        scanf("%c",&ch);
    }while(ch!='Z' && ch!='z' && ch!='X' && ch!='x');
    if(ch=='Z' || ch=='z')
    {
        printf("请输入待删除的数据元素值：");
        scanf("%d",&x);
        if(Del_LinkList1(L,x)) printf("删除操作执行成功……\n操作结果：");
        else printf("删除操作未执行成功……\n操作结果：");
    }
    if(ch=='X' || ch=='x')
    { printf("请输入待删除的数据的位序：");
        scanf("%d",&e);
        if(Del_LinkList2(L,e)) printf("删除操作执行成功……\n操作结果：");
        else printf("删除操作未执行成功……\n操作结果：");
    }

    Traverse_LinkList(L);

    printf("7、单链表的查找操作：\n");
    do
    {
        fflush(stdin);
        printf("请选择按值查找（Z）还是按位序查找（X）： ");
        scanf("%c",&ch);
    }while(ch!='Z' && ch!='z' && ch!='X' && ch!='x');
    if(ch=='Z' || ch=='z')
    {
        printf("请输入待查找的数据元素值：");
        scanf("%d",&x);
        if(Get_LinkList3(L,x)) printf("待查找的值为%d数据元素的位序为：%d\n\n",x,Get_LinkList3(L,x));
        else printf("待查找的值为%d数据元素不存在\n\n",x);
    }
    if(ch=='X' || ch=='x')
    { do
        { printf("请输入待查找的数据元素的位序（1~%d）：", Length_LinkList(L));
            scanf("%d",&i);
        } while(i<1||i> Length_LinkList(L));
        x=Get_LinkList1(L,i);
        printf("待查找的位序为%d数据元素值为：%d \n\n",i,x);
    }

    printf("8、单链表的最小值：");
    printf("%d\n\n", Min_LinkList(L));

    return 0;
}


