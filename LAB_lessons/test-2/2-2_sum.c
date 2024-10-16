//
// Created by 我的名字是Ox on 2023/12/30 030.
//
/*根据下式求s的值（要求使用循环实现）：*/
#include <stdio.h>

int main() {
    int n = 20;
    double s = 0.0;
    double term = 1.0;

    for (int i = 0; i <= n; i++)
    {
        s += term;
        term /= 3.0;
    }

    printf("s的值为：%f\n", s);

    return 0;
}
