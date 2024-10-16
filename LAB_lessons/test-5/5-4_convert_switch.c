//
// Created by 我的名字是Ox on 2023/12/27 027.
//
/*键盘输入一个十六进制数字的字符串转换成与它等价的十进制整数值。十六进制允许的字符是从：0~9和A~F或a~f。（不得直接调用C语言的十六进制转换函数）*/
#include <stdio.h>

int main() {
    char hex[100]; //hex：字符数组，用于存储从键盘输入的十六进制数字字符串
    printf("请输入一个十六进制数字字符串：");
    scanf("%s", hex);

    int decimal = 0; //decimal：整数变量，用于存储转换后的十进制整数值
    int base = 1; //base：整数变量，表示当前位数的权重
    int length = 0; //length：整数变量，表示输入的十六进制数字字符串的长度
    while (hex[length] != '\0') {
        length++;
    }

    for (int i = length - 1; i >= 0; i--) {
        int digitValue;
        switch (hex[i]) {
            case '0':digitValue = 0;break;
            case '1':digitValue = 1;break;
            case '2':digitValue = 2;break;
            case '3':digitValue = 3;break;
            case '4':digitValue = 4;break;
            case '5':digitValue = 5;break;
            case '6':digitValue = 6;break;
            case '7':digitValue = 7;break;
            case '8':digitValue = 8;break;
            case '9':digitValue = 9;break;

            case 'A':case 'a':digitValue = 10;break;
            case 'B':case 'b':digitValue = 11;break;
            case 'C':case 'c':digitValue = 12;break;
            case 'D':case 'd':digitValue = 13;break;
            case 'E':case 'e':digitValue = 14;break;
            case 'F':case 'f':digitValue = 15;break;
            default:printf("输入无效的十六进制数字！\n");
                return 0;
        }

        decimal += digitValue * base;
        base *= 16;
    }

    printf("转换为十进制的值为：%d\n", decimal);

    return 0;
}