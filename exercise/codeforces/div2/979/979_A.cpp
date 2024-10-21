//
// Created by 我的名字是Ox on 2024/10/19 019.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
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
        int n; cin>>n;
        vector<int>a;
        for(int i=0;i<n;i++)
        {
            int x; cin>>x;
            a.push_back(x);
        }
        //处理a 1最大，后排序
        std::sort(a.begin(), a.end());

        swap(a.front(),a.back());

        std::sort(a.begin()+1, a.end());


        vector<int>b;
        vector<int>c;

        int y = a.front();
        for(int i=1;i<=n;i++)
        {
            c.push_back(y);
            int x;
            x = * min_element(a.begin(), a.begin()+i);
            b.push_back(x);
        }


        int sum_b = accumulate(b.begin(),b.end(),0);
        int sum_c = accumulate(c.begin(),c.end(),0);

        cout<<sum_c-sum_b<<endl;


    }
    return 0;
}