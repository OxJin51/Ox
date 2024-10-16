//
// Created by 我的名字是Ox on 2023/12/13 013.
//
//给定两个点 P1
// 和 P2
//，其中 P1
// 的坐标为 (x1,y1)
//，P2
// 的坐标为 (x2,y2)
//，请你计算两点间的距离是多少
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    double x1,y1;
    double x2,y2;
    double d;

    cin >> x1 >>y1;
    cin >> x2 >>y2;

    d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2); //加乘号！！
    printf("%lf",sqrt(d));
    return 0;
}