//
// Created by �ҵ�������Ox on 2023/12/19 019.
//
/*����һ����Ϊprime���Ӻ������������ж�һ���������Ƿ���������ʹ��main�������øú���ʵ���������жϡ�*/
#include<stdio.h>

// �ж�һ�����Ƿ�Ϊ�����ĺ���
#include <stdio.h>
int Prime(int num) {
    if (num <= 1)
    {
        return 0; // 0��1��������
    }
    int i;
    for (i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0; // ���num�ܱ�2��sqrt(num)֮����κ�����������ô����������
        }
    }

    return 1; // ���û���ҵ���������������
}
int main()
{
    int Prime(int num);
    int x;
    scanf("%d",&x);
    if(Prime(x))
        printf("%d������",x);
    else
        printf("%d��������",x);
    return 0;
}

