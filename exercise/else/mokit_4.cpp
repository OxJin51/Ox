//
// Created by 我的名字是Ox on 2024/3/29 029.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>a;
int main()
{
    int n,t;
    cin>>n>>t;
    //输入
    while(n--)
    {
        int x; cin>>x;
        a.push_back(x);
    }
    //排序
    sort(a.begin(),a.end());

    int i=0;

    while(t>0)
    {
        t-=a[i];
        if(t==0) {i++;break;}
        else if(t<0) { break;}
        else i++;
    }

    cout<<i;

    return 0;
}