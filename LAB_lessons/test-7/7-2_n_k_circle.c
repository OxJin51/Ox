//
// Created by �ҵ�������Ox on 2023/12/19 019.
//
/*��дһ������int fun(int n,int k)ʵ��n^k��n��k�η�����n��k�Ӽ������룬ʹ�õݹ�ʵ�֡����������е����Ӻ�����*/
#include<stdio.h>
int fun(int n,int k)   /*�����ײ�*/
{
    int s=1;
    for (int i = 1; i<=k; i++)
    {
        s=s*n;
    }
    return s;
}
void  main()
{
    int x,y,z;
    scanf("%d%d",&x,&y);
    z=fun(x,y);   /*���ú���*/
    printf("%d^%d=%d\n",x,y,z);
}
