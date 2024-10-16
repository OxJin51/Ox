//
// Created by 我的名字是Ox on 2023/12/30 030.
//
/*输入两个正整数a和b，如果a能被b整除，输出商，否则输出商和余数。*/
#include <stdio.h>

int main() {
    int a, b;

    // 输入两个正整数
    printf("请输入两个正整数a和b（以空格分隔）： ");
    scanf("%d %d", &a, &b);

    // 判断是否a能被b整除
    if (b != 0)
    {
        if (a % b == 0)
            {
            printf("%d 能被 %d 整除，商为 %d\n", a, b, a / b);
            } else
               {
                 printf("%d 除以 %d 的商为 %d，余数为 %d\n", a, b, a / b, a % b);
               }
    }
    else
      {
        printf("除数不能为零，请输入一个非零的除数。\n");
      }

    return 0;
}

