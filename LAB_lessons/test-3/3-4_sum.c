//
// Created by 我的名字是Ox on 2023/12/30 030.
//
/*已知y= 2/(1*3)+3/(2*4)+.........31/(30*32),编程计算并输出y*/
#include <stdio.h>

int main() {
    double y = 0.0;
    int i;
    for (i = 1; i <= 31; i++)
    {
        y += (double)i / ((i - 1) * (i + 1));
    }

    printf("y = %lf\n", y);

    return 0;
}
