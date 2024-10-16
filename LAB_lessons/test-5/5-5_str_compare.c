//
// Created by 我的名字是Ox on 2023/12/27 027.
//
/*从键盘输入两个字符串，比较大小。（不使用字符串比较函数）*/
#include <stdio.h>

int main()
{
    char str1[100];
    char str2[100];

    printf("请输入第一个字符串：");
    scanf("%s", str1);

    printf("请输入第二个字符串：");
    scanf("%s", str2);

    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) {
            printf("第一个字符串小于第二个字符串\n");
            return 0;
        }
        else if (str1[i] > str2[i]) {
            printf("第一个字符串大于第二个字符串\n");
            return 0;
        }
        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0') {
        printf("第一个字符串等于第二个字符串\n");
    }
    else if (str1[i] == '\0') {
        printf("第一个字符串小于第二个字符串\n");
    }
    else {
        printf("第一个字符串大于第二个字符串\n");
    }

    return 0;
}