//
// Created by 我的名字是Ox on 2023/12/30 030.
//
/*从键盘输入一个正整数（1~32767），根据输入的正整数，判断它是几位数，并输出。分别把不同数位上的数码输出。逆序输出。（使用循环完成）
例如：输入32741
输出格式为：
32741 是一个5位数。  //第一行的内容为32741是5位数。
第5位上的数码是3。//表示第1位上是1，第2位上的数是4，第3位位上的数是7，依次类推。
第4位上的数码是2。
第3位上的数码是7。
第2位上的数码是4。
第1位上的数码是1。
32741 的逆序数是14723   //通过原数，计算得到它的逆序数并输出
若输入0或者负数，则输出：输入错误！*/
#include <stdio.h>

int main() {
    int num, originalNum, digitCount = 0,i;

    // 输入正整数
    printf("请输入一个正整数（1~32767）： ");
    scanf("%d", &num);

    originalNum = num;

    // 判断位数
    if (num <= 0 || num > 32767)
    {
        printf("输入错误！\n");
        return 0;
    }

    while (num > 0)
    {
        num /= 10;
        ++digitCount;
    }

    // 重新初始化num为原始值
    num = originalNum;

    // 输出位数信息
    printf("%d 是一个%d位数。\n", originalNum, digitCount);

    // 输出每个数位上的数码和逆序数
    printf("各位数字及逆序数：\n");
    for (i = digitCount; i > 0; --i)
    {
        int digit = num % 10;
        printf("第%d位上的数码是%d。\n", i, digit);
        num /= 10;
    }

    // 计算并输出逆序数
    printf("%d 的逆序数是", originalNum);
    num = originalNum;
    while (num > 0)
    {
        printf("%d", num % 10);
        num /= 10;
    }

    printf("\n");

    return 0;
}

