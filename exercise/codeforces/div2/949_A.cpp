//
// Created by 我的名字是Ox on 2024/5/31 031.
//
#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
typedef long long ll;
using namespace std;
int l,r;
int cnt;
ll pow2(int n)
{
    int power = 1;
    while (power <= n) {
        power <<= 1;
    }
    return power >> 1;
}

int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        ll maxnum= pow2(r);
        if(maxnum<1)
        {
            maxnum= pow2(r/2);
        }
        while(maxnum!=1)
        {
            maxnum/=2;
            cnt++;
        }

        cout<<cnt<<endl;
    }
    return 0;
}