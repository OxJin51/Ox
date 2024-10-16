//
// Created by 我的名字是Ox on 2024/9/18 018.
//
#include<stdio.h>
int main()
{
    double f; //华氏温度
    double c;
    scanf("%lf",&f); //输入
    c = 5.0/9 * (f-32); //计算（转换） 补.0 转化为实型（浮点型）
    printf("%lf",c);
    return 0;
}