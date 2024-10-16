//
// Created by 我的名字是Ox on 2023/12/27 027.
//
/*将输入的字符串中的数字字符与非数字字符分离开来，分别组成俩个字符串，并输出。
例如，输入字符串“A123B56C78D0X*+”,分离得到字符串“12356780”与“ABCDX*+” */
#include <stdio.h>

int main() {
    char input[100];
    char digits[100];
    char nonDigits[100];

    printf("请输入字符串：");
    scanf("%s", input);

    int dIndex = 0;
    int ndIndex = 0;
    int iIndex = 0;

    while (input[iIndex] != '\0')
    {
        char c = input[iIndex];

        if (c >= '0' && c <= '9')
        {
            digits[dIndex] = c;
            dIndex++; //为下次写入做准备
        }
        else
        {
            nonDigits[ndIndex] = c;
            ndIndex++;
        }
        iIndex++;
    }

    digits[dIndex] = '\0';
    nonDigits[ndIndex] = '\0';

    printf("数字字符字符串: %s\n", digits);
    printf("非数字字符字符串: %s\n", nonDigits);

    return 0;
}