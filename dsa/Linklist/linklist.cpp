//
// Created by 我的名字是Ox on 2024/3/30 030.
//
#include<iostream>
#include<cstdlib>
using namespace std;
//单链表
struct node
{
    int data; //数据域
    struct node * next;  //地址域
};
typedef struct node Lnode,*Linklist; //取两个别名
//双向链表
struct Doubly_node
{
    int data;
    struct Doubly_node *prior; //存直接前驱地址
    struct Doubly_node *next;
};
//初始化(返回链表的头节点)
Linklist Init_Linklist()
{
    Linklist H;
    //为H开辟空间，即产生一个结点给H
    H=(Linklist)malloc(sizeof (Linklist)); //Linklist本身为指针变量
    H->next=NULL;  //设置H后继为空
    return H;
}
//插入

/*(1)头插法*/
/*在名为H的单链表首元素节点前。插入一个值为x的结点*/
void Insert_Linklist_Head(Linklist H,int x)
{
    Linklist q; //创建新结点

    //插入操作
    q=(Linklist ) malloc(sizeof (Linklist));  //1.开辟结点q，用于操作

    q->data = x;  //2.值存入q

    q->next = H->next;  //3.q的指针指向首元素

    H->next = q;  //4.H的指针指向q

}

/*(2)尾插法*/
/*在名为H的链表的尾元素后插入一个值为x的结点*/
void Insert_Linklist_Last(Linklist H,int x)
{
    Linklist p=H,q;
    //p做索引，用于遍历到尾结点，q为待插入结点

    while(p->next!=NULL) p=p->next; //找到尾结点 p->next=NULL

    //插入操作
    q=(Linklist ) malloc(sizeof (Linklist));  //1.开辟结点q，用于操作

    q->data = x;  //2.值存入q

    q->next = NULL;  //3.q的指针指向NUL

    p->next = q;  //4.H的指针指向q

}
/*(3)中间插入*/

/*①指定位置*/
/*在单链表H中，第i个元素结点后插入一个值为x的结点|成功返回1，失败返回0*/
int Insert_Linklist_Last_Mid_Position(Linklist H,int i,int x)
{
    int j; //索引
    Linklist p=H,q;
    if(i<1) return 0; //i不合法,插入失败
    for(j=0; j<i&&p!=NULL; j++,p=p->next) ;
    if(p==NULL) return 0; //表短了，找不到i
    if(j==i)
    {
        //插入操作
        q=(Linklist ) malloc(sizeof (Linklist));  //1.开辟结点q，用于操作

        q->data = x;  //2.值存入q

        q->next = p->next;  //3.q的指针指向NUL

        p->next = q;  //4.H的指针指向q

        return 1;
    }
}

/*②指定值*/
/*在单链表H中，所有值为x的结点后插入一个值为y的结点|成功返回1，失败返回0*/
void Insert_Linklist_Last_Mid_Val(Linklist H,int x,int y)
{
    Linklist p=H->next,q; //p作索引，q为待插入结点
    while(p!=NULL) //查到尾结点前即可，此时p->next==NULL; 即p的下一位是尾结点
    {
        if(p->data == x) //找到
        {
            //插入操作
            q=(Linklist ) malloc(sizeof (Linklist));  //1.开辟结点q，用于操作

            q->data = y;  //2.值存入q

            q->next = p->next;  //3.q的指针指向NUL

            p->next = q;  //4.H的指针指向q
        }

        p=p->next; //或p=q; 少查一次
    }
}

/*③查找*/
/*查找单链表H中第i个元素值*/

int Search_Linklist(Linklist H,int i)
{
    Linklist p = H; //H而不是H->next 防止空表

    int idx=0;

    while(p!=NULL && idx<i)
    {
        p=p->next;
        idx++;
    }

    if(idx==i&&p!=NULL) return p->data;

    else                return -1; //NULL
}

/*（2）统计链表H的长度（不包括头节点）*/

int Length_Linklist(Linklist H)
{
    int idx=0;
    Linklist p=H->next;
    while(p!=NULL) {idx++; p=p->next;} //p==NULL 结束
    return idx;
}

/*(3)统计链表H中，值为x的个数*/
int Count_Linklist(Linklist H,int x)
{
    int cnt=0; Linklist p=H->next;
    while(p!=NULL)
    {
        if(p->data==x) cnt++;
        p=p->next; //指针一定要后移（在if约束外）
    }
    return cnt;
}

/*④删除*/
/*（1）按地址*/
/*删除单链表H中，第i个节点 成功返回1，失败返回0*/
int Delete_Linklist_Position(Linklist H,int i)
{
    Linklist p=H,q;
    int idx=0; //记录遍历了多少个结点
    //定位p到i-1号
    while(idx<i-1&&p->next!=NULL)
    {
        if(idx==i-1) break;

        idx++; p=p->next;
    }

    if(idx<i-1) return 0;

    //删除
    q=p->next; //q定位到待删结点

    p->next=p->next->next;

    free(q);

    return 1;
}

/*（2）删除单链表H中。所有值为x的元素*/
void Delete_Linklist_Val(Linklist H,int x)
{
    Linklist p=H,q;

    while(p->next!=NULL) //尾结点一定不是x
    {
        if(p->next->data == x)
        {
            q=p->next; //定位到x前结点
            p->next=p->next->next;
            free(q);
        }
        else p=p->next; //没找到x，指针后移（没删的情况下）
    }
}

/*⑤合并*/
/*将单链表HB合并到HA后面*/
void Merge_Linklist(Linklist HA,Linklist HB)
{
    Linklist p=HA; //不是HA->next;

    //定位p到HA尾结点上
    while(p->next!=NULL) p=p->next;

    p->next=HB->next;

    free(HB);

}
/*把递增有序的单链表HA与HB合并为一个单链表，仍递增有序，名称为HA*/
void Merge_Linklist_Ordered_BF(Linklist HA,Linklist HB)
{
    //在HB中找，并插入（在HA中找位置|第一个小于的）
    Linklist pa=HA,pb=HB,q;
    while(pb!=NULL)
    {
        q=pb->next;
        while(pa->next!=NULL)
        {
            if(pa->next->data>pb->data) break; //找到插入点
            else pa=pa->next;
        }
        //插入
        pb->next=pa->next;
        pa->next=pb;
        pb=q;
    }
}

void Merge_Linklist_Ordered(Linklist HA,Linklist HB)
{
    Linklist pa=HA->next,pb=HB->next,q=HA;
    while(pa!=NULL && pb!=NULL)
    {
        if(pa->data<pb->data)
        {
            q->next=pa;
            pa=pa->next;
        }
        else
        {
            q->next=pb;
            pb=pb->next;
            q=q->next;
        }
    }

    if(pa==NULL) q->next=pb;
    else q->next=pa;
}

int main()
{

    return 0;
}