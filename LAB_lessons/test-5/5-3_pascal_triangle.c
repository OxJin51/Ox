//
// Created by 我的名字是Ox on 2023/12/27 027.
//
/*打印杨辉三角（10行）*/
#include<stdio.h>
int main()
{
    int a[10][10];
    int i, j;
    for (i = 0; i < 10; i++)
    {
        a[i][0] = 1; //第一列元素均为1；
        a[i][i] = 1; //每一行最后一个为0；
    }
    //计算其它元素
    for (i = 2; i < 10; i++)
    {
        for (j = 1; j <= i - 1; j++)
        {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
    //打印杨辉三角
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}