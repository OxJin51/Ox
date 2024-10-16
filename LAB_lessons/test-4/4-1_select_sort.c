//
// Created by 我的名字是Ox on 2023/12/27 027.
//
/*用选择排序法，键盘输入 10 个整数，对 10 个整数，从小到大进行排序。*/
#include <stdio.h>

int main()
{
    int numbers[10];
    int i, j, temp;

    // 输入10个整数
    printf("请输入10个整数：\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &numbers[i]);
    }

    // 选择排序
    for (i = 0; i < 9; i++) //i=0,i<n-1 外循环遍历未排序的区域（a[i]为未排序区域）
    {
        for (j = i + 1; j < 10; j++)
        {

            if (numbers[j] < numbers[i]) //a[i]是小的数
            {
                // 交换位置
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    // 输出排序结果
    printf("从小到大排序结果为：\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}