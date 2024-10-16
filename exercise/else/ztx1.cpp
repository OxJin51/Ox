#include<stdio.h>
int main()
{
    int a,b;
    int div,rem; //div是商 rem余数 浮点数 float精度  double
    scanf("%d%d",&a,&b);
    div = a/b;
    rem = a%b;
    printf("%d %d",div,rem);
    return 0;
}