//
// Created by 我的名字是Ox on 2023/12/19 019.
//
/*编写一个函数int fun(int n,int k)实现n^k（n的k次方），n和k从键盘输入，使用递归实现。在主函数中调用子函数。*/
#include<stdio.h>
int fun(int n,int k)   /*函数首部*/
{
    int s=1;
   if(k==0)
    {s=1;}
   else
    {s=n*fun(n,k-1);}
    return s;
}
void  main()
{
    /*函数声明*/
    int fun(int n,int k);
    int x,y,z;
    scanf("%d%d",&x,&y);
    z=fun(x,y);   /*调用函数*/
    printf("%d^%d=%d\n",x,y,z);
}
