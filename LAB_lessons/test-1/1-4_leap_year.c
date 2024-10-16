//
// Created by 我的名字是Ox on 2023/12/30 030.
//
#include <stdio.h>

int main()
{
    int year;

    // 输入年份
    printf("请输入一个正整数年份： ");
    scanf("%d", &year);

    // 判断是否为闰年
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        printf("%d is a leap year.\n", year);
    }
    else
    {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
}
