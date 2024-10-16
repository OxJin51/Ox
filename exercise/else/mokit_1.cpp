//
// Created by 我的名字是Ox on 2024/3/28 028.
//
#include<iostream>
using namespace std;
typedef long long ll;
int res;
ll add(int num)
{
    ll sum=0;
    while(num!=0)
    {
        sum+=num%10;
        num=num/10;
    }
    return sum;
}
void check(int n)
{
    if(n<=9){res=n; return ;}

    ll t=add(n);

    if(t<=9) {res=t; return ;}
    else check(add(t));
}

int main()
{
    ll n; cin>>n;

    check(n);

    printf("%d",res);

    return 0;
}