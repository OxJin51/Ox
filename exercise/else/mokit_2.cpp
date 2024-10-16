//
// Created by 我的名字是Ox on 2024/3/28 028.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>a;
int sum=0,max,min;
double ave=0;
int main()
{
    int x;
    while(1) //数组输入
    {
        cin>>x;
        if(x==0)
           {
             a.push_back(0);
             break;
           }
        a.push_back(x);
        sum+=x;
    }

    sort(a.begin(),a.end()-1);

    int t=a.size()-1;

    printf("%d ",t); // 1. 输出个数

     //2. 输出中值
     printf("%d ",a[t>>1]);

    ave=sum*1.0/t;

    printf("%.2lf ",ave); // 3. 平均值

    printf("%d ",a[t-1]);

    printf("%d ",a[0]);


    printf("%d",sum);


    return 0;
}