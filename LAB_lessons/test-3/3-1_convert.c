//
// Created by �ҵ�������Ox on 2023/12/30 030.
//
/*��������һ��ʵ������������Ӧ�Ķ����˺�ʮ����������ת�����ƺ�С��λ����6λ����ʹ�����飩*/
#include <stdio.h>

void printBinary(double num)
{
    printf("�����Ʊ�ʾ��");
    long long intPart = (long long)num;
    double fracPart = num - intPart;

    // ����������ֵĶ����Ʊ�ʾ
    while (intPart > 0)
    {
        printf("%lld", intPart % 2);
        intPart /= 2;
    }

    printf(".");

    // ���С�����ֵĶ����Ʊ�ʾ
    int count = 0;
    while (fracPart > 0 && count < 6) {
        fracPart *= 2;
        printf("%d", (int)fracPart);
        fracPart -= (int)fracPart;
        count++;
    }

    printf("\n");
}

void printOctal(double num) {
    printf("�˽��Ʊ�ʾ��");
    long long intPart = (long long)num;
    double fracPart = num - intPart;

    // ����������ֵİ˽��Ʊ�ʾ
    while (intPart > 0) {
        printf("%lld", intPart % 8);
        intPart /= 8;
    }

    printf(".");

    // ���С�����ֵİ˽��Ʊ�ʾ
    int count = 0;
    while (fracPart > 0 && count < 6) {
        fracPart *= 8;
        printf("%d", (int)fracPart);
        fracPart -= (int)fracPart;
        count++;
    }

    printf("\n");
}

void printHexadecimal(double num) {
    printf("ʮ�����Ʊ�ʾ��");
    long long intPart = (long long)num;
    double fracPart = num - intPart;

    // ����������ֵ�ʮ�����Ʊ�ʾ
    while (intPart > 0) {
        int remainder = intPart % 16;
        if (remainder < 10) {
            printf("%c", '0' + remainder);
        } else {
            printf("%c", 'A' + remainder - 10);
        }
        intPart /= 16;
    }

    printf(".");

    // ���С�����ֵ�ʮ�����Ʊ�ʾ
    int count = 0;
    while (fracPart > 0 && count < 6) {
        fracPart *= 16;
        int digit = (int)fracPart;
        if (digit < 10) {
            printf("%d", digit);
        } else {
            printf("%c", 'A' + digit - 10);
        }
        fracPart -= digit;
        count++;
    }

    printf("\n");
}

int main() {
    double input;

    // ����ʵ��
    printf("������һ��ʵ���� ");
    scanf("%lf", &input);

    // ������ֽ��Ʊ�ʾ
    printBinary(input);
    printOctal(input);
    printHexadecimal(input);

    return 0;
}
