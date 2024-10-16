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
    double a[200];
    double sum = 0;

    // ��ʼ��ǰ����
    a[0] = 1;
    a[1] = 2;

    // ��������ǰ200���ֵ
    for (n = 2; n < maxTerms; ++n) {
        a[n] = a[n - 2] + 2 * a[n - 1] - ((int)(2 * a[n - 1]) / n) * n;
    }

    // ��������ǰ200���ƽ��ֵ
    for (n = 0; n < maxTerms; ++n) {
        sum += a[n];
    }

    // ���ƽ��ֵ������2λС����
    printf("����ǰ%d���ƽ��ֵΪ��%.2lf\n", maxTerms, sum / maxTerms);

    return 0;
}
