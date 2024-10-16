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
    //std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n,k; cin>>n>>k;
        ll  sum_a=0,sum_b=0;
        int count_a=0,count_b=0;
        //double ave_a,ave_b;
        for(int i=1;i<=n;i++)
        {
            if(i%k==0) {sum_a+=i;count_a++;}
            else {sum_b+=i;count_b++;}
        }

        printf("%.1lf %.1lf",sum_a*1.0/count_a,sum_b*1.0/count_b);
    }
    return 0;
}