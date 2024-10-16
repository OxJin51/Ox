//
// Created by �ҵ�������Ox on 2023/12/23 023.
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
            // ������Ч�ַ�����ѡ��
            printf("��⵽��Ч�ַ���%c\n", digit);
            return -1; // ��ʾ����
        }

        sum += digits * positionalRights; // չ��ÿһλ
        positionalRights *= 16; // ����Ȩֵ
    }

    return sum;
}

int main() {
    char a[200];
    printf("������һ��ʮ�������ַ�����");
    scanf("%s", a);
    printf("%d\n", hexToDecimal(a));

    return 0;
}
