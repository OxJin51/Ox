//
// Created by 我的名字是Ox on 2024/3/28 028.
//
#include<iostream>
using namespace std;
typedef struct num
{
    int a;
    int b;
    int c;
}num;


int main()
{
    int n; cin>>n;

    while(n--)
    {
        num t;
        cin>>t.a>>t.b>>t.c;
        if(t.a<t.b&&t.b<t.c) cout<<"STAIR"<<endl;
        else if(t.a<t.b&&t.b>t.c) cout<<"PEAK"<<endl;
        else cout<<"NONE"<<endl;
    }

    return 0;
}