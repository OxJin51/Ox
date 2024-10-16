//
// Created by �ҵ�������Ox on 2023/12/30 030.
//
/*��֪����D(n)
��n=1ʱ��D(1)=1
��n=2ʱ��D(2)=2
��n>2ʱ��D(n)= D(n-2)+ 2D(n-1)%n
�������ǰ200���ֵ�����洢������a�У����㲢���������ǰ200���ƽ��ֵ��Ҫ��ʹ��ѭ��ʵ�֣��������2λС������*/

#include <stdio.h>

int main() {
    int n;
    int maxTerms = 200;
    double sum = 0;
    double term1 = 1.0;
    double term2 = 2.0;

    // ��������ǰ200���ֵ
    for (n = 2; n < maxTerms; ++n) {
        double currentTerm = term1 + 2 * term2 - ((int)(2 * term2) / n) * n;
        sum += currentTerm;

        // ����term1��term2
        term1 = term2;
        term2 = currentTerm;
    }

    // ���ƽ��ֵ������2λС����
    printf("����ǰ%d���ƽ��ֵΪ��%.2f\n", maxTerms, sum / maxTerms);

    return 0;
}

