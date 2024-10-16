//
// Created by 我的名字是Ox on 2023/12/30 030.
//
/*设圆半径r, 圆柱高h，求对应的圆球体积、圆柱体积。*/
#include <stdio.h>

int main()
{
    double r, h;

    // 输入圆半径和圆柱高
    printf("请输入圆半径和圆柱高（以空格分隔）： ");
    scanf("%lf %lf", &r, &h);

    // 使用给定的 π 近似值计算圆球体积
    double sphere_volume = (4.0 / 3.0) * 3.1415926 * r * r * r;

    // 使用给定的 π 近似值计算圆柱体积
    double cylinder_volume = 3.1415926 * r * r * h;

    // 输出结果
    printf("圆球体积: %f\n", sphere_volume);
    printf("圆柱体积: %f\n", cylinder_volume);

    return 0;
}

