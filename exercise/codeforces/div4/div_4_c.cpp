//
// Created by 我的名字是Ox on 2024/2/19 019.
//
#include<iostream>
#include<cstdio>
using namespace std;
int digitSum(int num)
{
    int sum = 0;
    while (num>0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n,sum=0;
      cin>>n;
      for(int i=1;i<=n;i++)
      {
          if (i >= 10)
              sum += digitSum(i);
          else sum += i;
      }
        printf("%d\n",sum);
    }
    return 0;
}