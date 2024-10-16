//
// Created by 我的名字是Ox on 2024/3/18 018.
//
#include<iostream>
#define MAXSIZE 1000
using namespace std;
typedef struct list Sqlist; //给struct list起个别名Sqlist
struct list
{
    int elem[MAXSIZE];
    int length;
};

void Init_Sqlist(struct list *L)
{
    L->length = 0; //顺序表中对象置零
}

int main()
{

    Sqlist l;
    Init_Sqlist (&l);
    cout<<"enter the length"<<endl;
    cin>>l.length;
    for(int i=0;i<l.length;i++) cin>>l.elem[i];

    int x,j=0; cin>>x;
    //思路：i便
    for(int i=0;i<l.length;i++) //i用作遍历顺序表
    {
        if(l.elem[i]!=x)
        {
            l.elem[j]=l.elem[i];
            j++;
        }
        else l.length--;
    }


    for(int i=0;i<l.length;i++) cout<<l.elem[i]<<' ';

    puts("");


    return 0;
}
