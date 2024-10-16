//
// Created by 我的名字是Ox on 2023/12/30 030.
//
/*从键盘输入1~7之间的整数，输出对应的英文星期名缩写（Mon,Tue,Wed,Thu,Fri,Sat,Sun）,要求用switch语句实现。*/
#include <stdio.h>

int main() {
    int day;

    // 输入1~7之间的整数
    printf("请输入1~7之间的整数： ");
    scanf("%d", &day);

    // 使用switch语句判断输入的整数对应的星期名缩写
    switch (day)
    {
        case 1:printf("Mon\n");break;
        case 2:printf("Tue\n");break;
        case 3:printf("Wed\n");break;
        case 4:printf("Thu\n");break;
        case 5:printf("Fri\n");break;
        case 6:printf("Sat\n");break;
        case 7:printf("Sun\n");break;
        default:printf("输入不在1~7之间。\n");
    }

    return 0;
}

