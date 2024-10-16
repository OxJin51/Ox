//
// Created by 我的名字是Ox on 2024/2/18 018.
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
        int count=0;
        int length;
        string s;
        cin>>length>>s;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='@') //币
            { count++;continue;}
            if(s[i]=='.') //空
            { continue;}
            if(s[i]=='*') //荆棘
            {
                if(++i<s.size())
                {
                    if(s[i]=='.') ;
                    if(s[i]=='*')
                    {cout<<count<<endl;
                        break;}
                    if(s[i]=='@') count++;

                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
