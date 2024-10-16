//
// Created by 我的名字是Ox on 2023/12/30 030.
//
/*键盘输入一个小于等于99999的整数，判断该整数是个几位数，输出每个数位上的数码，然后把该数逆置存放在原数中。
例：
6723是一个四位数
千位的数码是6
百位的数码是7
十位的数码是2
个位的数码是3
逆置结果是3276
*/
#include <stdio.h>

int main() {
    int num, originalNum, reversedNum = 0, digitCount = 0;

    // 输入整数
    printf("请输入一个小于等于99999的整数： ");
    scanf("%d", &num);

    originalNum = num;

    // 判断整数位数
    while (num != 0)
    {
        num /= 10;
        ++digitCount;
    }

    num = originalNum; // 重新初始化num为原始值

    // 输出整数的位数
    printf("%d是一个%d位数\n", originalNum, digitCount);

    // 输出每个数位上的数码
    while (num != 0)
    {
        if (digitCount == 5) {
            printf("万位的数码是%d\n", num % 10);
        } else if (digitCount == 4) {
            printf("千位的数码是%d\n", num % 10);
        } else if (digitCount == 3) {
            printf("百位的数码是%d\n", num % 10);
        } else if (digitCount == 2) {
            printf("十位的数码是%d\n", num % 10);
        } else {
            printf("个位的数码是%d\n", num % 10);
        }
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
        --digitCount;
    }

    // 输出逆置结果
    printf("逆置结果是%d\n", reversedNum);

    return 0;
}

