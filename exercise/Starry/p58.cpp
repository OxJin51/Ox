//
// Created by 我的名字是Ox on 2024/10/28 028.
//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{

}
priority_queue<ll>pq;
int main()
{
    ll sun=0;
    int q;cin>>q;
    while(q--)
    {
        int op; cin>>op;
        if(op==1)
        {
            ll x; cin>>x;
            pq.push(x);
            sun+=x;
        }
        else if(pq.size())
        {
            sun-=pq.top();
            pq.pop();
        }
    }

    cout<<sun;

    return 0;
}