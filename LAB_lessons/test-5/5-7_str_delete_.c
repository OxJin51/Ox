//
// Created by �ҵ�������Ox on 2024/1/9 009.
//
#include <stdio.h>

int main() {
    char str[100];

    // �����ַ���
    printf("������һ���ַ�����");
    scanf("%99[^\n]", str);  // �������������ַ���Ϊ99���������

    // ɾ�������ַ�
    int i = 0,j;
    while (str[i] != '\0') //���������ַ���
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            // ����������ַ���ɾ����
            for (j = i; str[j] != '\0'; j++)
            {
                str[j] = str[j + 1];
            }
        }
        else
          {i++;}
    }

    // ���ɾ�������ַ�����ַ���
    printf("ɾ�������ַ�����ַ�����%s\n", str);

    return 0;
}
