//
// Created by �ҵ�������Ox on 2023/12/30 030.
//
/*������ʽ��s��ֵ��Ҫ��ʹ��ѭ��ʵ�֣���*/
#include <stdio.h>

int main() {
    int n = 20;
    double s = 0.0;
    double term = 1.0;

    for (int i = 0; i <= n; i++)
    {
        s += term;
        term /= 3.0;
    }

    printf("s��ֵΪ��%f\n", s);

    return 0;
}
