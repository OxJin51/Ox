//
// Created by 我的名字是Ox on 2024/5/26 026.
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
const int N = 15;
int nums[N];
bool st[N];
int n,sum;
void dfs(int u)
{
    if(u>10&&sum==n)
    {
        for(int i=1;i<=10;i++)
        {
            cout<<nums[i]<<' ';
        }
        puts("");
    }

    //搜索过程
    if(sum>n) return;
    for(int i=1;i<=3;i++)
    {
        if (!st[u])
        {

            nums[u] = i;
            sum += i;
            st[u] = true;
            dfs(u + 1);
            st[u] = false;
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    cin>>n;
    dfs(1);
    return 0;
}