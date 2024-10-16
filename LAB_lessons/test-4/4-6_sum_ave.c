//
// Created by 我的名字是Ox on 2023/12/27 027.
//
/*张晓负责两个居民小区的快递服务，二月份两个小区每天完成的快递书分别保存在数组 a 和 b 中，其中数组元素-1 表示该天是周六和周日休息。
计算并输出二月份完成的快递总数和工作日完成快递数的平均值。（要求使用循环实现，结果保留 2 位小数）。*/
#include<stdio.h>
int main()
{
    float sum1, sum2, sum;
    int i, j;
    float ave;

    /*小区 1*/
    int a[29] = { -1,-1,125,134,165,173,-1,-1,120,119,165,145,186,-1,-1,197,215,179,154,185,-1,-1,121,128,147,155,127,-1 };
    /*小区 2*/
    int b[29] = { -1,-1,175,185,155,130,166,-1,-1,166,175,135,185,196,-1,-1,186,185,195,163,174,-1,-1,121,243,225,288,259,-1 };
    /*由此开始设计程序*/
    sum1 = 0;
    sum2 = 0;
    for (i = 1; i <= 28; i++)
    {
        if (a[i] != -1)
            sum1 += a[i];

    }
    for (j = 1; j <= 28; j++)
    {
        if (b[j] != -1)
            sum2 += b[j];

    }
    sum = sum1 + sum2;
    ave = sum / 28.0;
    printf("二月份完成的快递总数是%.2f\n",sum);
    printf("二月份完成的快递数的平均值是%.2f\n", ave);
    return 0;
}
//ai

//#include <stdio.h>
//
// int main() {
//	 int a[29] = { -1, -1, 125, 134, 165, 173, -1, -1, 120, 119, 165, 145, 186, -1, -1, 197, 215, 179, 154, 185, -1, -1, 121, 128, 147, 155, 127, -1 };
//	 int b[29] = { -1, -1, 175, 185, 155, 130, 166, -1, -1, 166, 175, 135, 185, 196, -1, -1, 186, 185, 195, 163, 174, -1, -1, 121, 243, 225, 288, 259, -1 };
//	 int totalDeliveries = 0;
//	 int workingDays = 0;
//
//	 for (int i = 0; i < 29; i++) {
//		 if (a[i] != -1 && b[i] != -1) {
//			 totalDeliveries += a[i] + b[i];  // 计算快递总数
//			 workingDays++;  // 统计工作日数量
//		 }
//	 }
//
//	 float averageDeliveries = (float)totalDeliveries / workingDays;  // 计算平均值
//
//	 printf("二月份完成的快递总数：%d\n", totalDeliveries);
//	 printf("工作日完成快递数的平均值：%.2f\n", averageDeliveries);
//
//	 return 0;
// }