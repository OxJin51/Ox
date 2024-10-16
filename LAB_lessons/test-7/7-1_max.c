//
// Created by 我的名字是Ox on 2023/12/19 019.
//
/*定义一个子函数max，功能是求解两个数中的最大数。*/
#include <stdio.h>
//求解两个数中的最大数
int max(int a,int b) //自定义函数
{ int max;
    if(a>b)
        max=a;
    else
        max=b;
    return max;
}
   //习惯
int main() //主函数
{
    //函数声明
    int max(int a,int b);

printf("输入两个数字\n");
int x,y,z;
scanf("%d%d",&x,&y);
z=max(x,y);
printf("max=%d\n",z);
    return 0;
}