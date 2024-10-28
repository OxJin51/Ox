//
// Created by 我的名字是Ox on 2024/10/29 029.
//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    map<string,int>mp;
    vector<string>v;
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s; cin>>s;
        if(mp.count(s)) //有这个键值对，数量++
            mp[s]++;
        else //插入
        {
           v.push_back(s);
           mp[s] = 1;
        }
    }

    for(auto &i:v) cout<<i<<' '<<mp[i]<<endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}