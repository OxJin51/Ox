//
// Created by 我的名字是Ox on 2023/12/30 030.
//
/*键盘输入一个实数，求解该数对应的二、八和十六进制数（转换进制后，小数位保留6位。不使用数组）*/
#include <stdio.h>

void printBinary(double num)
{
    printf("二进制表示：");
    long long intPart = (long long)num;
    double fracPart = num - intPart;

    // 输出整数部分的二进制表示
    while (intPart > 0)
    {
        printf("%lld", intPart % 2);
        intPart /= 2;
    }

    printf(".");

    // 输出小数部分的二进制表示
    int count = 0;
    while (fracPart > 0 && count < 6) {
        fracPart *= 2;
        printf("%d", (int)fracPart);
        fracPart -= (int)fracPart;
        count++;
    }

    printf("\n");
}

void printOctal(double num) {
    printf("八进制表示：");
    long long intPart = (long long)num;
    double fracPart = num - intPart;

    // 输出整数部分的八进制表示
    while (intPart > 0) {
        printf("%lld", intPart % 8);
        intPart /= 8;
    }

    printf(".");

    // 输出小数部分的八进制表示
    int count = 0;
    while (fracPart > 0 && count < 6) {
        fracPart *= 8;
        printf("%d", (int)fracPart);
        fracPart -= (int)fracPart;
        count++;
    }

    printf("\n");
}

void printHexadecimal(double num) {
    printf("十六进制表示：");
    long long intPart = (long long)num;
    double fracPart = num - intPart;

    // 输出整数部分的十六进制表示
    while (intPart > 0) {
        int remainder = intPart % 16;
        if (remainder < 10) {
            printf("%c", '0' + remainder);
        } else {
            printf("%c", 'A' + remainder - 10);
        }
        intPart /= 16;
    }

    printf(".");

    // 输出小数部分的十六进制表示
    int count = 0;
    while (fracPart > 0 && count < 6) {
        fracPart *= 16;
        int digit = (int)fracPart;
        if (digit < 10) {
            printf("%d", digit);
        } else {
            printf("%c", 'A' + digit - 10);
        }
        fracPart -= digit;
        count++;
    }

    printf("\n");
}

int main() {
    double input;

    // 输入实数
    printf("请输入一个实数： ");
    scanf("%lf", &input);

    // 输出各种进制表示
    printBinary(input);
    printOctal(input);
    printHexadecimal(input);

    return 0;
}
