//
// Created by �ҵ�������Ox on 2023/12/30 030.
//
/*��ӡ1000��Ϊ��������������һ������������������֮�͡�
���磺6=1+2+3����6��������
�����ʽ��6��������������Ϊ1  2  3
��һ��������Ϣռ��һ�У�*/
#include <stdio.h>

int main() {
    int sum = 0,num=1,i;
    for (num = 1; num <= 1000; num++)
    {


        for (i = 1; i <= num-1; i++)
        {
            if (num % i == 0)
            {
                sum += i;
            }
        }

        if (sum == num)
        {
            printf("%d��������������Ϊ1", num);

            for (i = 1; i <= num-1; i++) {
                if (num % i == 0)
                {
                    printf("  %d", i);
                }
            }

            printf("\n");
        }
    }

    return 0;
}
