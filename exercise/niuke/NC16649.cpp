//
// Created by 我的名字是Ox on 2024/9/29 029.
//
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define endl "\n"
typedef long long ll;
using namespace std;
const int N = 1e4+10;
bool tree[N];

int cnt;
int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        memset(tree,1,N *sizeof(bool));
        int L,M; cin>>L>>M;
        cnt=L;
        while(M--)
        {
            int l,r; cin>>l>>r;
            for(int i=l;i<=r;i++)
            {
                if(tree[i])
                {
                    cnt--;
                    tree[i]=0;
                }
            }

        }

        cout<<cnt+1;
    }
    return 0;
}