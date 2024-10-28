//
// Created by 我的名字是Ox on 2024/10/22 022.
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
    int toatl=0; //总钱数
    int save;
    //cin>>t;
    for (int month = 0; month < 12; month++)
    {
        int budget;
        cin>>budget;
        toatl += 300; //每个月都给300

        if(toatl<budget)
        {
            cout<<'-'<<month+1;
            return 0;
        }
        toatl -= budget;
        while(toatl>100)
        {
            toatl-=100;
            save+=100;
        }

        toatl -= budget;
    }
    int final_amount = toatl + save * 1.2;
    cout << final_amount; // 输出年末的钱数
    return 0;
}