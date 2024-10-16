//
// Created by 我的名字是Ox on 2023/12/19 019.
//
/*定义一个名为prime的子函数，功能是判断一个正整数是否是素数。使用main函数调用该函数实现素数的判断。*/
#include<stdio.h>

// 判断一个数是否为素数的函数
#include <stdio.h>
int Prime(int num) {
    if (num <= 1)
    {
        return 0; // 0和1不是素数
    }
    int i;
    for (i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0; // 如果num能被2到sqrt(num)之间的任何数整除，那么它不是素数
        }
    }

    return 1; // 如果没有找到除数，它是素数
}
int main()
{
    int Prime(int num);
    int x;
    scanf("%d",&x);
    if(Prime(x))
        printf("%d是素数",x);
    else
        printf("%d不是素数",x);
    return 0;
}

