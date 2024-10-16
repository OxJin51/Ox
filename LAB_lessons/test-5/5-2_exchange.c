//
// Created by 我的名字是Ox on 2023/12/27 027.
//
/*键盘输入3*3的二维整型数组的数值，然后转置，即行列互换，结果仍然存入原来数组中。*/
#include<stdio.h>

int main() {
    int i, j;
    int a[3][3];
    //数组输入
    for (i = 0; i <= 2; i++)
    {
        for (j = 0; j <= 2; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    //转置
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) {
            int t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
    }

    //输出新的数组
    for (i = 0; i <= 9; i++)
    {
        for (j = 0; j <= 2; j++)
        {
            printf("%d",a[i][j]);
        }
    }
    return 0;
}