//
// Created by 我的名字是Ox on 2024/10/9 009.
//
#include <stdio.h>

int main() {
    double baseSalary = 4000.0; // 底薪
    double sales; // 销售额
    double commissionRate; // 提成比例
    double commission; // 提成
    double totalSalary; // 总工资

    // 输入员工的销售额
    scanf("%lf", &sales);

    // 根据销售额的整数部分确定提成比例
    int salesCategory = (int)(sales / 1000); // 将销售额除以1000并取整

    switch (salesCategory) {
        case 0: // sales < 3000
            commissionRate = 0.0;
            break;
        case 3: // 3000 <= sales < 7000
            commissionRate = 0.10;
            break;
        case 7: // 7000 <= sales < 10000
            commissionRate = 0.15;
            break;
        case 10: // sales >= 10000
            commissionRate = 0.20;
            break;
        default:
            commissionRate = 0.20; // 处理大于10000的情况
            break;
    }

    // 计算提成
    commission = sales * commissionRate;

    // 计算总工资
    totalSalary = baseSalary + commission;

    // 输出结果
    printf("%.2f\n", totalSalary);

    return 0;
}
