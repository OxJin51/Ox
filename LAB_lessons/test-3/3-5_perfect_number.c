//
// Created by 我的名字是Ox on 2023/12/30 030.
//
/*打印1000以为的完数。完数是一个整数，等于其因子之和。
例如：6=1+2+3，则6是完数。
输出格式：6是完数，其因子为1  2  3
（一个完数信息占用一行）*/
#include <stdio.h>

int main() {
    int sum = 0,num=1,i;
    for (num = 1; num <= 1000; num++)
    {


        for (i = 1; i <= num-1; i++)
        {
            if (num % i == 0)
            {
                sum += i;
            }
        }

        if (sum == num)
        {
            printf("%d是完数，其因子为1", num);

            for (i = 1; i <= num-1; i++) {
                if (num % i == 0)
                {
                    printf("  %d", i);
                }
            }

            printf("\n");
        }
    }

    return 0;
}
