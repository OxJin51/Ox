//
// Created by 我的名字是Ox on 2024/5/31 031.
//
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define endl "\n"
typedef long long ll;
using namespace std;
bool prime(int n)
{
    bool is_prime = true;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) is_prime= false;
    }
    if(is_prime) return true;
    else return false;
}
int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        string s;
    }
    return 0;
}