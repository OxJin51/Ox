//
// Created by 我的名字是Ox on 2024/1/19 019.
//
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int cx=n/2 , cy=n/2;
    for(int i=0;i<n;i++) //控制n阶
    {
        for(int j=0;j<n;j++)
        {   if(abs(i-cx)+abs(j-cy)<=n/2)
                cout << "*";
            else cout <<" ";
        }
        cout << endl;
    }
    return 0;
}