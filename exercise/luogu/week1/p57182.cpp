//
// Created by 我的名字是Ox on 2024/9/7 007.
//
#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
typedef long long ll;
using namespace std;
const int N=110;
int a[N];
int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n; cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        int min=a[0];
        for(int i=0;i<n;i++)
        {
            if(min>a[i]) min=a[i];
        }

        cout<<min;
    }
    return 0;
}