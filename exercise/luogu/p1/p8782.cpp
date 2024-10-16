//
// Created by 我的名字是Ox on 2024/2/19 019.
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
    int t;
    cin>>t;
    while(t--)
    {
        vector<int>a;
        int n; cin>>n;
        for(int i=0;i<n;i++)
        {
            int x; cin>>x;
            a.push_back(x);
        }
        //solve
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i<j&&i%2==0&&j%2==0)
                {
                    if(a[i]%2==0&&a[j]%2==0){cnt++;}
                }
            }
        }

        cout<<cnt<<endl;
    }
    return 0;
}