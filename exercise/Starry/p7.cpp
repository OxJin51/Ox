//
// Created by 我的名字是Ox on 2024/9/29 029.
//
#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
typedef long long ll;
using namespace std;
const int N = 1e5+10;
ll a[N],prefix[N];
int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n,q; cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) prefix[i]=prefix[i-1]+a[i];

        while(q--)
        {
            int l,r; cin>>l>>r;
            cout<<prefix[r]-prefix[l-1]<<endl;
        }
    }
    return 0;
}