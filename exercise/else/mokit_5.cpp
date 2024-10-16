//
// Created by 我的名字是Ox on 2024/3/29 029.
//
#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;
vector<int>a;
int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);
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
        i++;
    }

    if(t==0) cout << i << endl;
    else cout << i-1 << endl;

    return 0;
}