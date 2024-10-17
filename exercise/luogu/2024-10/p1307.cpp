//
// Created by 我的名字是Ox on 2024/10/17 017.
//
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define endl "\n"
typedef long long ll;
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    string n,re_n;
    cin>>n;
    if(n == "0") {cout<<'0';return 0;}
    re_n.resize(n.size()); // 设置re_n的大小
    reverse_copy(n.begin(),n.end(),re_n.begin()); //逆置

    if(n[0]=='-') cout<<'-';

    string::iterator zero = re_n.begin();
    while(*zero=='0')
    {
        zero++;
    }

    for(auto it = zero; it != re_n.end(); ++it)
    {
        if(*it=='-') break;
        cout<<*it;
    }

    return 0;
}