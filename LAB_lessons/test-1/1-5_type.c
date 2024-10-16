//
// Created by 我的名字是Ox on 2023/12/30 030.
//
/*使用if语句，实现判断输入内容的类别（通过键盘输入符号）
输出结果样例：A是一个大写字母，a是一个小写字母，8是一个数字，*是一个其他符号。*/

#include <stdio.h>

int main()
{
    char symbol;

    // 输入符号
    printf("请输入一个符号： ");
    scanf("%c", &symbol);

    // 判断输入内容的类别
    if ((symbol >= 'A' && symbol <= 'Z'))
    {
        printf("%c是一个大写字母。\n", symbol);
    }
    else if (symbol >= 'a' && symbol <= 'z')
    {
        printf("%c是一个小写字母。\n", symbol);
    }
    else if (symbol >= '0' && symbol <= '9')
    {
        printf("%c是一个数字。\n", symbol);
    }
    else
    {
        printf("%c是一个其他符号。\n", symbol);
    }

    return 0;
}

