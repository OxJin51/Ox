//
// Created by 我的名字是Ox on 2024/9/18 018.
//
#include<stdio.h>
#include<math.h> //数学库
int main()
{
    double a,b,c;

    scanf("%lf%lf%lf",&a,&b,&c); //输入

    double s,k;
    k = (a+b+c)/2; //注意结合优先级 加括号
    s = sqrt(k*(k-a)*(k-b)*(k-c));
   // printf("%lf\n",k*(k-a)*(k-b)*(k-c));
    printf("%lf",s);
    return 0;
}