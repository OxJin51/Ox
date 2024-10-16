//
// Created by 我的名字是Ox on 2024/2/19 019.
//
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;

    cin>>t;
    while(t--)
    {
        int cnt1=0,cnt2=0;
        string s;
        cin>>s;
     for(char x:s)
     {
         if(x=='A') cnt1++;
         else if(x=='B') cnt2++;
     }
     if(cnt1>cnt2) cout<<'A'<<endl;
     else cout<<'B'<<endl;
    }
    return 0;
}