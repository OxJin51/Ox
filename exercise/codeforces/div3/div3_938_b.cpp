//
// Created by 我的名字是Ox on 2024/4/8 008.
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
        //输入
        int n,c,d;
        int cnt=0;
        cin>>n>>c>>d;
        vector<int>a;
        for(int i=0;i<n*n;i++) cin>>a[i];
        //排序
        sort(a.begin(),a.end());
        //减去a1，1
        ll t=a[0];
        for(int i=0;i<n;i++)
        {
            a[i]=a[i]-t;
        }
        bool match= true;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]!=a[i][0]+i*c+j*d) match= false;
            }
        }

        if(match) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


        cout<<"YES"<<endl;

    }
    return 0;
}