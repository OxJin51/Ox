//
// Created by 我的名字是Ox on 2023/12/27 027.
//
/*键盘输入一个十六进制数字的字符串转换成与它等价的十进制整数值。十六进制允许的字符是从：0~9和A~F或a~f。（不得直接调用C语言的十六进制转换函数）*/
#include <stdio.h>

int main() {
    char hex[100];
    printf("请输入一个十六进制数字字符串：");
    scanf("%s", hex);

    int decimal = 0;
    int base = 1;
    int length = 0;
    while (hex[length] != '\0') {
        length++;
    }

    for (int i = length - 1; i >= 0; i--) {
        int digitValue;
        if (hex[i] >= '0' && hex[i] <= '9') {
            digitValue = hex[i] - '0';
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digitValue = hex[i] - 'A' + 10;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            digitValue = hex[i] - 'a' + 10;
        }
        else {
            printf("输入无效的十六进制数字！\n");
            return 0;
        }

        decimal += digitValue * base;
        base *= 16;
    }

    printf("转换为十进制的值为：%d\n", decimal);

    return 0;
}