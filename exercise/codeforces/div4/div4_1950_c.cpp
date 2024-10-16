//
// Created by 我的名字是Ox on 2024/2/19 019.
//
#include<iostream>
#include<string>
typedef long long ll;
using namespace std;
void solve(string s)
{
    //前半部分
    int hour = (s[0] - '0') * 10 + (s[1] - '0'); // 将字符转换为数字

    if (hour > 12)
    {
        cout << (hour - 12 < 10 ? "0" : "") << hour - 12 << ':';
    } else
    {
        if(hour==0) cout<<"12"<<":";
        else
        cout << (hour < 10 ? "0" : "") << hour << ':';
    }


    //后半部分
    cout<<s.substr(3,4)<<' ';
    if(hour>=12) cout<<"PM"<<endl;
    else cout<<"AM"<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        solve(s);
    }
    return 0;
}