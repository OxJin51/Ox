//
// Created by 我的名字是Ox on 2024/3/14 014.
//
#include<iostream>
#define MAXSIZE 1000
using namespace std;
struct list
        {
         int elem[MAXSIZE];
         int length;
        };
typedef struct list Sqlist; //给struct list起个别名Sqlist

//顺序表的初始化
void Init_Sqlist(struct list *L)
{
    L->length = 0; //顺序表中对象置零
}

//顺序表的插入

/*①尾插法*/
int Insert_Sqlist_end(Sqlist &L , int x)
{
    if(L.length==MAXSIZE) return 0; // 表满，插入失败
    L.elem[L.length]=x; //x拆入表尾
    L.length++;  //表长+1
    /*可合并为 L.elem[L.length++];*/
    return 1;  //插入成功
}
/*②头插法*/
int Insert_Sqlist_head(Sqlist *L , int x)
{
    if(L->length==MAXSIZE) return 0; //表满，插入失败
    for(int i=L->length;i>=0;i--) L->elem[i+1]=L->elem[i]; //后移
    L->elem[0]=x;  //x插入表头
    L->length++;   //表长+1
    return 1; //插入成功
}
/*③中间插法*/
int Insert_Sqlist_in(Sqlist *L , int i , int x)
{
    if(L->length==MAXSIZE||i<1||i>L->length) //表满或非法，插入失败
        return 0;
    for(int j=L->length-1;j>=i-1;j--) L->elem[j+1]=L->elem[j]; //后移
    L->elem[i-1]=x; //插入x
    L->length++;    //表长+1
    return 1;       //成功
}
int main()
{
    Sqlist l;
    Init_Sqlist (&l);
    cout<<"enter the length"<<endl;
    cin>>l.length;
    for(int i=0;i<l.length;i++) cin>>l.elem[i];

    Insert_Sqlist_in(&l,3,114514);

    for(int i=0;i<l.length;i++) cout<<l.elem[i]<<' ';

    return 0;
}





