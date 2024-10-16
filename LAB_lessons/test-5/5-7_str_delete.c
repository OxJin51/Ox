//
// Created by 我的名字是Ox on 2023/12/27 027.
//
/*键盘输入一个字符串，删除字符串中所有数字字符。（要求：在原字符串中进行删除操作）*/
#include <stdio.h>

int main() {
    char input[1000];

    // 输入字符串
    printf("请输入字符串：");
    fgets(input, sizeof(input), stdin);

    // 删除字符串中的数字字符
    int i, j;
    for (i = j = 0; input[i] != '\0'; i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            input[j++] = input[i];
        }
    }

    input[j] = '\0';

    // 输出处理后的字符串
    printf("删除数字后的字符串：%s\n", input);

    return 0;
}

