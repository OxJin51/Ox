//
// Created by 我的名字是Ox on 2024/7/17 017.
//
#include<iostream>
#include<vector>
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
       int x; cin>>x;
        //全有
        if( x%2==0 && x>4&&x<=12 ) cout<<1;
        else cout<<0;
        //至少有一个
        if( x%2==0 || x>4&&x<=12 ) cout<<1;
        else cout<<0;
        //只有一个
        if( x%2==0 && x<=4&&x>12 ) cout<<1;
        else cout<<0
        else if (x%!=0 && x>4&&x<=12) cout<<1
        else cout<<0;
    }
    return 0;
}