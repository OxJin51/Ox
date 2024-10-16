//
// Created by 我的名字是Ox on 2023/12/30 030.
//
/*输出100以内能被3整除且个位数为6的所有整数及之和*/
#include <stdio.h>

int main() {
    int sum = 0;
    int i;

    printf("100以内能被3整除且个位数为6的整数有：\n");

    for (i = 6; i < 100; i += 10)
    {
        if (i % 3 == 0)
        {
            printf("%d ", i);
            sum += i;
        }
    }

    printf("\n它们的和为：%d\n", sum);

    return 0;
}

