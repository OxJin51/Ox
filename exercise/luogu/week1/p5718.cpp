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
    vector<int>arr;
    //cin>>t;
    while(t--)
    {
        int n,min;
        cin>>n;
        while(n--)
        {
            int num; cin>>num;
            arr.push_back(num);
        }
        min = arr[0];
        for(vector<int>::iterator it;it!=arr.end();it++)
        {
            if(min>*it) min=*it;
        }

        cout<<min;
    }
    return 0;
}