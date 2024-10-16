//
// Created by 我的名字是Ox on 2024/4/8 008.
//
//
// Created by 我的名字是Ox on 2024/2/19 019.
//
#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
typedef long long ll;
using namespace std;
const int N = 1e4+10;
int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        if(a*2>b) //若两瓶更划算
        {
            cout<<n/2*b+n%2*a<<endl;
        }

        else
        {
            cout<<n*a<<endl;
        }

    }
    return 0;
}