//
// Created by 我的名字是Ox on 2023/12/30 030.
//
/*已知数列D(n)
当n=1时，D(1)=1
当n=2时，D(2)=2
当n>2时，D(n)= D(n-2)+ 2D(n-1)%n
求该数列前200项的值，并存储在数组a中，计算并输出该数列前200项的平均值（要求使用循环实现，结果保留2位小数）。*/

#include <stdio.h>

int main() {
    int n;
    int maxTerms = 200;
    double a[200];
    double sum = 0;

    // 初始化前两项
    a[0] = 1;
    a[1] = 2;

    // 计算数列前200项的值
    for (n = 2; n < maxTerms; ++n) {
        a[n] = a[n - 2] + 2 * a[n - 1] - ((int)(2 * a[n - 1]) / n) * n;
    }

    // 计算数列前200项的平均值
    for (n = 0; n < maxTerms; ++n) {
        sum += a[n];
    }

    // 输出平均值（保留2位小数）
    printf("数列前%d项的平均值为：%.2lf\n", maxTerms, sum / maxTerms);

    return 0;
}
