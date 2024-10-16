//
// Created by 我的名字是Ox on 2023/12/30 030.
//
/*从键盘输入一个正数给变量x，判断x是否是一个回文数。（注意解题效率）
输出格式：
1325231是回文整数
1322不是回文整数*/
#include <stdio.h>

int main() {
    int x, originalNum, reversedNum = 0, remainder;

    // 从键盘输入一个正数给变量x
    printf("请输入一个正数： ");
    scanf("%d", &x);

    // 将原始数保存起来
    originalNum = x;

    // 反转数字
    while (x > 0)
    {
        remainder = x % 10;
        reversedNum = reversedNum * 10 + remainder;
        x /= 10;
    }

    // 判断是否为回文数
    if (originalNum == reversedNum)
    {
        printf("%d是回文整数\n", originalNum);
    }
    else
      {
        printf("%d不是回文整数\n", originalNum);
      }

    return 0;
}
