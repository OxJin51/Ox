//
// Created by 我的名字是Ox on 2023/12/30 030.
//
/*打印π的值 格式分别为：%f,   %9.4f    %-9.4f    %3f  %-3f*/
#include <stdio.h>

int main()
{
    double pi = 3.14159265358979323846;

    printf("%f\n", pi);
    printf("%9.4f\n", pi);
    printf("%-9.4f\n", pi);
    printf("%3f\n", pi);
    printf("%-3f\n", pi);

    return 0;
}
