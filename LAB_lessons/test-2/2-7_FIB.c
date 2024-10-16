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
    double sum = 0;
    double term1 = 1.0;
    double term2 = 2.0;

    // 计算数列前200项的值
    for (n = 2; n < maxTerms; ++n) {
        double currentTerm = term1 + 2 * term2 - ((int)(2 * term2) / n) * n;
        sum += currentTerm;

        // 更新term1和term2
        term1 = term2;
        term2 = currentTerm;
    }

    // 输出平均值（保留2位小数）
    printf("数列前%d项的平均值为：%.2f\n", maxTerms, sum / maxTerms);

    return 0;
}

