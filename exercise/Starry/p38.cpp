//
// Created by 我的名字是Ox on 2024/10/28 028.
//
#include<iostream>
#include<stack>
using namespace std;
const int N = 1e5+10;
int a[N],pos;
int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    pos = 1; //代入站车的编号
    stack<int>stk;

    for(int i=1;i<=n;i++) //i为出站列车编号
    {
        while(pos<=n && (stk.empty()||stk.top()!=i)) stk.push(a[pos++]);

        if(stk.top()==i) stk.pop();
        else {
            cout<<"No";
            return 0;
        }

    }

    cout<<"Yes";
    return 0;
}