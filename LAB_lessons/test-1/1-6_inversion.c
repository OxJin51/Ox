//
// Created by �ҵ�������Ox on 2023/12/30 030.
//
/*��������һ��С�ڵ���99999���������жϸ������Ǹ���λ�������ÿ����λ�ϵ����룬Ȼ��Ѹ������ô����ԭ���С�
����
6723��һ����λ��
ǧλ��������6
��λ��������7
ʮλ��������2
��λ��������3
���ý����3276
*/
#include <stdio.h>

int main() {
    int num, originalNum, reversedNum = 0, digitCount = 0;

    // ��������
    printf("������һ��С�ڵ���99999�������� ");
    scanf("%d", &num);

    originalNum = num;

    // �ж�����λ��
    while (num != 0)
    {
        num /= 10;
        ++digitCount;
    }

    num = originalNum; // ���³�ʼ��numΪԭʼֵ

    // ���������λ��
    printf("%d��һ��%dλ��\n", originalNum, digitCount);

    // ���ÿ����λ�ϵ�����
    while (num != 0)
    {
        if (digitCount == 5) {
            printf("��λ��������%d\n", num % 10);
        } else if (digitCount == 4) {
            printf("ǧλ��������%d\n", num % 10);
        } else if (digitCount == 3) {
            printf("��λ��������%d\n", num % 10);
        } else if (digitCount == 2) {
            printf("ʮλ��������%d\n", num % 10);
        } else {
            printf("��λ��������%d\n", num % 10);
        }
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
        --digitCount;
    }

    // ������ý��
    printf("���ý����%d\n", reversedNum);

    return 0;
}

