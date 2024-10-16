//
// Created by 我的名字是Ox on 2023/12/30 030.
//
/*解方程：根据x值求对应y值。
X>10     y=x2-1
0<x<=10   y=5x+2
X=0       y=0
X<0       y=3x-7
输出格式：x=2.26,y=3.78*/
#include <stdio.h>

int main() {
    double x, y;

    // 输入 x 值
    printf("请输入 x 值： ");
    scanf("%lf", &x);

    // 根据 x 值计算对应的 y 值
    if (x > 10) {
        y = x * x - 1;
    }
    else if (x > 0) {
        y = 5 * x + 2;
    }
    else if (x == 0) {
        y = 0;
    }
    else {
        y = 3 * x - 7;
    }

    // 输出结果
    printf("x=%.2lf, y=%.2lf\n", x, y);

    return 0;
}

