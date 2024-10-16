//
// Created by 我的名字是Ox on 2023/12/27 027.
//
/*打印九九乘法表。（此题不用数组）*/
#include<stdio.h>
int main() {
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d*%d=%2d;",j,i,i*j); //怎么样才能对齐？

        }
        printf("\n");
    }

    return 0;
}