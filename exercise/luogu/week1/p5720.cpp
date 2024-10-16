//
// Created by 我的名字是Ox on 2024/9/7 007.
//
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define endl "\n"
typedef long long ll;
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        int a,cnt=1; cin>>a;
        while(a!=1)
        {
            a=floor(a/2);
            cnt++;
        }

        cout<<cnt;
    }
    return 0;
}