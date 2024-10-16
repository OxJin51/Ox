//
// Created by 我的名字是Ox on 2024/1/19 019.
//
#include <cstdio>
#include <iostream>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    for(int i=1,k=1;i<=n;i++) //控制行
    {
        for(int j=1;j<=n;j++) //K是填进去的数字
        {
            printf("%5d ",k++);
        }
        cout<<endl; //换行
    }


    return 0;
}