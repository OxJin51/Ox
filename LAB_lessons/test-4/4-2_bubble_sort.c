//
// Created by 我的名字是Ox on 2023/12/27 027.
//
/*用冒泡排序法，键盘输入 10 个整数，对 10 个整数，从小到大进行排序。*/
#include <stdio.h>

int main()
{
    int arr[10];
    int i, j, temp;
    //temp 做交换变量

    printf("请输入10个整数：\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    // 冒泡排序
    for (i = 0; i < 9; i++) //i<n-1
    {
        for (j = 0; j < 9 - i; j++) //j<n-1-i
        {
            if (arr[j] > arr[j + 1])
            {
                // 交换 arr[j] 和 arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("从小到大排序后的结果为：\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
