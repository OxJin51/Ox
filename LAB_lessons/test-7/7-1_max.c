//
// Created by �ҵ�������Ox on 2023/12/19 019.
//
/*����һ���Ӻ���max������������������е��������*/
#include <stdio.h>
//����������е������
int max(int a,int b) //�Զ��庯��
{ int max;
    if(a>b)
        max=a;
    else
        max=b;
    return max;
}
   //ϰ��
int main() //������
{
    //��������
    int max(int a,int b);

printf("������������\n");
int x,y,z;
scanf("%d%d",&x,&y);
z=max(x,y);
printf("max=%d\n",z);
    return 0;
}