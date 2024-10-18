//
// Created by 我的名字是Ox on 2024/10/18 018.
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
    string title;
    getline(cin,title);
    int length = title.size();
    //cout<<length;
    //cout<<endl;
    for(string::iterator it=title.begin();it!=title.end();it++)
    {
        if(*it == '\n'|| *it == ' ') {length--;}
    }
    cout<<length;

    return 0;
}