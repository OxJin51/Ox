//
// Created by 我的名字是Ox on 2024/3/25 025.
//
#include<iostream>
using namespace std;
const int N = 110;
int n,a[N],b[N]; //a存分子，b存分母
int gcd(int a,int b)
{
    if(a<b) swap(a,b); //求最大公约数前提：a>b
    while(b!=0)
    {
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}

int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)  scanf("%d/%d",&a[i],&b[i]); //输入分子和分母
        int lcm1=1;
        for(int i=1;i<=n;i++)
        {
            lcm1=lcm(lcm1,b[i]);
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=a[i]*(lcm1/b[i]);
        }
        if(sum%lcm1==0)
            printf("%d",sum/lcm1);
        else
        printf("%d %d/%d",sum/lcm1,sum%lcm1,lcm1);

    return 0;
}