//
// Created by 我的名字是Ox on 2023/12/30 030.
//
/*编程从键盘输入4个整数a、b和c，d，、使用if语句，判断并输出三4个数中的最大值。
输出结果控制：MAX=15*/
#include <stdio.h>

int main()
{
    int a, b, c, d;

    // 输入4个整数
    printf("请输入四个整数（以空格分隔）： ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // 判断最大值
    int max = a;  // 假设a是最大值

    if (b > max)
    {
        max = b;
    }

    if (c > max)
    {
        max = c;
    }

    if (d > max)
    {
        max = d;
    }

    // 输出结果
    printf("MAX=%d\n", max);

    return 0;
}
