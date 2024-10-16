//
// Created by 我的名字是Ox on 2024/9/18 018.
//
#include <stdio.h>
int main()
{
    int x; //给定一个数 判断其是否为素数
    scanf("%d",&x);
    int is_Prime = 1 ; //标识其是否为素数
    for(int i=2;i<=x-1;i++)
    {
        if(x%i==0)
        {is_Prime = 0;
            break;} //能除尽，不是素数
    }
    if(is_Prime)
        printf("%d is a Prime Num",x);
    else printf("%d is not a Prime Num",x);

    return 0;
}