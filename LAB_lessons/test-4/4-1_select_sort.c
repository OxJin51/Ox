//
// Created by �ҵ�������Ox on 2023/12/27 027.
//
/*��ѡ�����򷨣��������� 10 ���������� 10 ����������С�����������*/
#include <stdio.h>

int main()
{
    int numbers[10];
    int i, j, temp;

    // ����10������
    printf("������10��������\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &numbers[i]);
    }

    // ѡ������
    for (i = 0; i < 9; i++) //i=0,i<n-1 ��ѭ������δ���������a[i]Ϊδ��������
    {
        for (j = i + 1; j < 10; j++)
        {

            if (numbers[j] < numbers[i]) //a[i]��С����
            {
                // ����λ��
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    // ���������
    printf("��С����������Ϊ��\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}