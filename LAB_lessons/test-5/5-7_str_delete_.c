//
// Created by 我的名字是Ox on 2024/1/9 009.
//
#include <stdio.h>

int main() {
    char str[100];

    // 输入字符串
    printf("请输入一个字符串：");
    scanf("%99[^\n]", str);  // 限制输入的最大字符数为99，避免溢出

    // 删除数字字符
    int i = 0,j;
    while (str[i] != '\0') //遍历整个字符串
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            // 如果是数字字符，删除它
            for (j = i; str[j] != '\0'; j++)
            {
                str[j] = str[j + 1];
            }
        }
        else
          {i++;}
    }

    // 输出删除数字字符后的字符串
    printf("删除数字字符后的字符串：%s\n", str);

    return 0;
}
