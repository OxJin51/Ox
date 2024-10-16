//
// Created by 我的名字是Ox on 2024/9/7 007.
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
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int num=1;
        for(int i=0;i<n;i++) //处理行
        {
            for(int j=n-i;j>0;j--) //处理具体行
            {
                if(num>=10) cout<<num++;
                else cout<<0<<num++;
            }

            cout<<endl;

        }
    }
    return 0;
}