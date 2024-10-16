//
// Created by 我的名字是Ox on 2023/12/27 027.
//
/*编程实现以下功能：
（1）输入一个字符串；
（2）在其中所有的数字字符前加上*字符；
（3）输出变换后的字符串；
举例说明：若输入字符串为A1B23C456，则输出为A*1B*2*3C*4*5*6*/
#include <stdio.h>
#include <string.h>

int main() {
    char inputString[100];

    // 输入字符串
    printf("请输入一个字符串：");
    scanf("%s", inputString);

    // 变换字符串
    for (int i = 0; i < strlen(inputString); i++)
    {
        if (inputString[i] >= '0' && inputString[i] <= '9')
        {
            // 如果是数字字符，插入'*'字符
            for (int j = strlen(inputString); j > i; j--)
            {
                inputString[j] = inputString[j - 1];
            }
            inputString[i] = '*';
            i++; // 跳过刚插入的'*'字符，避免重复插入
        }
    }

    // 输出变换后的字符串
    printf("变换后的字符串：%s\n", inputString);

    return 0;
}

