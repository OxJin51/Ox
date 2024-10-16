//
// Created by 我的名字是Ox on 2023/12/27 027.
//
/*将长整型数 s 中每一位上为偶数的数码依次取出，构成一个新数放在 t 中。高位仍放在高位，低位仍放在低位。（此题不用数组）
s由键盘输入 例：s=123456789  t=2468*/
#include <stdio.h>

int main() {
    long s;
    long t = 0;
    long multiplier = 1;

    printf("请输入一个长整型数：");
    scanf("%ld", &s);

    for (; s != 0; s /= 10)
    {
        int digit = s % 10;  // 取出最低位的数码

        if (digit % 2 == 0)
        {
            t += digit * multiplier;  // 将偶数数码加入新数中
            multiplier *= 10;  // 更新放置新数的位数
        }
    }

    // 输出新数
    printf("提取出的偶数数码为：%ld\n", t);

    return 0;
}