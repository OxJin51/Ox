//
// Created by 我的名字是Ox on 2024/5/30 030.
//
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define endl "\n"
typedef long long ll;
using namespace std;
int n;
string str;
void solve(string a)
{
    for(int i=0;i<n-1;i++)
    {
        //字符
        if('a'<=a[i]<='z')
        {
            if('0'<=a[i+1]<='9')
            {
                cout<<"NO"<<endl;
                return;
            }

            else if(a[i]>a[i+1])
            {
                cout<<"NO"<<endl;
                return;
            }

            else if(i==n-2)
            {
                cout<<"YES"<<endl;
                return;
            }
            else continue;
        }
        //数字
        else
        {
            //下一位也是数字
            if('0'<=a[i+1]<='9')
            {
                if(a[i]>a[i+1])
                {cout<<"NO"<<endl;
                    return;}
                else
                {
                    if(i==n-2)
                    {
                        cout<<"YES"<<endl;
                        return;
                    }
                    else continue;
                }
            }
            else //下一位是字符
            {
                if(i==n-2)
                {
                    cout<<"YES"<<endl;
                    return;
                }
                else continue;
            }
        }
    }
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        getline(cin,str);
        solve(str);
    }
    return 0;
}