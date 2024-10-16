//
// Created by 我的名字是Ox on 2023/12/19 019.
//
/*编写一个函数int fun(int n,int k)实现n^k（n的k次方），n和k从键盘输入，使用递归实现。在主函数中调用子函数。*/
#include<stdio.h>
int fun(int n,int k)   /*函数首部*/
{
    int s=1;
    for (int i = 1; i<=k; i++)
    {
        s=s*n;
    }
    return s;
}
void  main()
{
    int x,y,z;
    scanf("%d%d",&x,&y);
    z=fun(x,y);   /*调用函数*/
    printf("%d^%d=%d\n",x,y,z);
}
