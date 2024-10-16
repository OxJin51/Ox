//
// Created by 我的名字是Ox on 2023/12/23 023.
//
#include <stdio.h>
#include <string.h>

int hexToDecimal(char s[200]) {
    int sum = 0, positionalRights = 1, digits;

    for (int i = strlen(s) - 1; i >= 0; i--) {
        char digit = s[i];

        if (digit >= '0' && digit <= '9') {
            digits = digit - '0';
        } else if (digit >= 'a' && digit <= 'f') {
            digits = 10 + (digit - 'a');
        } else if (digit >= 'A' && digit <= 'F') {
            digits = 10 + (digit - 'A');
        } else {
            // 处理无效字符（可选）
            printf("检测到无效字符：%c\n", digit);
            return -1; // 表示错误
        }

        sum += digits * positionalRights; // 展开每一位
        positionalRights *= 16; // 更新权值
    }

    return sum;
}

int main() {
    char a[200];
    printf("请输入一个十六进制字符串：");
    scanf("%s", a);
    printf("%d\n", hexToDecimal(a));

    return 0;
}
